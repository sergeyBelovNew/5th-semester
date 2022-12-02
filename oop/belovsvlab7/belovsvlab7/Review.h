#pragma once
#include <iostream>
#include <cstring>

class Review
{
public:
	Review();
	Review(std::string name, int rating);
	~Review();
	void printDate();
	bool compareRating(Review rev1, Review rev2);
	std::string getName() { return name; }
	int getRating() { return rating; }

private:
	std::string name;
	int rating;
};

