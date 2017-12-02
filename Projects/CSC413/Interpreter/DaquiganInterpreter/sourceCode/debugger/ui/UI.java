/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interpreter.debugger.ui;

import interpreter.debugger.*;
import interpreter.debugger.ui.CommandCode.*;
import java.util.*;

/**
 *
 * @author Darrel Daquigan
 */
public class UI {
    DebuggerVM dvm;
    String command;
    Vector<String> args;
    Scanner s;
    boolean reprompt;
    
    public UI(DebuggerVM d){
        dvm = d;
        args = new Vector<String>();
        s = new Scanner(System.in);
    }
    
    public void prompt(){
        args.clear();
        System.out.print(">");
        StringTokenizer st = new StringTokenizer(s.nextLine());
        command = st.nextToken();
        while(st.hasMoreTokens()){
            args.add(st.nextToken());
        }
    }
    
    public boolean execute(){
        CommandCode cmdCode;
        switch (command){
            case "?":
                cmdCode = new HelpCode();
                break;
            case "sb":
                cmdCode = new SetBPCode();
                break;
            case "cb":
                cmdCode = new ClearBPCode();
                break;
            case "df":
                cmdCode = new DisFuncCode();
                break;
            case "dv":
                cmdCode = new DisVarCode();
                break;
            case "c":
                cmdCode = new ContinueCode();
                break;
            case "q":
                cmdCode = new QuitCode();
                break;
            case "out":
                cmdCode = new StepOutCode();
                break;
            case "in":
                cmdCode = new StepIntoCode();
                break;
            case "ov":
                cmdCode = new StepOverCode();
                break;
            
            default:
                cmdCode = new InvalidCode();
                break;
        }
        cmdCode.init(args);
        return cmdCode.execute(dvm);
    }
    
    public boolean isInteger(String s){
        try{
            Integer.parseInt(s);
            return true;
        }
        catch (NumberFormatException e){
            return false;
        }
    }
    public void displayFunction(int start, int end, int current){
        System.out.print("Function: ");
        System.out.println(dvm.peekEnvStack().getName());
        for (int i = 0; i < end - start; i++){
            if (dvm.getEntry(i + start - 1).isBreakptSet)
                System.out.print("*");
            else
                System.out.print(" ");
            
            if (start + i < 10)
                System.out.print(" ");
            System.out.print((i + start) + ". " + dvm.getEntry(i+start-1).sourceLine);
            
            if ( i + start == current)
                System.out.print("         <----");
            System.out.println();
        }
    }
    
    
    
}


