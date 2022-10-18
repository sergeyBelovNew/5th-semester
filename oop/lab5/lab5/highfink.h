#pragma once
class highfink : public manager, public fink 
{
public:
    highfink();
    highfink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo, int ico);
    highfink(const abstr_emp& source, const std::string& rpo, int ico);
    highfink(const fink& f, int ico);
    highfink(const manager& m, const std::string& rpo);
    highfink(const highfink& h);
    virtual void ShowAll() const;
    virtual void SetAll();
};
