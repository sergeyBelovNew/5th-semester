%include "io.inc"
extern printf
section .data

%define  masA  1,2,3
section .bss

section .text
global CMAIN
CMAIN:
    ;write your code here
    mov rbp, rsp;
  
    mul  2
    PRINT_UDEC 1, [.data]
    
    
    ret