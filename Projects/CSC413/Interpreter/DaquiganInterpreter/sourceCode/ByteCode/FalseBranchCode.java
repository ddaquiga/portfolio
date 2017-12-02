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
public class FalseBranchCode extends ByteCode {
    ArrayList<String> args;
    int branchAddrs;
    String addrsId;
    public void execute(VirtualMachine vm){
        if (vm.popRunStack() == 0){
            vm.branch(Integer.valueOf(branchAddrs));
        }
    }
    public void init(ArrayList<String> newArgs){
        args = new ArrayList<String>(newArgs);
        addrsId = args.get(0);
    }
    
    public String getArg(int index){
        return args.get(index);
    }
    
    public void setArg(int index, String value){
        args.set(index, value);
    }
    
    public void resolveAddress(){
        branchAddrs = Integer.valueOf(args.get(0));
    }
    
    public void print(){
        System.out.print("FALSEBRANCH " + addrsId);
        System.out.println();
    }
}
