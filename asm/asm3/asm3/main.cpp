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
<<<<<<< HEAD
		xor esi, esi
		lea esi, data
=======

		xor esi, esi
		lea esi, data

>>>>>>> ac04179c5fe5d788412b913e535af28aa7e30ea3
		cmp bh, 127
		je exitCycle
		cmp bl, 128
		je exitCycle
		cmp ch, 128
		je exitCycle
		cmp cl, 128
		je exitCycle

		push ecx
		call random
<<<<<<< HEAD
		pop ecx
	    mov [edi], ax
		
=======
		movzx eax, ax
		pop ecx
	    mov [edi], ax
>>>>>>> ac04179c5fe5d788412b913e535af28aa7e30ea3

		test  eax, 1
		jnz   odd			//Нечетное, переход на метку Odd
		jz    evenNum		//Четное, переход на метку Even


	evenNum:
<<<<<<< HEAD
		adc bh, 1
		mov eax, 2 //для вычисления сдвига
=======
		
		cmp [esi], 0
		je firstEven

		adc bh, 1
		mov eax, 2          //для вычисления сдвига
>>>>>>> ac04179c5fe5d788412b913e535af28aa7e30ea3
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
<<<<<<< HEAD
		lea esi, data
		adc bl, 1
		mov eax, 2 //для вычисления сдвига
=======

		adc bl, 1
		mov eax, 2          //для вычисления сдвига
>>>>>>> ac04179c5fe5d788412b913e535af28aa7e30ea3
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
<<<<<<< HEAD
		xor esi, esi
		lea esi, data
=======

		xor esi, esi
		lea esi, data

>>>>>>> ac04179c5fe5d788412b913e535af28aa7e30ea3
		adc ch, 1
		mov eax, 2
		mul ch
		adc esi, eax

		mov eax, [edi]
		mov[esi + 510], eax

		jmp loopStart

	less10000:
<<<<<<< HEAD
		xor esi, esi 
		lea esi, data
=======
		
		xor esi, esi
		lea esi, data

>>>>>>> ac04179c5fe5d788412b913e535af28aa7e30ea3
		adc cl, 1
		mov eax, 2
		mul cl
		adc esi, eax

		mov eax, [edi]
		mov[esi + 766], eax

		jmp loopStart

	firstEven:

		mov eax, [edi]
		mov[esi], eax

		cmp eax, 50000
		jae more50000
		cmp eax, 10000
		jbe less10000
		jmp loopStart
	

	exitCycle:

		popad
	}

<<<<<<< HEAD
	cout << "Array\n";
=======
	cout << "Array(0 - 127 even, 127 - 255 odd, 255 - 383 more than 50000, 383 - 511 \nless than 10000):";
>>>>>>> ac04179c5fe5d788412b913e535af28aa7e30ea3
	for (int i = 0; i < 512; i++) {
		if (i % 128 == 0)
			cout << "\n\n\n";
		cout << data[i]<<"  ";
<<<<<<< HEAD
		if (i % 128 == 0)
			cout << "\n\n\n";
=======
>>>>>>> ac04179c5fe5d788412b913e535af28aa7e30ea3
	}
	return 0;
}