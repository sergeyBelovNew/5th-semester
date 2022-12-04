format PE GUI 4.0
entry start
include 'win32a.inc'

section '.code' code readable executable
 start:
    mov ebp, esp; for correct debugging
    
   
    invoke scanf, string1
    invoke printf, string1
    invoke sleep, 2000
    LRESULT WINAPI SendMessage
    call [getch]
    ret
    

section '.bss' readable writeable

string1: dw ?
string2: dw ?

section '.idata' import data readable writeable
        
 library kernel32, 'kernel32.dll', \
                msvcrt,   'msvcrt.dll'
        import kernel32, ExitProcess, 'ExitProcess',  sleep, 'Sleep' 
        import msvcrt,  printf, 'printf' ,  scanf , 'snamf', getch, 'getch' 
                 