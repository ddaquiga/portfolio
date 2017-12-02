/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interpreter.debugger.ui.CommandCode;
import interpreter.VirtualMachine;
import interpreter.debugger.*;


/**
 *
 * @author Darrel Daquigan
 */
public abstract class CommandCode {
    public abstract boolean execute(DebuggerVM dvm);
    public abstract void init(java.util.Vector<String> args);    
}
