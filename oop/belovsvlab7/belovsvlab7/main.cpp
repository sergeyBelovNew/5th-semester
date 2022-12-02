#include <iostream>
#include <vector>
#include <cstring>
#include "Review.h"
#include <algorithm>

void runTask();
void sortRating(std::vector <std::shared_ptr <Review>> vectors);
void sortName(std::vector <std::shared_ptr <Review>> vectors);
void printVectors(std::vector <std::shared_ptr <Review>> vectors);


int main() {
	runTask();
}

void runTask() {
	std::vector <std::shared_ptr <Review>> vectors;
	auto vector1 = std::shared_ptr<Review>(new Review("Game1", 125));
	auto vector2 = std::shared_ptr<Review>(new Review("Game2", 600));
	auto vector3 = std::shared_ptr<Review>(new Review("Game3", 80));
	auto vector4 = std::shared_ptr<Review>(new Review("Game4", 90));

	vectors.push_back(vector1);
	vectors.push_back(vector2);
	vectors.push_back(vector3);
	vectors.push_back(vector4);
	printVectors(vectors);
	sortRating(vectors);
	sortName(vectors);
}

void printVectors(std::vector <std::shared_ptr <Review>> vectors) {
	std::cout << "Vectors:\n";
	for (size_t i = 0; i < vectors.capacity(); i++)
		vectors[i].get()->printDate();
}

void sortRating(std::vector <std::shared_ptr <Review>> vectors) {

	for (size_t i = 0; i < vectors.capacity(); i++)
		std::sort(vectors.begin(), vectors.end(), [](std::shared_ptr<Review> ptrReview1, std::shared_ptr<Review> ptrReview2) {
		return ptrReview1.get()->getRating() > ptrReview2.get()->getRating();
			});
	
	std::cout << "Sorted by rating:\n";
	printVectors(vectors);
}

void sortName(std::vector <std::shared_ptr <Review>> vectors) {
	for (size_t i = 0; i < vectors.capacity(); i++)
		std::sort(vectors.begin(), vectors.end(), [](std::shared_ptr<Review> ptrReview1, std::shared_ptr<Review> ptrReview2) {
		return ptrReview1.get()->getName() > ptrReview2.get()->getName();
			});

	std::cout << "Sorted by name:\n";
	printVectors(vectors);
}