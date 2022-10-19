
#include "abstr_emp.h"
#include "manager.h"
#include "fink.h"
#include "highfink.h"

highfink::highfink() : abstr_emp() {
    ReportsTo() = "";
    InChargeOf() = 0;
}

highfink::highfink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo, int ico) : abstr_emp(fn, ln, j) {
    ReportsTo() = rpo;
    InChargeOf() = 0;
}

highfink::highfink(const abstr_emp& e, const std::string& rpo, int ico) : abstr_emp(e) {
    ReportsTo() = rpo;
    InChargeOf() = ico;
}

highfink::highfink(const fink& f, int ico) : fink(f) {
    InChargeOf() = ico;
}

highfink::highfink(const manager& m, const std::string& rpo) : manager(m) {
    ReportsTo() = rpo;
}

highfink::highfink(const highfink& h) : abstr_emp(h) {
    InChargeOf() = h.InChargeOf();
    ReportsTo() =  h.ReportsTo();
}

void highfink::ShowAll() const {
    abstr_emp::ShowAll();
    std::cout << "reportsTo: " << ReportsTo() << "\n";
    std::cout << "inchargeOf: " << InChargeOf() << "\n";
}

void highfink::SetAll() {
    manager::SetAll();
    fink::SetAll();
}