/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interpreter;

import interpreter.ByteCode.*;
import java.io.*;
import java.util.*;

/**
 *
 * @author Darrel Daquigan
 */
public class ByteCodeLoader {
    BufferedReader source;
    
    public ByteCodeLoader(String programFile) throws IOException{
        source = new BufferedReader(new FileReader(programFile));
        
        
    }
    public Program loadCodes(){
        Program program = new Program();
        String nextLine;
        String hashKey;
        String hashValue;
        ByteCode byteCode;
        ArrayList<String> argArray = new ArrayList<String>();
        
        try{
            nextLine = source.readLine();
            
            while(nextLine != null){
                StringTokenizer st = new StringTokenizer(nextLine);
                hashKey = st.nextToken();
                hashValue = CodeTable.get(hashKey);
                byteCode = (ByteCode) (Class.forName("interpreter.ByteCode." +
                        hashValue).newInstance());
                
                argArray.clear();
                while(st.hasMoreTokens()){
                    argArray.add(st.nextToken());
                }
                byteCode.init(argArray);
                program.addCode(byteCode);
                nextLine = source.readLine();
                
            }
            program.resolveAddresses();
        }
        catch(Exception e){}
        
        return program;
    }
    
}
