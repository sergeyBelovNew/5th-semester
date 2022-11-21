%include "io.inc"

section .data

equalityMessages:
equal dw 'Equal'
notEqual dw 'Not Equal'

section .bss

string1:
resw 1
resb 1; 1 trash byte
string2:
resw 1

section .text

global CMAIN
global runTask1
global bitEqual
global clearGeneralPurposeRegisters

CMAIN:
    mov ebp, esp; for correct debugging
    
    call runTask1
    
    ret
    
runTask1:
    
    call clearGeneralPurposeRegisters
    GET_STRING string1, 8
    GET_STRING string2, 8
    PRINT_STRING string1
    NEWLINE
    PRINT_STRING string2
    NEWLINE
    ;call bitEqual
    
    ret 
    
bitEqual:
 
    cmpsw 
    jc   notEqualStrings
    PRINT_STRING equal
    ret
    notEqualStrings:
    PRINT_STRING notEqual
    ret
  
clearGeneralPurposeRegisters:

    mov eax, 0
    mov ebx, 0
    mov ecx, 0
    mov edx, 0
    mov esi, 0
    mov edi, 0
    ret