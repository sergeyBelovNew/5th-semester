#pragma once
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Human
{

public:
	Human();

	void showAll();
	void inputAll();
	string getName();
	string getSurname();
	string getCity();
	int getAge();

private:
	string name;
	string surname;
	string secondName;
	string phoneNumber;
	int age;
	string currentCity;

};

