# Branch-Predictor

To compile System 1 (static predicion) first compile 
the cpp file into the object code file "sys1.o":
 	g++ -c sys1.cpp

Next link to the object code creating the executable
file "sys1":
	g++ -o sys1 sys1.o

Now the executable file, "sys1.exe", can be called to run the program:
	./sys1 <filename>
where filename is the name of the trace file to be analyzed.

System 2 (2-bit predictor and branch target buffer) is compiled similarly
to System 1, but it the executable file requires additional arguments:
	./sys2 <filename> <#prediction entries> <#buffer entries> <verbose mode(optional with [-v])>
where #prediction entries and #buffer entries are powers of 2

I have included three trace files: test.trace, li1.trace, li2.trace. These can be used as inputs for either of the branch prediction systems. Each line of a trace file contains four hexadecimal integers, representing information from branches extracted from an instruction trace. The four (hexadecimal) integers on each line are: 

the address (i.e., PC) of the branch

the type of the branch (1 means direct branch, meaning either a conditional or unconditional branch similar to a MIPS I-format branch; 2 means indirect branch, meaning a branch where the target address comes from a register, similar to the MIPS jr instruction)

the target address

whether the branch is taken (1) or not taken (0)