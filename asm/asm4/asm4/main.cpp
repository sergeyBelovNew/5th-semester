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
	int numberPairOnes = 0;
	int numberPairZeroes = 0;

	__asm {
		pushad
		
		mov ecx, 0
		mov eax, 0 //Counter of ones
		lea ebx, number
		mov ebx, [ebx]
		
	calculationRol:
		
		inc ecx
		rol ebx, 1     //shift of bits to 1 left(equel of div 2)
		jc  onesIncrem
		jnc  zeroChooseExit1

	onesIncrem:
		
		inc eax
		cmp ecx, 32
		jb calculationRol
		je exitCalculation1

	zeroChooseExit1:
		
		cmp ecx, 32
		jb calculationRol
		je exitCalculation1

	exitCalculation1:
		
		mov esi, 0
		lea esi, numberOnes
		mov [esi], al
        mov ecx, 0
		mov eax, 0

	calculationBt:

		bt ebx, ecx
		inc ecx
		jc  onesIncrem2
		jnc zeroChooseExit2

	onesIncrem2:
	
		inc eax
		cmp ecx, 32
		jb calculationBt
		je exitCalculation2

	zeroChooseExit2:
		
		cmp ecx, 32
		jb calculationBt
		je exitCalculation2
			
	exitCalculation2:

		mov esi, 0
		lea esi, numberOnes2
		mov[esi], al
		mov esi, 0
		mov edi, 0
		mov ecx, 0

    // 3 task
	calculationPair:
		
		cmp ecx, 32
		je exitCalculationPair

		bt ebx, ecx
		inc ecx
		jc  firstOne
		jnc firstZero

	firstOne:

		bt ebx, ecx
		inc ecx
		jc  incPairOne
		jmp calculationPair

	firstZero :

		bt ebx, ecx
		inc ecx
		jnc incPairZero
		jmp calculationPair

	incPairOne:
		
		inc esi
        jmp  calculationPair
			
	incPairZero:

		inc edi
        jmp  calculationPair

	exitCalculationPair:

		lea edx, numberPairOnes
		mov [edx], esi
		lea edx, numberPairZeroes
		mov [edx], edi

		mov ecx, 0
		mov esi, 0
		mov edi, 0
	//task4

		
		

		popad
	}

	numberZeroes = 32 - (int)numberOnes;
	numberZeroes2 = 32 - (int)numberOnes2;

	std::cout << "Number " << "1101 1110 1111 1011 1100 1101 1110 1111" << "\nNumber of zeroes: " 
		      << numberZeroes << "\nNumber of ones: " << (int)numberOnes;
	std::cout << "\nSecond way:" << "\nNumber of zeroes: "
		      << numberZeroes2 << "\nNumber of ones: " << (int)numberOnes2;
	std::cout << "\nNumber of pairs: " << "\nZeroes: " << numberPairZeroes << "\nOnes: " << numberPairOnes;

	return 0;
}