#include<iostream>
#include<conio.h>
#include<iomanip>
#include<sstream>

using namespace std;

const int DataSize = 144;

std::string IntToHex(int n) {
	std::stringstream ss;
	ss << std::hex << n;
	return ss.str();
}

int main() {
	unsigned char Memo[DataSize];

	for (int i = 0; i++; i < DataSize) {
		Memo[i] = NULL;
	}
	//(c * 2 - d + 23)/( a / 4 - 1)
	long long a = 5'678'901'234; //5678901234; // 1 527D 27F2
	long long c = 7'890'123'456; //7890123456; // 1 D649 BAC0
	long long d = 8'901'234'567; //8901234567; // 2 128E 0F87

	long long result = 0;

	__asm {
		pushad
		// c * 2 - d + 23

		// c * 2
		mov eax, 890123456
		mov ebx, 7
		mov ecx, 2
		mul ecx
		imul ebx, ecx
		mov edx, ebx

		// c * 2 - d

		mov esi, 8
		mov ecx, 901234567
		sbb eax, ecx
		sbb edx, esi

		// c * 2 - d + 23

		add  eax, 23
		push eax
		push edx

		// a / 400 - 1
		// a / 400

		mov eax, 678901234
		mov edx, 000000005
		mov ecx, 400
		div ecx

		// a / 400 - 1

		sbb eax, 1

		// (c * 2 - d + 23)/( a / 4 - 1)

		mov ebx, eax
		pop edx
		pop eax
		div ebx

		mov dword ptr[result], eax
		lea eax, Memo
		mov[eax], eax

		popad
	}

	for (int i = 0; i < DataSize; i++) {
		if ((i % 16) == 0) {
			cout << "\n" << setw(2) << i / 16 << ":";
		}
		else {
			cout << " " << setw(2) << IntToHex(Memo[i - 1]);
		}
	}
	std::cout << "\nResult: " << result;
	std::cout << "\nCaltulation answer:" << (7890123456 * 2 - 8901234567 + 23) / (5678901234 / 400 - 1);
	
	return 0;
}
