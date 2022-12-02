#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

std::vector<std::string> inputVector(std::vector<std::string> vector);
void sortVector(std::vector<std::string>& vector);
void printVector(std::vector<std::string>& vector);
void runTask();

int main() {
    runTask();
    return 0;
}

void  runTask() {
    auto mattFriends = std::vector<std::string>();
    auto patFriends = std::vector<std::string>();
    auto uniteFriends = std::vector<std::string>();

    std::cout << "Friends of Matt:\n";
    mattFriends = inputVector(mattFriends);
    std::cout << "Friends of Pit:\n";
    patFriends = inputVector(patFriends);
    std::cout << "\n\nFriends of Matt:\n";
    sortVector(mattFriends);
    std::cout << "\n\nFriends of Pit:\n";
    sortVector(patFriends);

    uniteFriends.insert(uniteFriends.end(), patFriends.begin(), patFriends.end());
    uniteFriends.insert(uniteFriends.end(), mattFriends.begin(), mattFriends.end());
    std::cout << "\n\nFriends of Matt and Pit:\n";
    printVector(uniteFriends);
    uniteFriends.erase(std::unique(uniteFriends.begin(), uniteFriends.end()), uniteFriends.end());
}

std::vector<std::string> inputVector(std::vector<std::string> vector) {

    std::cout << "Input vector(exit - break))\n";
    std::string input;
    std::cin >> input;
    while (input.compare("exit")) {
        vector.push_back(input);
        std::cin >> input;
    }
    return vector;
}

void sortVector(std::vector<std::string>& vector) {
    std::cout << "Sorted\n";
    std::sort(vector.begin(),
        vector.end(),
        [](std::string name_1, std::string name_2) {
            return name_1.compare(name_2) < 0;
        });
    printVector(vector);
}

void printVector(std::vector<std::string>& vector) {
    for (auto name : vector)
        std::cout << name << std::endl;
}