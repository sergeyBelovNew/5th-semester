format PE GUI 4.0
entry Start

include 'win32a.inc'

section '.text' code readable executable

Start:
  
mov ebp, esp; for correct debugging
call runTask
ret

runTask:
invoke MessageBox, 0, string1, title, 0
call clearGeneralPurposeRegisters
call divStr
ret

proc divStr

mov esi, string1
lodsw
mov [string2], eax
invoke MessageBox, 0, string2, title, 0

mov eax, string1
adc eax, 2
mov esi, eax
lodsw
mov [string3], eax
invoke MessageBox, 0, string3, title, 0
ret
endp

proc clearGeneralPurposeRegisters
mov eax, 0
mov ebx, 0
mov ecx, 0
mov edx, 0
mov esi, 0
mov edi, 0
ret
endp

section '.mes' data readable writeable

  title:
  mes1 dW "I_"
  mes2 dd "love"
  mes3 db "_"
  mes4 dd "beer"

section '.data' data readable writeable


  string1:
  str1  dd  "Beer"
  string2:
  str2  db ?
  string3:
  str3  db ?

section '.idata' import data readable writeable

  library kernel32, 'KERNEL32.DLL',\
	  user32, 'USER32.DLL'

  include 'api\kernel32.inc'
  include 'api\user32.inc'