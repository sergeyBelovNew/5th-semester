#pragma once
#include "abstr_emp.h"
class manager : virtual public abstr_emp
{
    public:
        manager();
        manager(const std::string& fn, const std::string& ln, const std::string& j, int ico = 0);
        manager(const abstr_emp& �, int ico);
        manager(const manager& m);
        virtual void ShowAll() const;
        virtual void SetAll();

    protected:
        int InChargeOf() const { return inchargeof; }
        int& InChargeOf() { return inchargeof; }

    private:
        int inchargeof; 
   
};

