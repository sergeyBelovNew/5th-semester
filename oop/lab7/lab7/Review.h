#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <sstream>

class Review {

public:
    std::wstring toString() const;

    void print() const;

    Review(const std::wstring& text = L"", const int8_t rating = 0);
    ~Review();

    std::wstring getText() const;
    int8_t getRating() const;

private:
    std::wstring text;
    unsigned char rating;
};


