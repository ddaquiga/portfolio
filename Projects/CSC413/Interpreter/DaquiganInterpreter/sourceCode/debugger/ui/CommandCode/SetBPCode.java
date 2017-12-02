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
public class SetBPCode extends CommandCode {
    Vector<String> args;
    int lines[];
    public boolean execute(DebuggerVM dvm){
        if (args.size() == 0){
            System.out.println("Invalid number of arguments. Try setbp" + 
                    " <lineNumber1> <lineNumber2> ... <lineNumbern>");
        }
        else{
            try{
                for (int i = 0; i < args.size(); i++){
                    if (!(dvm.isValidBreakpoint(lines[i]))){
                        System.out.println("Line number " + lines[i] +
                                " is invalid for a breakpoint");
                    }
                    else{
                        dvm.setBreakpoint(lines[i]);
                        System.out.println("Breakpoint set at line " + lines[i]);
                    }
                }
            }
            catch(NullPointerException e){
                System.out.println("Linenumber goes past end of file");
            }
        }
        return true;
    }
    public void init(Vector<String> newArgs){
        args = new Vector<String>();
        lines = new int[newArgs.size()];
        for (int i = 0; i < newArgs.size(); i++){
            args.add(newArgs.get(i));
            lines[i] = Integer.valueOf(args.get(i));
        }
    }
}
