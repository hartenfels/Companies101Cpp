#ifndef COMPANIES101_TOTAL_HPP
#define COMPANIES101_TOTAL_HPP
#include "Department.hpp"
#include "Employee.hpp"
#include "FlatCompany.hpp"
#include "NestedCompany.hpp"
namespace companies101
{

double total(const FlatCompany  & company);

double total(const NestedCompany& company);

double total(const Department   & department);

double total(const Employee     & employee);

}
#endif

