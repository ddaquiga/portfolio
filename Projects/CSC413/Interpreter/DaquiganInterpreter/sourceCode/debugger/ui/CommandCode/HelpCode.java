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
public class HelpCode extends CommandCode{
    public boolean execute(DebuggerVM dvm){
        System.out.println("? - display help menu\n" +
                "sb <lineNumber> - sets a breakpoint at the line number\n" +
                "cb - clears all breakpoints\n" +
                "cb <lineNumber> - clears any breakpoint at the line number\n" +
                "df - displays the current function\n" +
                "dv - display local variables\n" +
                "c - Continue execution\n" +
                "out - step out\n" +
                "in - step into\n" +
                "ov - step over \n" +
                "q - Quit execution");
        return true;
    }
    
    public void init(java.util.Vector<String> args){
        
    }
}
