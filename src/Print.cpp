#include "Print.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
namespace companies101
{ using namespace std;

static inline void
printIndent(const unsigned int& in)
{
    fill_n(ostream_iterator<char>(cout), in, '\t');
}

void
print(const Company& c, const unsigned int& in)
{
    const auto& ds = c.getDepartments();

    printIndent(in);
    cout << c.getName() << " (" << ds.size() << " Departments)\n";

    for (const auto& d : ds) print(d, in + 1);
}

void
print(const Department& d, const unsigned int& in)
{
    const auto& es = d.getEmployees  ();
    const auto& ds = d.getDepartments();

    printIndent(in);
    cout << d.getName() << " (" << es.size() << " Employees, "
         << ds.size() << " Departments)\n";

    for (const auto& e : es) print(e, in + 1);
    for (const auto& d : ds) print(d, in + 1);
}

void
print(const Employee& e, const unsigned int& in)
{
    printIndent(in);
    cout << e.getName() << ", " << e.getAddress() << ", " << e.getSalary() << '\n';
}

}

