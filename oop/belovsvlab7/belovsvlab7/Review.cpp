#include "Review.h"

Review::Review()
{
		name = "Default";
		rating = 0;
}

Review::Review(std::string name, int rating)
{
	this->name = name;
	this->rating = rating;
}

Review::~Review(){
}

void Review::printDate()
{
	std::cout << "Name: " << name << " Rating: " << rating << "\n";
}


bool  Review::compareRating(Review rev1, Review rev2)
{
	return ( rev1.getRating() < rev2.getRating());
}
