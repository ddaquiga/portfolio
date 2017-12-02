/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interpreter.ByteCode;

import interpreter.VirtualMachine;
import java.util.ArrayList;

/**
 *
 * @author Darrel Daquigan
 */
public class FormalCode extends ByteCode{
    ArrayList<String> args;
    String name;
    int offset;
    public void execute(VirtualMachine vm){
        vm.addSymbol(name, offset);
    }
    
    public void init(ArrayList<String> newArgs){
        args = newArgs;
        name = args.get(0);
        offset = Integer.valueOf(args.get(1));
    }
    
    public String getArg(int index){
        return args.get(index);
    }
    
    public void setArg(int index, String value){
        args.set(index,value);
    }
    
    public void resolveAddress(){};
    
    public void print(){
        System.out.print("FORMAL ");
        for (int i = 0; i < args.size(); i++){
            System.out.print(args.get(i) + " ");
        }
        System.out.println();
    }
    
}
