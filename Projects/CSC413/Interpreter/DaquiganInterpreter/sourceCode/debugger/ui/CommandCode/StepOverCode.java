/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interpreter.debugger.ui.CommandCode;
import interpreter.debugger.*;
/**
 *
 * @author Darrel Daquigan
 */
public class StepOverCode extends CommandCode {
    public boolean execute(DebuggerVM dvm){
        dvm.stepOver();
        return false;
    }
    public void init(java.util.Vector<String> args){
        
    }
}
