/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interpreter.debugger.ui.CommandCode;
import interpreter.debugger.*;
import java.util.*;

/**
 *
 * @author Darrel Daquigan
 */
public class DisVarCode extends CommandCode{
    public boolean execute(DebuggerVM dvm){
        HashMap<String,Integer> offsets = dvm.peekEnvStack().varOffsets();
        String [] keys = dvm.peekEnvStack().getVarIds();
        if(keys.length == 0){
            System.out.println("no local variables");
        }
        for (int i = 0; i < keys.length; i++){
            System.out.println(keys[i] + ": " +
                    dvm.runStack().get(dvm.runStack().peekFrame() +
                            offsets.get(keys[i])));
        }
        return true;
    }
    public void init(Vector<String> newArgs){
    }
}
