#include "Employee.hpp"
namespace companies101
{ using namespace std;

Employee::Employee(const string& n, const string& a, const double& s) :
    name(n), address(a), salary(s) {}

Employee::~Employee() {}


const std::string&
Employee::getName() const
{
    return name;
}

const std::string&
Employee::getAddress() const
{
    return address;
}

const double&
Employee::getSalary() const
{
    return salary;
}


void
Employee::setName(const string& n)
{
    name = n;
}

void
Employee::setAddress(const string& a)
{
    address = a;
}

void
Employee::setSalary(const double& s)
{
    salary = s;
}

}

