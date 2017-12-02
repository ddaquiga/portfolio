/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interpreter.ByteCode;

import interpreter.ByteCode.CallCode;
import interpreter.*;
import interpreter.debugger.*;
import java.util.ArrayList;

/**
 *
 * @author Darrel Daquigan
 */
public class DebuggerCallCode extends CallCode {
    public void execute(VirtualMachine vm){
        super.execute(vm);
        vm.newFuncRec();
    };
}
