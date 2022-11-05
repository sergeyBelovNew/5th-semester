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

		lea esi, data

	loopStart:
		cmp ebx, 128
		je exitCycle
		cmp bl, 128
		je exitCycle
		cmp ch, 128
		je exitCycle
		cmp cl, 128
		je exitCycle

		push ecx
		call random
		pop edi
		pop edx
		pop ecx
		pop ebx

		test eax,1
		jae evenNum
		jbe odd

		test  eax, 1
		jnz   odd			//Нечетное, переход на метку Odd
		jz    evenNum		//Четное, переход на метку Even


	evenNum:
		adc ebx, 1
		adc esi, 2
		mov [esi],eax

		cmp eax, 50000
		jae more50000
		cmp eax, 10000
		jbe less10000
		jmp loopStart

	odd:
		adc ecx, 1
		adc esi, 2
		mov[esi], eax

		adc bl, 1
		mov eax, 2          //для вычисления сдвига
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
		adc edx, 1
		jmp loopStart

	less10000:
		adc edi, 1
		jmp loopStart
	

	exitCycle:

		popad
	}
	cout << "Array\n";
	for (int i = 0; i < 512; i++) {
		if (i % 128 == 0)
			cout << "\n\n\n";
		cout << data[i]<<"  ";
		if (i % 64 == 0)
			cout << "\n";
	}
	return 0;
}