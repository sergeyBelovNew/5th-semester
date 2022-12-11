#include <iostream>
#include "FunctionsForHumans.h"

using namespace std;

void runTask();
vector <shared_ptr <Human>> fillVectors(vector <shared_ptr <Human>> vectors);

int main() {

	runTask();
	return 0;
}

void runTask() {

	int age;
	int choose;
	string city;
	vector <shared_ptr <Human>> humans;
	humans = fillVectors(humans);
	FunctionsForHumans* printer = new FunctionsForHumans;
	cout << "Choose function:\n1)Print\n2)Sort age\n3)Sort name\n";
	cout << "4)Search age\n5)Rewrite human(s) with current age\n6)Fstream\n7)Insert\n";
	cout << "8)Print humans in one city\n9)Exit\n";
	cin >> choose;
	while (choose != 9) {
		switch (choose) {
		case 1:
			printer->printVectors(humans);
			break;
		case 2:
			printer->sortAge(humans);
			break;
		case 3:
			printer->sortName(humans);
			break;
		case 4:
			cout << "Enter age: ";
			cin >> age;
			printer->searchAge(humans, age);
			break;
		case 5:
			cout << "Enter age: ";
			cin >> age;
			printer->rewriteByAge(humans, 20);
			break;
		case 6:
			printer->runFstream(humans);
			break;
		case 7:
			printer->insert(humans);
			break;
		case 8:
			cout << "Enter city: ";
			cin >> city;
			printer->printHumansInOneCity(humans, city);
			break;
		default:
			break;
		}
		cout << "Choose function again\n";
		cin >> choose;
	}

}

vector <shared_ptr <Human>> fillVectors(vector <shared_ptr <Human>> vectors) {

	auto vector1 = std::shared_ptr<Human>(new Human());
	auto vector2 = std::shared_ptr<Human>(new Human());
	auto vector3 = std::shared_ptr<Human>(new Human());
	auto vector4 = std::shared_ptr<Human>(new Human());
	vectors.push_back(vector1);
	vectors.push_back(vector2);
	vectors.push_back(vector3);
	vectors.push_back(vector4);
	return vectors;

}