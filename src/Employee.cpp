#include "Employee.hpp"
#include "MutateVisitor.hpp"
#include "Visitor.hpp"
namespace companies101 {

Employee::Employee(const std::string& n, const std::string& a, const double& s) :
    name(n), address(a), salary(s) {}


const std::string&
Employee::getName() const
{ return name; }

const std::string&
Employee::getAddress() const
{ return address; }

const double&
Employee::getSalary() const
{ return salary; }


void
Employee::setName(const std::string& n)
{ name = n; }

void
Employee::setAddress(const std::string& a)
{ address = a; }

void
Employee::setSalary(const double& s)
{ salary = s; }


void
Employee::accept(const Visitor& visitor) const
{
    visitor.enter(*this);
    visitor.exit (*this);
}

void
Employee::accept(const MutateVisitor& visitor)
{
    visitor.enter(*this);
    visitor.exit (*this);
}

}

