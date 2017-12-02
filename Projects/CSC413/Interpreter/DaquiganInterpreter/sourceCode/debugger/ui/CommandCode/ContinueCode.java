/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interpreter.debugger.ui.CommandCode;
import interpreter.VirtualMachine;
import interpreter.debugger.*;
import java.util.*;
/**
 *
 * @author Darrel Daquigan
 */
public class ContinueCode extends CommandCode {

    public boolean execute(DebuggerVM dvm){
        return false;
    }
    public void init(Vector<String> newArgs){
    }
}
