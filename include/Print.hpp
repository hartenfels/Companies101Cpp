#ifndef COMPANIES101_PRINT_HPP
#define COMPANIES101_PRINT_HPP
#include "Company.hpp"
#include "Department.hpp"
#include "Employee.hpp"
namespace companies101
{

void print(const Company   & company,    const unsigned int& indentation = 0);

void print(const Department& department, const unsigned int& indentation = 0);

void print(const Employee  & employee,   const unsigned int& indentation = 0);

}
#endif

