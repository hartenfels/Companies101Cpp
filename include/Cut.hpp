#ifndef COMPANIES101_CUT_HPP
#define COMPANIES101_CUT_HPP
#include "Department.hpp"
#include "Employee.hpp"
#include "FlatCompany.hpp"
#include "NestedCompany.hpp"
namespace companies101
{

void cut(FlatCompany  & company);

void cut(NestedCompany& company);

void cut(Department   & department);

void cut(Employee     & employee);

}
#endif

