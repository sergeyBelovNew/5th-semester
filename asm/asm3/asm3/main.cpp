#include<iostream>
#include<conio.h>
#include<iomanip>
#include<sstream>
#include<random>
using namespace std;


const uint16_t MIN = 0x0;
const uint16_t MAX = 0xFFFF;

uint16_t random() {
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<uint16_t> uni(MIN, MAX);

	return uni(rng);
}

int main() {
	unsigned short int data[512];

	__asm {
		pushad
		mov ebx, 0
		mov ecx, 0
		mov edx, 0
		mov edi, 0

		lea esi, data

	loopStart:
		cmp ebx, 128
		je exitCycle
		cmp ecx, 128
		je exitCycle
		cmp edx, 128
		je exitCycle
		cmp edi, 128
		je exitCycle

		push ebx
		push ecx
		push edx
		push edi
		call random
		pop edi
		pop edx
		pop ecx
		pop ebx

		test eax,1
		jae evenNum
		jbe odd

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
		cout << data[i]<<"  ";
		if (i % 64 == 0)
			cout << "\n";
	}
	return 0;
}