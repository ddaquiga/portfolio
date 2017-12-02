/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interpreter.ByteCode;

import interpreter.VirtualMachine;

/**
 *
 * @author Darrel Daquigan
 */
public abstract class ByteCode {
    public abstract void execute(VirtualMachine vm);
    public abstract void init(java.util.ArrayList<String> args);
    public abstract String getArg(int index);
    public abstract void setArg(int index, String value);
    public abstract void resolveAddress();
    public abstract void print();
}
