#include "Human.h"

Human::Human()
{
	
	name = "Sergey";
	surname = "Belov";
	secondName = "Vladimirovich";
	phoneNumber = "890435345";
	age = 20;
	currentCity = "Moscow";
	
}

void Human::showAll()
{
	cout << "Name: " << name << "\n";
	cout << "Surname: " << surname << "\n";
	cout << "Second name: " << secondName << "\n";
	cout << "Phone number: " << phoneNumber << "\n";
	cout << "Age: " << age << "\n";
	cout << "Current city: " << currentCity << "\n\n\n";
}

void Human::inputAll() {

	cout << "Enter date:\n";
	try {
		cout << "Enter name:";
		cin >> name;
		cout << "\nEnter surname:";
		cin >> surname;
		cout << "\nEnter secondname:";
		cin >> secondName;
		cout << "\nEnter phone number:";
		cin >> phoneNumber;
		cout << "\nEnter age:";
		cin >> age;
		if (age < 0)
			throw invalid_argument("received negative value");
		cout << "\nEnter current city:";
		cin >> currentCity;
	}
	catch (const invalid_argument& e) {
		throw e;
		cout << "Bad input";
	}
	catch (std::exception exepcion) {
		throw exepcion;
		cout << "Unknown exception";
	}

}

string Human::getName()
{
	return name;
}

string Human::getSurname()
{
	return surname;
}

string Human::getCity()
{
	return currentCity;
}

int Human::getAge()
{
	return age;
}
