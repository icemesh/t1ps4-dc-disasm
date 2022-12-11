# t1ps4-dc-disasm
Tool for decompiling The Last Of Us ps4

# Tutorial
To decompile a script first find a script file that starts with `ss-\<name>.bin`
- The program will look for following folder: `sid1/sidbase.bin` in the same directory of the executable so **make sure its there otherwise there will only be a partial resolution of the stringIds**
- In this example we\'re going to use `ss-basic-door.bin`
Open the terminal and run the following command:
```
.\t1ps4-dc-disasm.exe .\ss-basic-door.bin > .\ss-basic-door.txt
```
This will redirect the output of the program to the file ss-basic-door.txt

# Notes
- Please let me know if a state name is not resolved.