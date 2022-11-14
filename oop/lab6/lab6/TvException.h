#pragma once
#include <stdexcept>

class TvIsOffException: public std::logic_error {
public:
    TvIsOffException();
    virtual const char* what() const noexcept override;
};

