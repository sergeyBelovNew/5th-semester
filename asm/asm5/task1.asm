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

entry  CMAIN
proc runTask1
proc strEqual
proc strLenght
proc strReverse
proc clearGeneralPurposeRegisters

CMAIN:

    mov ebp, esp; for correct debugging
    call runTask1
    ret
    endp
    
runTask1:
    
    call clearGeneralPurposeRegisters
    GET_STRING string1, 8
    ;int 21h
    GET_STRING string2, 8
    ;int 21h
    PRINT_STRING string1
    PRINT_STRING string2
    NEWLINE
    call strEqual
    NEWLINE
    call strLenght
    ret 
    
strEqual:
 
    mov esi,string1
    mov edi,string2
    cld
    cmpsw 
    jnz notEqualStrings
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
 
strLenght:

    mov edi, string1
    repne scasb
    mov eax, ecx
  
    mov edi, string2
    repne scasb
   
    cmp eax, ecx
    jne notEquelLenght
    PRINT_STRING equal
    ret
    notEquelLenght:
    PRINT_STRING notEqual
    ret
    
strReverse:
