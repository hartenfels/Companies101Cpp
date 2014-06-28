#include "Department.hpp"
#include "MutateVisitor.hpp"
#include "Visitor.hpp"
namespace companies101 {

Department::Department(const std::string& n, const std::vector<Employee>& es,
                       const std::vector<Department>& ds) :
    name(n), employees(es), departments(ds) {}


const std::string&
Department::getName() const
{ return name; }

const std::vector<Employee>&
Department::getEmployees() const
{ return employees; }

const std::vector<Department>&
Department::getDepartments() const
{ return departments; }


void
Department::setName(const std::string& n)
{ name = n; }

void
Department::setEmployees(const std::vector<Employee>& es)
{ employees = es; }

void
Department::setDepartments(const std::vector<Department>& ds)
{ departments = ds; }


std::vector<Employee>&
Department::getMutableEmployees()
{ return employees; }

std::vector<Department>&
Department::getMutableDepartments()
{ return departments; }


void
Department::accept(const Visitor& visitor) const
{
    visitor.enter(*this);
    for (const Employee  & e : getEmployees  ()) e.accept(visitor);
    for (const Department& d : getDepartments()) d.accept(visitor);
    visitor.exit (*this);
}

void
Department::accept(const MutateVisitor& visitor)
{
    visitor.enter(*this);
    for (Employee  & e : getMutableEmployees  ()) e.accept(visitor);
    for (Department& d : getMutableDepartments()) d.accept(visitor);
    visitor.exit (*this);
}

}

