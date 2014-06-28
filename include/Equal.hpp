#ifndef COMPANIES101_EQUAL_HPP
#define COMPANIES101_EQUAL_HPP
namespace companies101 {
class Company;
class Department;
class Employee;

bool operator==(const Company   & lhs, const Company   & rhs);
bool operator==(const Department& lhs, const Department& rhs);
bool operator==(const Employee  & lhs, const Employee  & rhs);

}
#endif

