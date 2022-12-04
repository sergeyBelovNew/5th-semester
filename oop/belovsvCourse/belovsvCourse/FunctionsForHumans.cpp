#include "FunctionsForHumans.h"

void FunctionsForHumans::printVectors(vector <shared_ptr <Human>> vectors) {

	std::cout << "Humans:\n";
	for (size_t i = 0; i < vectors.capacity(); i++)
		vectors[i].get()->showAll();

}

void FunctionsForHumans::sortAge(vector <shared_ptr <Human>> vectors) {

	for (size_t i = 0; i < vectors.capacity(); i++)
		sort(vectors.begin(), vectors.end(), [](shared_ptr<Human> ptrReview1, shared_ptr<Human> ptrReview2) {
		return ptrReview1.get()->getAge() > ptrReview2.get()->getAge();
			});

	cout << "Sorted by age:\n";
	printVectors(vectors);

}

void FunctionsForHumans::sortName(vector <std::shared_ptr <Human>> vectors) {

	for (size_t i = 0; i < vectors.capacity(); i++)
		sort(vectors.begin(), vectors.end(), [](shared_ptr<Human> ptrReview1, shared_ptr<Human> ptrReview2) {
		return ptrReview1.get()->getName() > ptrReview2.get()->getName();
			});

	cout << "Sorted by name:\n";
	printVectors(vectors);

}

void const FunctionsForHumans::printHumansInOneCity(vector<shared_ptr<Human>> vectors, string city)
{
	for (size_t i = 0; i < vectors.capacity(); i++) 
		if (city.compare(vectors[i].get()->getCity()) == 0)
			vectors[i].get()->showAll();
	
}

shared_ptr<Human> FunctionsForHumans::searchAge(vector<shared_ptr<Human>> vectors, int age)
{

	std::cout << "Human:\n";
	for (size_t i = 0; i < vectors.capacity(); i++) {
		if (vectors[i].get()->getAge() == age)
			vectors[i].get()->showAll();
		return vectors[i];
	}

}

void FunctionsForHumans::insert(vector<shared_ptr<Human>>&vectors)
{
	auto vector = shared_ptr<Human>(new Human());
	vector.get()->inputAll();
	vectors.push_back(vector);

}

void FunctionsForHumans::rewriteByAge(vector<shared_ptr<Human>>&vectors, int age){
	
	for (int i = 0; i < vectors.size(); i++)
		if (vectors[i].get()->getAge() == age) {
			vectors[i].get()->inputAll();
			return;
		}
	
}

string FunctionsForHumans::runFstream(vector<shared_ptr<Human>> vectors) {

	fstream fs;
	string buff;

	fs.open(path, fstream::in | fstream::out | fstream::app);
	int choose;
	if (!fs.is_open())
		cout << "Error open";
	else
		cout << "Open";

	cout << "Choose option(1 - write, 2 - read):";
	cin >> choose;

	if (choose == 1)
		for (int i = 0; i < vectors.size(); i++)
			fs << vectors[i]->getName() << vectors[i] ->getSurname() << vectors[i] ->getAge();

	if (choose == 2)
		while(!fs.eof())
			for (int i = 0; i < vectors.size(); i++) {
				fs >> buff;
				cout << buff;
			}
	
	fs.close();
	return buff;
}