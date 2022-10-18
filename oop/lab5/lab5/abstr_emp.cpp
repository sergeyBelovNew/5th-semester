#include <iostream>
#include <string>
#include <sstream>
#include "abstr_emp.h"

abstr_emp::abstr_emp()
{
	this->fname = "";
	this->job = "";
	this->lname = "";
}

abstr_emp::abstr_emp(const std::string& fn, const std::string& ln, const std::string& j)
{
	this->fname = fn;
	this->lname = ln;
	this->job = j;
}


void abstr_emp::ShowAll() const
{
	std::cout<<"\n"<< this->fname << "\n" << this->job << "\n"<< this->lname;
}

void abstr_emp::SetAll()
{
	this->fname = "Unnamed";
	this->lname = "Unnamed";
	this->job = "Unnamed";
}

std::ostream& operator<<(std::ostream& os, const abstr_emp& e)
{
	os << "fname: " << e.fname << "\n" << "lname: " << e.lname << "\n" << "job: " << e.job << "\n";
	return os;
}
