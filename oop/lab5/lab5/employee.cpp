#include <iostream>
#include <string>
#include "abstr_emp.h"
#include "employee.h"
#include "manager.h"
#include "fink.h"
#include "highfink.h"

void employee::ShowAll() const
{
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}
