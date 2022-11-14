#include "TvException.h"

TvIsOffException::TvIsOffException() : std::logic_error("") {}

const char* TvIsOffException::what() const noexcept {
    return "exception tv";
}
