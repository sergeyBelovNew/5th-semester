#pragma once
#include "abstr_emp.h"
class fink : virtual public   abstr_emp
{
public:
    fink();
    fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo);
    fink(const abstr_emp& source, const std::string& rpo) ;
    fink(const fink& source);
    virtual void ShowAll() const;
    virtual void SetAll();

protected:
    const std::string ReportsTo() const
    {
        return reportsto;
    }
    std::string& ReportsTo()
    {
        return reportsto;
    }

private:
    std::string reportsto;
};

