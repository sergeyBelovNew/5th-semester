#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "Human.h"


class FunctionsForHumans
{

public:
	string runFstream(vector<shared_ptr<Human>> vectors);
	shared_ptr<Human> static searchAge(vector<shared_ptr<Human>> vectors, int age);
    void insert(vector<shared_ptr<Human>>&vectors);
	void static printVectors(vector <shared_ptr <Human>> vectors);
	void static sortAge(vector <shared_ptr <Human>> vectors);
	void static sortName(vector <shared_ptr <Human>> vectors);
	void rewriteByAge(vector <shared_ptr <Human>>&vectors, int age);
	void static const printHumansInOneCity(vector <shared_ptr <Human>> vectors, string city);

private:
	string path = "new.txt";

};

