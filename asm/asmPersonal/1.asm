%include "io.inc"

section .data

metka:
arrayA dd 50,60,70,80
X dd 25 ;ecx = 16
Y dd 30
arrayB dd 17,18,256
messageCalculationPart1 dw 'Sum(Array A[i] * X^2)'
messageCalculationPart2 dw 'Sum(Array B[i] * Y)'
messageCalculationPartFinal dw 'Sum(Array A[i] * X^2) + Sum(Array B[i] * Y)'

section .bss

section .text

global CMAIN
CMAIN:

    mov ebp, esp; for correct debugging
   
    mov ebx, 0
    mov ecx, 16
    mov eax, 0
    mov edx, 0
    mov esi, 0
    mov edi, 0
    
    mov eax, [metka + ecx] 
    mul eax
    mov ecx, 0
    
    summarizeArrayA:
     
      cmp ecx, 16
      je exitSummarizeA
      
      adc ebx, [metka + ecx]
      dec ebx
      imul ebx, eax
      adc esi, ebx
      adc ecx, 4
      mov ebx, 0
      jmp summarizeArrayA
      
    exitSummarizeA:
    
    PRINT_STRING messageCalculationPart1
    NEWLINE
    PRINT_UDEC 4, esi
    NEWLINE
    adc ecx, 4
    mov eax, [metka + ecx]
  
    
    summarizeArrayB:
      
      adc ecx, 4
      cmp ecx, 36
      je exitSummarizeB
      
      mov ebx, 0
      adc ebx, [metka + ecx]
      dec ebx
      imul ebx, eax
      adc edi, ebx
      jmp summarizeArrayB
      
       
    exitSummarizeB:
    
    PRINT_STRING messageCalculationPart2
    NEWLINE
    PRINT_UDEC 4, edi
    NEWLINE
    PRINT_STRING messageCalculationPartFinal
    NEWLINE
    adc esi, edi
    PRINT_UDEC 4, esi
   
    ret