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
public class PopCode extends ByteCode {
    ArrayList<String> args;
    int n;
    
    public void execute(VirtualMachine vm){
        while (n > 0){
            vm.popRunStack();
            n--;
        }
    }
    public void init(ArrayList<String> newArgs){
        args = new ArrayList<String>(newArgs);
        n = Integer.valueOf(args.get(0));
    }
    
    public String getArg(int index){
        return args.get(index);
    }
    
    public void setArg(int index, String value){
        args.set(index, value);
    }
    
    public void resolveAddress(){}
    
    public void print(){
        System.out.print("POP ");
        for (int i = 0; i < args.size(); i++){
            System.out.println(args.get(i) + " ");
        }
        System.out.println();
    }
}
