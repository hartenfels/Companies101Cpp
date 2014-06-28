#include "Equal.hpp"
#include "Company.hpp"
#include "Department.hpp"
#include "Employee.hpp"
namespace companies101 {

bool
operator==(const Company& lhs, const Company& rhs)
{
    return lhs.getName       () == rhs.getName       ()
        && lhs.getDepartments() == rhs.getDepartments();
}

bool
operator==(const Department& lhs, const Department& rhs)
{
    return lhs.getName       () == rhs.getName       ()
        && lhs.getEmployees  () == rhs.getEmployees  ()
        && lhs.getDepartments() == rhs.getDepartments();
}

bool
operator==(const Employee& lhs, const Employee& rhs)
{
    return lhs.getName   () == rhs.getName   ()
        && lhs.getAddress() == rhs.getAddress()
        && lhs.getSalary () == rhs.getSalary ();
}

}

