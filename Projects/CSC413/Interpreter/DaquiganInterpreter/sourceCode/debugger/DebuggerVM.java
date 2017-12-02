/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interpreter.debugger;

import interpreter.*;
import interpreter.ByteCode.*;
import interpreter.debugger.ui.*;
import java.util.*;
import java.io.*;

/**
 *
 * @author Darrel Daquigan
 */
public class DebuggerVM extends VirtualMachine{
    UI ui;
    Vector<Entry> entries;
    Stack<FunctionEnvironmentRecord> envStack;
    String xFile;
    Vector<Integer> validBkpts;
    boolean firstRun;
    int preStepEnvSize;
    int preStepLine;
    boolean steppingOut;
    boolean steppingOver;
    boolean steppingInto;
    
    public DebuggerVM(Program p,String xCodeFile){
        super(p);
        xFile = xCodeFile;
        validBkpts = new Vector<Integer>();
        
    }
    
    public void executeProgram(){
        ui = new UI(this);
        entries = new Vector<Entry>();
        envStack = new Stack<FunctionEnvironmentRecord>();
        firstRun = true;
        preStepEnvSize = -2;
        preStepLine = -2;
        steppingOut = false;
        steppingOver = false;
        steppingInto = false;
        
        try{
            initEntries(xFile);
        }catch(IOException e){}
        
        initValidBkpts();
        
        
        while(super.isRunning()){
            ByteCode code = super.program().getCode(super.pc());
            ByteCode nextCode;
            if (super.pc() + 1 < super.program().numCodes())
                nextCode = super.program().getCode(super.pc() + 1);
            else 
                nextCode = null;
            code.execute(this);
            
            if(!(code instanceof DumpCode) && super.dumpFlag() == true){
                code.print();
                super.runStack().dump();
            }
            
            
            if(shouldPrompt(code, nextCode)){
                ui.displayFunction(1, entries.size(), envStack.peek().currentLine);
                if (firstRun){
                    firstRun = false;
                    System.out.println("Type '?' for help");
                }
                do{
                    ui.prompt();
                }
                while (ui.execute());
            }
            
            super.incPC();
        }
    }
    
    //Breakpoints may only be set at the beginning of the following constructs:
    // blocks decl if while return assign
    public boolean shouldPrompt(ByteCode code, ByteCode nextCode){
        String codeName = code.getClass().getSimpleName();
        if (envStack.size() != 0){
            if (firstRun || 
                ((envStack.peek().getStartLine() > 0) && (entries.get(envStack.peek().getCurrentLine()-1).isBreakptSet)) || // breakpoint
                (steppingOver) ||
                (steppingInto)){

                /*
                (steppingInto && (preStepEnvSize != envStack.size() || preStepLine != envStack.peek().getCurrentLine()))||
                (steppingOver && (preStepEnvSize > envStack.size() || (preStepLine != envStack.peek().getCurrentLine()&& preStepEnvSize == envStack.size() )))){
                */

                switch (codeName){
                    case "LineCode":
                        if (!(nextCode instanceof FunctionCode)){
                            preStepEnvSize = -2;
                            preStepLine = -2;
                            steppingOver = false;
                            steppingInto = false;
                            return true;
                        }
                        return false;
                    case "FunctionCode":
                        if (!(nextCode instanceof FunctionCode)){
                            preStepEnvSize = -2;
                            preStepLine = -2;
                            steppingInto = false;
                            return true;
                        }
                        return false;
                          
                    default:
                        if (preStepEnvSize > envStack.size() && steppingOut){
                            steppingOut = false;
                            return true;
                        }
                        return false;
                }
            }
            if (preStepEnvSize > envStack.size() && steppingOut){
                steppingOut = false;
                return true;
            }
        }
        return false;
    }
    
    public void initEntries(String sourceFile) throws IOException{
        BufferedReader source = new BufferedReader(new FileReader(sourceFile));
        String nextLine;
        
        try{
            nextLine = source.readLine();
            
            while (nextLine != null){
                entries.add(new Entry(nextLine,false));
                nextLine = source.readLine();
            }
        }
        catch(Exception e){}
    }
    
    public Entry getEntry(int i){
        return entries.elementAt(i);
    }
    public int numEntries(){
        return entries.size();
    }
    
    public boolean setBreakpoint(int i) throws NullPointerException{
        if (isValidBreakpoint(i)){
            entries.get(i-1).isBreakptSet = true;
            return true;
        }
        System.out.println("Invalid breakpoint line. Breakpoints may only be" + 
                " set at the beginning of the following constructs:\n" +
                "blocks, decl, if, while, return, assign");
        return false;
        
    }
    
    public void initValidBkpts(){
        ByteCode code;
        for (int i = 0; i < program().numCodes(); i++){
            code = program().getCode(i);
            if (code instanceof LineCode && Integer.valueOf(code.getArg(0)) > 0)
                validBkpts.add(Integer.valueOf(code.getArg(0)));
        }
    }
    public boolean isValidBreakpoint(int i){
        return validBkpts.contains(i);
    }
    public void clearAllBreakpoints(){
        for (int i = 0; i < entries.size(); i++){
            entries.get(i).isBreakptSet = false;
        }
    }
    public void clearBreakpoint(int i)throws NullPointerException{
        entries.get(i - 1).isBreakptSet = false;
    }
    public int envStackSize(){
        return envStack.size();
    }
    
    public FunctionEnvironmentRecord peekEnvStack(){
        if (envStack.empty())
            return null;
        return envStack.peek();
    }
    
    public void newFuncRec(){
        envStack.push(new FunctionEnvironmentRecord());
        envStack.peek().beginScope();
    }
    
    public boolean envStackEmpty(){
        return envStack.empty();
    }
    
    public void setCurrentLine(int i){
        envStack.peek().setCurrentLineNumber(i);
    }
    
    public void setFunction(String name, int start, int end){
        envStack.peek().setFunctionInfo(name, start, end);
    }
    
    public void popEnvStack(){
        envStack.pop();
    }
    
    
    
    public void addSymbol(String id, int offset){
        envStack.peek().setVarVal(id,offset);
    }
    
    public int getEndLine(){
        return envStack.get(0).getEndLine();
    }
    public void printVars(){
        HashMap<String,Integer> offsets = envStack.peek().varOffsets();
        String [] keys = envStack.peek().getVarIds();
        if (keys.length == 0){
            System.out.println("no local variables");
        }
        for (int i = 0; i < keys.length; i++){
            System.out.println(keys[i] + ": " + runStack().get(runStack().peekFrame() + offsets.get(keys[i])));
        }
    }
    
    public void stepOut(){
        steppingOut = true;
        preStepEnvSize = envStack.size();
    }
    public void stepOver(){
        steppingOver = true;
        preStepEnvSize = envStack.size();
        preStepLine = envStack.peek().getCurrentLine();
    }
    public void stepInto(){
        steppingInto = true;
        preStepEnvSize = envStack.size();
        preStepLine = envStack.peek().getCurrentLine();
    }
    
}

