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
public class DisFuncCode extends CommandCode {

    public boolean execute(DebuggerVM dvm){
        int start, end, current;
        start = dvm.peekEnvStack().getStartLine();
        end = dvm.peekEnvStack().getEndLine();
        current = dvm.peekEnvStack().getCurrentLine();
        if (start != -1)
            displayFunction(start,end,current,dvm);
        else
            System.out.println("In " + dvm.peekEnvStack().getName() + " function");
        return true;
    }
    public void init(Vector<String> newArgs){
    }
    public void displayFunction(int start, int end, int current, DebuggerVM dvm){
        System.out.print("Function: ");
        System.out.println(dvm.peekEnvStack().getName());
        System.out.println();
        for (int i = 0; i < end - start; i++){
            if (dvm.getEntry(i + start - 1).isBreakptSet)
                System.out.print("*");
            else
                System.out.print(" ");
            
            if (start + i < 10)
                System.out.print(" ");
            System.out.print((i + start) + ". " + dvm.getEntry(i+start-1).sourceLine);
            
            if ( i + start == current)
                System.out.print("          <----");
            System.out.println();
        }
    }
}
