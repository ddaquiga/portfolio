/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interpreter;

import java.util.Stack;
import java.io.*;

/**
 *
 * @author Darrel Daquigan
 */
public class RunTimeStack {
    Stack<Integer> runTimeStack;
    Stack<Integer> framePointers;
    String dumpData;
    
    public RunTimeStack(){
        runTimeStack = new Stack();
        framePointers = new Stack();
        framePointers.push(0);
    }
    
    public void dump(){
        dumpData = "";
        Stack<Integer> readRunStack = new Stack<Integer>();
        Stack<Integer> readFrameStack = new Stack<Integer>();
        
        int currentRunStackSize = runTimeStack.size();
        int currentFrameStackSize = framePointers.size();
        
        for (int i = 0; i< currentRunStackSize; i ++){
            readRunStack.push(runTimeStack.pop());
        }
        for (int i = 0; i < currentFrameStackSize; i++){
            readFrameStack.push(framePointers.pop());
        }
        boolean startNewFrame = true;
        
        for (int i = 0; i < currentRunStackSize; i ++){
            if (startNewFrame){
                dumpData += "[";
                framePointers.push(readFrameStack.pop()); // push initial 0
                startNewFrame = false;
            }
            dumpData += readRunStack.peek();
            runTimeStack.push(readRunStack.pop());
                        
            boolean endOfFrame = false;
            if (readFrameStack.size() != 0){
                if (readFrameStack.peek() == i + 1)
                    endOfFrame = true;
                
            }
            if (readRunStack.size() == 0)
                endOfFrame = true;
            
            if (endOfFrame){
                dumpData += "]";
                startNewFrame = true;
            }
                
            else
                dumpData += ",";
               
        }
        if (currentRunStackSize == 0){
            dumpData = "[]";
        }
        
        while(readFrameStack.size() > 0){
            framePointers.push(readFrameStack.pop());
        }
        System.out.println(dumpData);
        
    }
    
    public int peek(){
        return runTimeStack.peek();
    }
    
    public int pop(){
        return runTimeStack.pop();
    }
    
    public int push(int i){
        runTimeStack.push(i);
        return i;
    }
    
    public void newFrameAt(int offset){
        framePointers.push(runTimeStack.size() - offset);
        
    }
    
    public int popFrame(){
        return framePointers.pop();
       
    }
    public int peekFrame(){
        return framePointers.peek();
    }
    
    public int store(int offset){
        int value = runTimeStack.peek();
        runTimeStack.set(framePointers.peek() + offset, runTimeStack.pop());
        return value;
    }
    public int load(int offset){
        int value = runTimeStack.get(framePointers.peek() + offset);
        runTimeStack.push(value);
        return value;
    }
    public Integer push(Integer i){
        runTimeStack.push(i);
        return i;
    }
    public int size(){
        return runTimeStack.size();
    }
    
    public int getTopOffset(){
        return runTimeStack.size() - framePointers.peek();
    }
    
    public int get(int i){
        return runTimeStack.get(i);
    }
    
}
