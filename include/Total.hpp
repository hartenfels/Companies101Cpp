#ifndef COMPANIES101_TOTAL_HPP
#define COMPANIES101_TOTAL_HPP
#include "Company.hpp"
#include "Department.hpp"
#include "Employee.hpp"
namespace companies101
{

double total(const Company   & company);

double total(const Department& department);

double total(const Employee  & employee);

}
#endif

