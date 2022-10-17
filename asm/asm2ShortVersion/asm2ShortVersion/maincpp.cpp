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
	long long a = 5'678'901'234; //5'678'901'234;
	long long b = 6'789'012'345; //6'789'012'345;
	long long c = 7'890'123'456; //7'890'123'456;
	long long d = 8'901'234'567; //8'901'234'567; 
	long long e = 9'012'345'678; //9'012'345'678;
	long long f = 10'123'456'789; //10'123'456'789;
	//short
	long long shortA = 5'678'901; //5'678'901;
	long long shortB = 6'789'012; //6'789'012;
	long long shortC = 7'890'123; //7'890'123;
	long long shortD = 8'901'234; //8'901'234; 
	long long shortE = 9'012'345; //9'012'345;
	long long shortF = 10'123'456; //10'123'456;
	long long result = 0;

	__asm {
		pushad
		// c * 2 - d + 23

		// c * 2
		mov eax, dword ptr[shortC]
		mov esi, 2
		mul esi

		// c * 2 - d
		mov esi, dword ptr[shortD]
		sub eax, esi
		//  c * 2 - d + 23
		add eax, 23
		mov ebx, eax
		// a / 4 - 1

		// a /  4
		mov eax, dword ptr[shortA]
		mov esi, 4
		div esi
		// a / 4 - 1
		dec eax
		xchg ebx, eax
		//(c * 2 - d + 23)/( a / 4 - 1)
		cdq
		div ebx
		mov dword ptr[result], eax
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

	_getch();
	return 0;
}
