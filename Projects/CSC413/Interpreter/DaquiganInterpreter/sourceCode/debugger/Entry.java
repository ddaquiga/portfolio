/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interpreter.debugger;

/**
 *
 * @author Darrel Daquigan
 */
public class Entry {
    public String sourceLine;
    public Boolean isBreakptSet;

    public Entry(String s, Boolean b){
        sourceLine = s;
        isBreakptSet = b;
    }

}
