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
public class DebuggerLitCode extends LitCode {
    public void execute(VirtualMachine vm){
        super.execute(vm);
        if(args.size() == 2){
            vm.addSymbol(id,vm.topOffset() - 1);
        }
    }
    
}
