#pragma once

class employee : public abstr_emp
{
public:
    employee()  {};
    employee(const std::string& fn, const std::string& ln, const std::string& j) : abstr_emp(fn, ln, j) {};
    virtual void ShowAll() const;
    virtual void SetAll();
};