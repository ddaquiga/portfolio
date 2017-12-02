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
public class GoToCode extends ByteCode {
    ArrayList<String> args;
    String addrs;
    
    public void execute(VirtualMachine vm){
        vm.branch(Integer.valueOf(addrs));
    }
    public void init(ArrayList<String> newArgs){
        args = new ArrayList<String>(newArgs);
        addrs = args.get(0);
    }
    
    public String getArg(int index){
        return args.get(index);
    }
    
    public void setArg(int index, String value){
        args.set(index, value);
    }
    
    public void resolveAddress(){
        addrs = args.get(0);
    }
    
    public void print(){
        System.out.print("GOTO ");
        for (int i = 0; i < args.size(); i++){
            System.out.println(args.get(i) + " ");
        }
        System.out.println();
    }
}
