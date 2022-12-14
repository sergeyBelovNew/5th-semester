#include<iostream>
#include<conio.h>
#include<iomanip>
#include<sstream>
#include<random>
#include<ctime>

using namespace std;
const uint16_t MIN = 0;
const uint16_t MAX = 65535;

uint16_t random() {
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<uint16_t> uni(MIN, MAX);

	return uni(rng);
}

int main() {
	unsigned short int data[512] = { 0 };
	int tempRandom = 0;


	__asm {
		pushad

		mov ebx, 0
		mov ecx, 0
		lea edi, tempRandom

		loopStart :

		    xor esi, esi
			lea esi, data

			cmp bh, 128
			jae exitCycle
			cmp bl, 128
			jae exitCycle
			cmp ch, 128
			jae exitCycle
			cmp cl, 128
			jae exitCycle

			push ecx
			call random
			movzx eax, ax
			pop ecx
			mov[edi], ax

			test  eax, 1
			jnz   odd
			jz    evenNum

		evenNum:

		    mov eax, 2
			mul bh
			adc esi, eax
			mov eax, [edi]
			mov[esi], ax
			adc bh, 1
			jmp moreLessCmp

		odd:

		    mov eax, 2
			mul bl
			adc esi, eax
			mov eax, [edi]
			mov[esi + 256], ax
			adc bl, 1
			jmp moreLessCmp
			
		moreLessCmp:
			
			cmp eax, 50000
			jae more50000
			cmp eax, 10000
			jbe less10000
			jmp loopStart

		more50000:

		    xor esi, esi
			lea esi, data

			mov eax, 2
			mul ch
			adc esi, eax
			mov eax, [edi]
			mov[esi + 512], ax
			adc ch, 1

			jmp loopStart

		less10000 :

		    xor esi, esi
			lea esi, data

			mov eax, 2
			mul cl
			adc esi, eax
			mov eax, [edi]
			mov[esi + 768], ax
			adc cl, 1

			jmp loopStart

		exitCycle :

		popad
	}

	cout << "Array(0 - 127 even, 127 - 255 odd, 255 - 383 more than 50000, 383 - 511 \nless than 10000):";
	for (int i = 0; i < 512; i++) {
		if (i % 128 == 0)
			cout << "\n\n\n";
		cout << data[i] << "  ";
	}
	return 0;
}