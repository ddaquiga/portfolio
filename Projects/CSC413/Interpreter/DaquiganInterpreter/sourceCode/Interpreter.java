package interpreter;

import interpreter.debugger.*;
import java.io.*;

/**
 * <pre>
 * 
 *  
 *   
 *     Interpreter class runs the interpreter:
 *     1. Perform all initializations
 *     2. Load the bytecodes from file
 *     3. Run the virtual machine
 *     
 *   
 *  
 * </pre>
 */
public class Interpreter {

	ByteCodeLoader bcl;
        String xFile;
        

	public Interpreter(String codeFileBase, boolean debugMode) {
                String codeFile;
                if (debugMode){
                    xFile = codeFileBase + ".x";
                    codeFile = codeFileBase + ".x.debug.cod";
                    if (!(new File(codeFile).exists())){
                        codeFile = codeFileBase + ".x.cod";
                    }    
                }
                else
                    codeFile = codeFileBase;
                try {
                        CodeTable.init(debugMode);
                        bcl = new ByteCodeLoader(codeFile);
                } catch (IOException e) {
                        System.out.println("**** " + e);
                }
	}

	void run(boolean debugMode) {
		Program program = bcl.loadCodes();
                VirtualMachine vm;
                if (debugMode)
                    vm = new DebuggerVM(program,xFile);
                else
                    vm = new VirtualMachine(program);
                vm.executeProgram();
	}

	public static void main(String args[]) {
		if (args.length == 0) {
			System.out.println("***Incorrect usage, try: java" +
                                " -jar Interpreter.jar [-d] <file>");
			System.exit(1);
		}
                
                
                switch( args[0].charAt(0)){
                    case '-':
                        if (args[0].charAt(1) == 'd')
                            (new Interpreter(args[1],true)).run(true);
                        else{
                            System.out.println("***Incorrect usage, try: java" +
                                    " -jar Interpreter.jar -d <fileBase>");
                            System.exit(1);
                        }
                        break;
                    default:
                        (new Interpreter(args[0],false)).run(false);
                    
                }
	}
}