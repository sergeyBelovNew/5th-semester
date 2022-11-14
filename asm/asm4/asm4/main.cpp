#include <iostream>
#include <conio.h>
#include <iomanip>
#include <sstream>

int transferDouble(int classicNumber) {
	int newNumber = 0;
	int k = 1;
	while (classicNumber) 
	{
		newNumber += classicNumber % 2 * k; 
		
		classicNumber /= 2;
		k *= 10; 
	}
	return newNumber;
}

int main() {

	uint32_t number = 0xDEFBCDEF;

	unsigned char numberOnes = 0;
	int numberZeroes = 0;
	unsigned char numberOnes2 = 0;
	int numberZeroes2 = 0;
	int numberPairOnes = 0;
	int numberPairZeroes = 0;
	unsigned char invertionByte = 0;

	unsigned char temp1 = 0;
	unsigned char temp2 = 0;

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
			mov[esi], al
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

		    mov ecx, 0
			lea esi, numberOnes2
			mov[esi], al
			mov esi, 0
			mov edi, 0
			
			// 3 task 1101 1110 1111 1011 1100 1101 1110 1111
		calculationPair:
		    
		    
		    cmp ecx, 32
			je exitCalculationPair

			bt ebx, ecx
			inc ecx
			jc  firstOne
			jnc firstZero

		firstOne:

		    bt ebx, ecx
			jc  incPairOne
			jmp calculationPair

		firstZero:

		    bt ebx, ecx
			jnc incPairZero
			jmp calculationPair

		incPairOne:
			inc ecx
			inc esi
		    jmp  calculationPair

		incPairZero:
			
			inc ecx
		    inc edi
			jmp  calculationPair

		exitCalculationPair:

		    lea edx, numberPairOnes
			mov[edx], esi
			lea edx, numberPairZeroes
			mov[edx], edi

			//task4 (bad way, without buff mas)

			mov al, bl
			mov ecx, 1
			neg ecx
			mov edx, 8

			//1110 1111
		startExchangeFirstHalf:

		    inc cx
			dec dl
			cmp dl, 3
			je exitExchange

			bt bl, dl
			jc byteOne
			jnc byteZero

		byteOne:

		    btr bl, dl
			bt bl, cl
			jnc changeBit
			jmp startExchangeFirstHalf

		byteZero:

		    bt bl, cl
			jc far changeBit
			jmp startExchangeFirstHalf

		changeBit:

		    btc bl, cl
			jmp startExchangeFirstHalf

		exitExchange:

		    lea esi, temp1
			mov[esi], bl
			mov ecx, 1
			neg ecx
			mov edx, 8

		startExchangeSecondHalf:

		    inc cx
			dec dl
			cld
			cmp cl, 4
			je near finalExit1

			bt al, cl
			jc byteOne2
			jnc byteZero2

		byteOne2:

		    btr al, cl
			bt al, dl
			jnc changeBit2
			jmp startExchangeSecondHalf

		byteZero2:

		    bt al, dl
			jc changeBit2
			jmp startExchangeSecondHalf

		changeBit2:

		    btc al, dl
			jmp startExchangeSecondHalf

		finalExit1:

		    lea edi, temp2
			mov[edi], al
			mov al, [edi]
			mov bl, [esi]
			adc bl, al
			lea esi, invertionByte
			mov[esi], bl

			popad
	}

	numberZeroes = 32 - (int)numberOnes;
	numberZeroes2 = 32 - (int)numberOnes2;
	std::cout << "Number " << "1101 1110 1111 1011 1100 1101 1110 1111" << "\nNumber of zeroes: "
		<< numberZeroes << "\nNumber of ones: " << (int)numberOnes;
	std::cout << "\nSecond way:" << "\nNumber of zeroes: "
		<< numberZeroes2 << "\nNumber of ones: " << (int)numberOnes2;
	std::cout << "\nNumber of pairs: " << "\nZeroes: " << numberPairZeroes << "\nOnes: " << numberPairOnes;
	std::cout << "\nInvertion: " << "\nOriginal: 1110 1111:" << "\nInvertion: " << transferDouble((int)invertionByte);
	std::cout << "\nFirst half byte: " << transferDouble((int)temp1) << "\nSecond half byte: " << transferDouble((int)temp2);
	return 0;
}