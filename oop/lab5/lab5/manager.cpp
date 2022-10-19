#include <iostream>
#include <string>
#include "abstr_emp.h"
#include "manager.h"

manager::manager() 
{
	this->inchargeof = 0;
}

manager::manager(const std::string& fn, const std::string& ln, const std::string& j, int ico) : abstr_emp(fn, ln, j) {
	this->inchargeof = ico;
}


manager::manager(const abstr_emp& source, int ico) : abstr_emp(source)
{
	this->inchargeof = ico;
}

manager::manager(const manager& source) : abstr_emp(source)
{
	this->inchargeof = source.inchargeof;
}

void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout <<"\n" << this->inchargeof;
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	this->inchargeof = 0;
}
