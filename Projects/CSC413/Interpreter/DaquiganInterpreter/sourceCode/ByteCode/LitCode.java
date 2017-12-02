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
public class LitCode extends ByteCode {
    ArrayList<String> args;
    int value;
    String id;
    public void execute(VirtualMachine vm){
        vm.pushRunStack(value);
    }
    public void init(ArrayList<String> newArgs){
        args = new ArrayList<String>(newArgs);
        if ( args.size() == 1){
            value = Integer.valueOf(args.get(0));
        }
        else {
            value = 0;
            id = args.get(1);
        }
    }
    
    public String getArg(int index){
        return args.get(index);
    }
    
    public void setArg(int index, String value){
        args.set(index, value);
    }
    
    public void resolveAddress(){}
    
    public void print(){
        System.out.print("LIT ");
        for (int i = 0; i < args.size(); i++){
            System.out.print(args.get(i) + " ");
        }
        if (args.size() == 2){
            System.out.print("  int " + id);
        }
        System.out.println();
    }
}
