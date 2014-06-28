#include "Company.hpp"
#include "MutateVisitor.hpp"
#include "Visitor.hpp"
namespace companies101 {

Company::Company(const std::string& n, const std::vector<Department>& ds) :
    name(n), departments(ds) {}


const std::string&
Company::getName() const
{ return name; }

const std::vector<Department>&
Company::getDepartments() const
{ return departments; }


void
Company::setName(const std::string& n)
{ name = n; }

void
Company::setDepartments(const std::vector<Department>& ds)
{ departments = ds; }


std::vector<Department>&
Company::getMutableDepartments()
{ return departments; }


void
Company::accept(const Visitor& visitor) const
{
    visitor.enter(*this);
    for (const Department& d : getDepartments()) d.accept(visitor);
    visitor.exit (*this);
}

void
Company::accept(const MutateVisitor& visitor)
{
    visitor.enter(*this);
    for (Department& d : getMutableDepartments()) d.accept(visitor);
    visitor.exit (*this);
}

}

