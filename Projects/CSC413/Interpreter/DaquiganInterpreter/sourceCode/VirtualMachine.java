/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interpreter;

import interpreter.ByteCode.*;
import interpreter.debugger.FunctionEnvironmentRecord;
import java.util.Stack;
import java.util.Scanner;


/**
 *
 * @author Darrel Daquigan
 */
public class VirtualMachine {
    RunTimeStack runStack;
    int pc;
    Stack<Integer> returnAddrs;
    boolean isRunning;
    boolean dumpFlag;
    Program program;
    int numArgs;
    
    
    public VirtualMachine(Program p){
        program = p; 
        pc = 0;
        runStack = new RunTimeStack();
        returnAddrs = new Stack<Integer>();
        isRunning = true;
        dumpFlag = false;
        
    }
    
    
    public void executeProgram(){
        while(isRunning){
            ByteCode code = program.getCode(pc);
            code.execute(this);
            
            if (!(code instanceof DumpCode) && dumpFlag == true){
                code.print();
                runStack.dump();
            }
            pc++;
        }
    }
    
    public RunTimeStack runStack(){return runStack;}
    public boolean dumpFlag(){ return dumpFlag;}
    public boolean isRunning(){ return isRunning;}
    
    public int pc(){ return pc;}
    public Program program(){ return program;}
    
    public void incPC(){ pc++;}
    
    public void stopRunning(){
        isRunning = false;
    }
    
    public void branch(int i){
        pc = i;
    }
    
    public void call(int addrs){
        returnAddrs.push(pc);
        runStack.newFrameAt(numArgs);
        pc = addrs;
        
    }
    
    public void setNumArgs(int i){
        numArgs = i;
    }
    
    
    public void dumpOn(){
        dumpFlag = true;
    }
    
    public void dumpOff(){
        dumpFlag = false;
    }
    
    public int peekReturnAddrs(){
        return returnAddrs.peek();
    }
    
    public int popReturnAddrs(){
        return returnAddrs.pop();
    }
    
    public void pushReturnAddrs(){
        returnAddrs.push(pc + 1);
    }
    
    public int peekRunStack(){
        return runStack.peek();
    }
    
    public int popRunStack(){
        return runStack.pop();
    }
    
    public int pushRunStack(int i){
        runStack.push(i);
        return i;
    }
    
    public void newFrameStack(int offset){
        runStack.newFrameAt(offset);
    }
    
    public void popFrameStack(){
        runStack.popFrame();
    }
    
    public int storeRunStack(int offset){
        return runStack.store(offset);
    }
    
    public int loadRunStack(int offset){
        return runStack.load(offset);
    }
    
    public Integer pushRunStack(Integer i){
        return runStack.push(i);
    }
    
    public void read(){
        System.out.print("Enter a number: ");
        Scanner reader = new Scanner(System.in);
        runStack.push(reader.nextInt());
    }
    
    public void write(){
        System.out.println(runStack.peek());
    }
    
    public void deleteFrame(){
        int topValue = runStack.pop();
        int frameStart = runStack.popFrame();
        while(runStack.size() > frameStart){
            runStack.pop();
        }
        runStack.push(topValue);
    }
    
    public void branchReturn(){
        pc = returnAddrs.pop();
    }
    
    public void operate(String operator){
        int secondOperand = popRunStack();
        int firstOperand = popRunStack();
        
        switch (operator){
            case ("+"):
                pushRunStack(firstOperand + secondOperand);
                break;
                
            case ("-"):
                pushRunStack(firstOperand - secondOperand);
                break;
                
            case ("/"):
                pushRunStack(firstOperand / secondOperand);
                break;
                
            case ("*"):
                pushRunStack(firstOperand * secondOperand);
                break;
                
            case ("=="):
                if (firstOperand == secondOperand)
                    pushRunStack(1);
                else
                    pushRunStack(0);
                break;
                
            case ("!="):
                if (firstOperand != secondOperand)
                    pushRunStack(1);
                else
                    pushRunStack(0);
                break;
                
            case ("<="):
                if (firstOperand <= secondOperand)
                    pushRunStack(1);
                else
                    pushRunStack(0);
                break;
                
            case (">"):
                if (firstOperand > secondOperand)
                    pushRunStack(1);
                else
                    pushRunStack(0);
                break;
            case (">="):
                if (firstOperand >= secondOperand)
                    pushRunStack(1);
                else
                    pushRunStack(0);
                break;
                
            case ("<"):
                if (firstOperand < secondOperand)
                    pushRunStack(1);
                else
                    pushRunStack(0);
                break;
                
            case ("|"):
                if (firstOperand == 1 || secondOperand == 1)
                    pushRunStack(1);
                else
                    pushRunStack(0);
                break;
                
            case ("&"):
                if (firstOperand == 1 && secondOperand == 1 )
                    pushRunStack(1);
                else
                    pushRunStack(0);
                break;
        }
    }
    
    public String getArgs(){
        Stack<Integer> tempStack = new Stack<Integer>();
        String argBuffer = "";
        for (int i = 0; i < numArgs; i++){
            tempStack.push(runStack.pop());
        }
        for (int i= 0; i < numArgs; i++){
            argBuffer += tempStack.peek();
            runStack.push(tempStack.pop());
            if ( i != numArgs - 1){
                argBuffer += ", ";
            }
        }
        return argBuffer;
    }
    
    
    public void newFuncRec(){}
    public boolean envStackEmpty(){
        return false;
    }
    public void setCurrentLine(int i){}
    public void setFunction(String n,int s,int e){}
    public FunctionEnvironmentRecord peekEnvStack(){
        return null;
    }
    public void popEnvStack(){}
    public void addSymbol(String id, int value){};
    public int topOffset(){
        return runStack.getTopOffset();
    };
    
}
