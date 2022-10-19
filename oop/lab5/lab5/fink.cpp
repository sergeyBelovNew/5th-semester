
#include "abstr_emp.h"
#include "fink.h"

fink::fink() 
{
	this->reportsto = "";
}

fink::fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo) : abstr_emp(fn, ln, j) {
	this->reportsto = rpo;
}

fink::fink(const abstr_emp& source, const std::string& rpo) : abstr_emp(source)
{
	this->reportsto = rpo;
}

fink::fink(const fink& source) : abstr_emp(source)
{
	this->reportsto = source.reportsto;
}

void fink::ShowAll() const 
{
	abstr_emp::ShowAll();
	std::cout << "\n" << reportsto;
}

void fink::SetAll()
{
	this->reportsto = "unnamed";
}
