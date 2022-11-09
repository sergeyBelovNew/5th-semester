#include <iostream>
#include <conio.h>
#include <iomanip>
#include <sstream>




int main() {
	
	uint32_t number = 0xDEFBCDEF;

	unsigned char numberOnes = 0;
	int numberZeroes = 0;
	unsigned char numberOnes2 = 0;
	int numberZeroes2 = 0;
    
	__asm {
		pushad
		
		mov ecx, 0
		mov eax, 0 //Counter of ones
		lea ebx, number
		mov ebx, [ebx]

	calculationShr:
		
		clc
		inc ecx
		shr ebx, 1     //shift of bits to 1 left(equel of div 2)
		jc  onesIncrem
		jnc  zeroChooseExit1

	onesIncrem:
		
		inc eax
		clc
		cld
		cmp ecx, 32
		jb calculationShr
		je exitCalculation1

	zeroChooseExit1:
		
		clc
		cld
		cmp ecx, 32
		jb calculationShr
		je exitCalculation1

	exitCalculation1:
		
		mov esi, 0
		lea esi, numberOnes
		mov [esi], al
        mov ecx, 0
		mov eax, 0
		lea ebx, number
		mov ebx, [ebx]


	calculationShl:

		clc
		inc ecx
		shl ebx, 1     
		jc  onesIncrem2
		jnc zeroChooseExit2

	onesIncrem2:
	
		inc eax
		clc
		cld
		cmp ecx, 32
		jb calculationShl
		je exitCalculation2

	zeroChooseExit2:
		
		clc
		cld
		cmp ecx, 32
		jb calculationShl
		je exitCalculation2
			
	exitCalculation2:

		mov esi, 0
		lea esi, numberOnes2
		mov[esi], al

		popad
	}

	numberZeroes = 32 - (int)numberOnes;
	numberZeroes2 = 32 - (int)numberOnes2;

	std::cout << "Number " << "11011110111110111100110111101111" << "\nNumber of zeroes: " 
		      << numberZeroes << "\nNumber of ones: " << (int)numberOnes;
	std::cout << "\nSecond way:" << "\nNumber of zeroes: "
		<< numberZeroes2 << "\nNumber of ones: " << (int)numberOnes2;

	return 0;
}