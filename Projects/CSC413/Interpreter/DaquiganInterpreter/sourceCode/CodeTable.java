/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interpreter;
import interpreter.ByteCode.*;


/**
 *
 * @author Darrel Daquigan
 */
public class CodeTable extends Object
{
    public static java.util.HashMap<String, String> hashMap = 
            new java.util.HashMap<String,String>();
    
    public static String get(String code){
        return hashMap.get(code);
    }
    
    public static void init(boolean debugMode){
        hashMap.put("HALT","HaltCode");
        hashMap.put("FALSEBRANCH","FalseBranchCode");
        hashMap.put("GOTO","GoToCode");
        hashMap.put("STORE","StoreCode");
        hashMap.put("LOAD","LoadCode");
        hashMap.put("ARGS","ArgsCode");
        hashMap.put("BOP","BopCode");
        hashMap.put("READ","ReadCode");
        hashMap.put("WRITE","WriteCode");
        hashMap.put("LABEL","LabelCode");
        hashMap.put("DUMP","DumpCode");
        
        if(!debugMode){
            hashMap.put("CALL","CallCode");
            hashMap.put("LIT","LitCode");
            hashMap.put("POP","PopCode");
            hashMap.put("RETURN","ReturnCode");
        }
        else{
            hashMap.put("CALL","DebuggerCallCode");
            hashMap.put("LIT","DebuggerLitCode");
            hashMap.put("POP","DebuggerPopCode");
            hashMap.put("RETURN","DebuggerReturnCode");
            
            hashMap.put("FORMAL", "FormalCode");
            hashMap.put("LINE", "LineCode");
            hashMap.put("FUNCTION","FunctionCode");
        }
    }
}
