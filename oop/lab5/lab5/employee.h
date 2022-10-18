#pragma once
#include "abstr_emp.h"
class employee : public abstr_emp
{
public:
    employee()  {};
    employee(const std::string& fn, const std::string& ln, const std::string& j)  {};
    virtual void ShowAll() const;
    virtual void SetAll();
};