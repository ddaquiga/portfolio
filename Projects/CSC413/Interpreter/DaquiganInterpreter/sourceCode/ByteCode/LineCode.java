/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interpreter.ByteCode;

import interpreter.debugger.*;
import interpreter.ByteCode.ByteCode;
import interpreter.VirtualMachine;
import java.util.ArrayList;

/**
 *
 * @author Darrel Daquigan
 */
public class LineCode extends ByteCode {
    ArrayList<String> args;
    int lineNum;
    
    public void execute(VirtualMachine vm){
        if (vm.envStackEmpty())
            vm.newFuncRec();
        vm.setCurrentLine(lineNum);
    }
    
    public void init(ArrayList<String> newArgs){
        args = new ArrayList<String>(newArgs);
        lineNum = Integer.valueOf(args.get(0));
    }
    
    public String getArg(int index){
        return args.get(index);
    }
    
    public void setArg(int index, String value){
        args.set(index, value);
    }
    
    public void resolveAddress(){};
    public void print(){
        System.out.print("LINE ");
        for (int i = 0; i < args.size(); i++){
            System.out.print(args.get(i));
            if (i != args.size() - 1)
                System.out.print(" ");
        }
    }
    
}
