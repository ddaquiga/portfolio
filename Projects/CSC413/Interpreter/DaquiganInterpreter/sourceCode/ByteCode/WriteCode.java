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
public class WriteCode extends ByteCode {
    ArrayList<String> args;
    public void execute(VirtualMachine vm){
        vm.write();
    }
    
    public void init(ArrayList<String> newArgs){
        args = new ArrayList<String>(newArgs);
    }
    
    public String getArg(int index){
        return args.get(index);
    }
    
    public void setArg(int index, String value){
        args.set(index, value);
    }
    
    public void resolveAddress(){}
    
    public void print(){
        System.out.print("WRITE ");
        for (int i = 0; i < args.size(); i++){
            System.out.println(args.get(i) + " ");
        }
        System.out.println();
    }
}
