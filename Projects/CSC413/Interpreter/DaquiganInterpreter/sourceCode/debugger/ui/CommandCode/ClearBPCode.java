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
public class ClearBPCode extends CommandCode {
    Vector<String> args;
    int lines[];
    public boolean execute(DebuggerVM dvm){
        if (args.size() == 0){
            dvm.clearAllBreakpoints();
            System.out.println("All breakpoints cleared");
        }
        else{
            for (int i = 0; i < args.size(); i++){
                if (lines[i] > 0 || lines[i] <= dvm.numEntries()){
                    if(!(dvm.getEntry(lines[i]-1).isBreakptSet)){
                        System.out.println("No breakpoint at line " + lines[i]);
                    }
                    else{
                        dvm.clearBreakpoint(lines[i]);
                        System.out.println("Cleared breakpoint at line " + lines[i]);
                    }
                }
                else{
                    System.out.println("Line number " + lines[i] + " does not exist");
                }
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
