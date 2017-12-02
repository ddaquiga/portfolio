/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interpreter.debugger;

import java.io.*;
import java.util.Set;
import java.util.HashMap;
/**
 *
 * @author Darrel Daquigan
 */
public class FunctionEnvironmentRecord {
    public Table symtab;
    int startLine;
    int endLine;
    int currentLine;
    String name;
    
    public FunctionEnvironmentRecord(){
        symtab = new Table();
        startLine = -2;
        endLine = -2;
        currentLine = -2;
        name = "";
    }
    
    public int getStartLine(){
        return startLine;
    }
    
    public int getEndLine(){
        return endLine;
    }
    
    public int getCurrentLine(){
        return currentLine;
    }
    
    public String getName(){
        return name;
    }
    
    public void setStartLine(int i){
        startLine = i;
    }
    
    public void setEndLine(int i){
        endLine = i;
    }
    
    public void setCurrentLineNumber(int i){
        currentLine = i;
    }
    
    public int getOffset(String sym){
        return (Integer)symtab.get(sym);
    }
    
    public void setVarVal(String sym, int value){
        symtab.put(sym, value);
        
    }
    
    public void beginScope(){
        symtab.beginScope();
    }
    
    public void endScope(){
        symtab.endScope();
    }
    
    public int numSymbols(){
        return symtab.size();
    }
    
    public void setFunctionInfo(String nm, int start, int end){
        name = nm;
        startLine = start;
        endLine = end;
    }
    
    public void doPop(int n){
        symtab.pop(n);
    }
    
    public HashMap<String,Integer> varOffsets(){
        HashMap<String,Integer> varOff = new HashMap<String,Integer>();
        String[] keys = new String[symtab.size()];
        int [] offsets = new int[symtab.size()];
        symtab.keys().toArray(keys);
        
        for (int i = 0; i < symtab.size(); i++){
            varOff.put(keys[i],symtab.get(keys[i]));
            
        }
        return varOff;
    }
    
    public String [] getVarIds(){
        String [] keys = new String[symtab.size()];
        symtab.keys().toArray(keys);
        return keys;       
    }
    
    public void dump(){
        System.out.print("(<");
        symtab.print();
        System.out.print(">,");
        
        if (name.equals(""))
            System.out.print("-");
        else
            System.out.print(name);
        System.out.print(",");
        
        if (startLine == -2)
            System.out.print("-");
        else
            System.out.print(startLine);
        System.out.print(",");
        
        if(endLine == -2)
            System.out.print("-");
        else
            System.out.print(endLine);
        System.out.print(",");
        
        if (currentLine == -2)
            System.out.print("-");
        else
            System.out.print(currentLine);
        System.out.println(")");
        
        
    }
    
    /*
    public static void main(String args[]){
        FunctionEnvironmentRecord fctEnvRecord =
                new FunctionEnvironmentRecord();
        
        System.out.println("BS");
        fctEnvRecord.beginScope();
        fctEnvRecord.dump();
        
        System.out.println("Function g 1 20");
        fctEnvRecord.setFunctionInfo("g", 1, 20);
        fctEnvRecord.dump();
                
        System.out.println("Line 5");
        fctEnvRecord.setCurrentLineNumber(5);
        fctEnvRecord.dump();
        
        System.out.println("Enter a 4");
        fctEnvRecord.setVarVal("a",(int)4); //null kind for now
        fctEnvRecord.dump();
        
        System.out.println("Enter b 2");
        fctEnvRecord.setVarVal("b",(int)2);
        fctEnvRecord.dump();
        
        System.out.println("Enter c 7");
        fctEnvRecord.setVarVal("c",(int)7);
        fctEnvRecord.dump();
        
        System.out.println("Enter a 1");
        fctEnvRecord.setVarVal("a", (int)1);
        fctEnvRecord.dump();
        
        System.out.println("Pop 2");
        fctEnvRecord.doPop(2);
        fctEnvRecord.dump();
        
        System.out.println("Pop 1");
        fctEnvRecord.doPop(1);
        fctEnvRecord.dump();
    }
    */
}
