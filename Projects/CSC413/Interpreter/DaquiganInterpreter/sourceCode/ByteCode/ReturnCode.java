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
public class ReturnCode extends ByteCode {
    ArrayList<String> args;
    String id;
    int returnValue;
    
    public void execute(VirtualMachine vm){
        vm.deleteFrame();
        vm.branchReturn();
        returnValue = vm.peekRunStack();
    }
    
    public void init(ArrayList<String> newArgs){
        args = new ArrayList<String>(newArgs);
        if (args.size() != 0)
            id = args.get(0);
    }
    
    public String getArg(int index){
        return args.get(index);
    }
    
    public void setArg(int index, String value){
        args.set(index, value);
    }
    
    public void resolveAddress(){}
    
    public void print(){
        System.out.print("RETURN ");
        for (int i = 0; i < args.size(); i++){
            System.out.print(args.get(i) + " ");
        }
        if (args.size() == 1){
            boolean done = false;
            String baseId = "";
            int i = 0;
            while (!done){
                char c = id.charAt(i);
                if (c != '<'){
                    baseId += c;
                    i++;
                }
                else
                    done = true;
                
            }
            System.out.print(" exit " + baseId + ": " + returnValue);
        }
        System.out.println();
    }
}
