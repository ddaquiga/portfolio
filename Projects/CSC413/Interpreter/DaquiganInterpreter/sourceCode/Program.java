/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interpreter;
import interpreter.ByteCode.*;
import java.util.ArrayList;
/**
 *
 * @author Darrel Daquigan
 */
public class Program extends Object {
    ArrayList<ByteCode> codes;
    
    public Program(){
        codes = new ArrayList<ByteCode>();
    }
    public void addCode(ByteCode newCode ){
        codes.add(newCode);
    }
    public ByteCode getCode(int index){ 
        return codes.get(index);
    }
    public int numCodes(){
        return codes.size();
    }
    public void resolveAddresses(){
        for (int i = 0; i < codes.size(); i++){
            if ( codes.get(i) instanceof FalseBranchCode ||
                    codes.get(i) instanceof GoToCode ||
                    codes.get(i) instanceof CallCode){
            
            String address = getAddress(codes.get(i).getArg(0));
            codes.get(i).setArg(0, address);
            codes.get(i).resolveAddress();
            }
        }
    }
    
    public String getAddress(String label){
        for (int i = 0; i < codes.size(); i++){
            if ( codes.get(i) instanceof LabelCode ){
                if ( label.equals(codes.get(i).getArg(0))){
                    return Integer.toString(i);
                }
            }
        }
        return "error"; //missing the arg, should not happen with good code
    }
    
    public void print(){
        for (int i = 0; i < codes.size(); i++){
            codes.get(i).print();
        }
    }
    
}
