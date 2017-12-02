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
public class CallCode extends ByteCode {
    ArrayList<String> args;
    int addrs;
    String id;
    String funcArgs;
    
    public void execute(VirtualMachine vm){
        vm.call(addrs);
        funcArgs = vm.getArgs();
    }
    
    public void init(ArrayList<String> newArgs){
        args = new ArrayList<String>(newArgs);
        id = args.get(0);
    }
    
    public String getArg(int index){
        return args.get(index);
    }
    
    public void setArg(int index, String value){
        args.set(index, value);
    }
    
    public void resolveAddress(){
        addrs = Integer.valueOf(args.get(0));
    }
    
    public void print(){
        System.out.print("CALL ");
        for (int i = 0; i < args.size(); i++){
            System.out.print(id + " ");
        }
        
        boolean done = false;
        String baseId = "";
        int i = 0;
        while (!done && i < id.length()){
            char c = id.charAt(i);
            if (c != '<'){
                baseId += c;
                i++;
            }
            else
                done = true;

        }
        
        System.out.println(" " + baseId + "(" + funcArgs + ")");
    }
}
