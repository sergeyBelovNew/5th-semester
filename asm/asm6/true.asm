%include "io.inc"

section .data

equalityMessages:
equal dw 'Equal'
notEqual dw 'Not equal'
section .bss

string3:
resw  1

temp:
resb 1

string4:
resw  1



section .text

global  CMAIN
global runTask1
global strEqual
global clearGeneralPurposeRegisters

CMAIN:

    mov ebp, esp; for correct debugging
    call runTask1
    ret
  
    
runTask1:
    
    call clearGeneralPurposeRegisters
    GET_STRING string3, 16
    GET_STRING temp, 8
    GET_STRING string4, 16
    PRINT_STRING string3
   
    NEWLINE
    call strEqual
    
    ret 
    
strEqual:
 
    mov esi, string3
    mov edi, string4
    
    cmpsw 
    
    je equalStrings
    PRINT_STRING notEqual
    ret
    equalStrings:
    PRINT_STRING equal
    ret
  
clearGeneralPurposeRegisters:

    mov eax, 0
    mov ebx, 0
    mov ecx, 0
    mov edx, 0
    mov esi, 0
    mov edi, 0
    ret
 
