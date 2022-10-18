#include <iostream>
#include <string>
#include "abstr_emp.h"
#include "employee.h"
#include "manager.h"
#include "fink.h"
#include "highfink.h"

int main() {
    highfink hf = highfink("fn", "ln", "j", "rpo", 12);
    hf.ShowAll();
    hf.SetAll();
    hf.ShowAll();
    return 0;
}

    
