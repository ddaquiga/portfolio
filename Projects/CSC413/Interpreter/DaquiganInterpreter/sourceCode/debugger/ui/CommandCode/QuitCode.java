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
public class QuitCode extends CommandCode {

    public boolean execute(DebuggerVM dvm){
       dvm.stopRunning();
       return false;
    }
    public void init(Vector<String> newArgs){
    }
    public void displayFunction(int start, int end, int current, DebuggerVM dvm){
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
