#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Review.h"

using namespace std;

void printReviewsByRating(vector<shared_ptr<Review>> vector);
void printReviewsAlphabatically(vector<shared_ptr<Review>> vector);
void printReviews(const vector<shared_ptr<Review>>& vector);

int main() {
    auto reviews = vector<shared_ptr<Review>>();

    auto review_1 = shared_ptr<Review>(new Review(L"Game1", 50));
    auto review_2 = shared_ptr<Review>(new Review(L"Game2", 30));
    auto review_3 = shared_ptr<Review>(new Review(L"Game3", 100));
    auto review_4 = shared_ptr<Review>(new Review(L"Game4", 25));

    reviews.push_back(review_1);
    reviews.push_back(review_2);
    reviews.push_back(review_3);
    reviews.push_back(review_4);

    cout << "Printing alphabetically: " << endl;
    printReviewsAlphabatically(reviews);
    cout << endl;

    cout << "Reviews without any sort: " << endl;
    printReviews(reviews);
    cout << endl;

    cout << "Printing by rating: " << endl;
    printReviewsByRating(reviews);
    cout << endl;

    return EXIT_SUCCESS;
}

void printReviewsByRating(vector<shared_ptr<Review>> vector) {
    std::sort(vector.begin(),
        vector.end(),
        [](shared_ptr<Review> reviewPtr_1, shared_ptr<Review> reviewPtr_2) {
            return reviewPtr_1.get()->getRating() > reviewPtr_2.get()->getRating();
        });

    printReviews(vector);
}

void printReviewsAlphabatically(vector<shared_ptr<Review>> vector) {
    sort(vector.begin(),
        vector.end(),
        [](shared_ptr<Review> reviewPtr_1, shared_ptr<Review> reviewPtr_2) {
            return reviewPtr_1.get()->getText().compare(reviewPtr_2.get()->getText()) < 0;
        });

    printReviews(vector);
}

void printReviews(const std::vector<std::shared_ptr<Review>>& vector) {
    for (auto review : vector)
       wcout << review.get()->toString() << endl;
}
