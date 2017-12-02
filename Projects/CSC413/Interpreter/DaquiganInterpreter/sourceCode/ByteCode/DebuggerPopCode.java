/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interpreter.ByteCode;

import interpreter.VirtualMachine;
import java.util.ArrayList;

/**
 *
 * @author Darrel Daquigan
 */
public class DebuggerPopCode extends PopCode{
    public void execute(VirtualMachine vm){
        vm.peekEnvStack().doPop(n);
        super.execute(vm);
    }
    
}
