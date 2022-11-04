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
	unsigned short int data[512] = {0};
	int tempRandom = 0;
	

	__asm {
		pushad
	
	    mov ebx, 0
	    mov ecx, 0
		lea edi, tempRandom

	loopStart:
		xor esi, esi
		lea esi, data
		cmp bh, 128
		je exitCycle
		cmp bl, 128
		je exitCycle
		cmp ch, 128
		je exitCycle
		cmp cl, 128
		je exitCycle

		push ecx
		call random
		pop ecx
	    mov [edi], ax
		

		test  eax, 1
		jnz   odd			//Ќечетное, переход на метку Odd
		jz    evenNum		//„етное, переход на метку Even


	evenNum:
		adc bh, 1
		mov eax, 2 //дл€ вычислени€ сдвига
		mul bh
		adc esi, eax
		mov eax, [edi]
		mov [esi], eax

		cmp eax, 50000
		jae more50000
		cmp eax, 10000
		jbe less10000
		jmp loopStart

	odd:
		lea esi, data
		adc bl, 1
		mov eax, 2 //дл€ вычислени€ сдвига
		mul bl
		adc esi, eax
		mov eax, [edi]
		mov[esi + 254], eax

		cmp eax, 50000
		jae more50000
		cmp eax, 10000
		jbe less10000
		jmp loopStart

	more50000:
		xor esi, esi
		lea esi, data
		adc ch, 1
		mov eax, 2
		mul ch
		adc esi, eax

		mov eax, [edi]
		mov[esi + 510], eax

		jmp loopStart

	less10000:
		xor esi, esi 
		lea esi, data
		adc cl, 1
		mov eax, 2
		mul cl
		adc esi, eax

		mov eax, [edi]
		mov[esi + 766], eax

		jmp loopStart

	exitCycle:

		popad
	}

	cout << "Array\n";
	for (int i = 0; i < 512; i++) {
		cout << data[i]<<"  ";
		if (i % 128 == 0)
			cout << "\n\n\n";
	}
	return 0;
}