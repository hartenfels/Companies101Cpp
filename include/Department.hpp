#ifndef COMPANIES101_DEPARTMENT_HPP
#define COMPANIES101_DEPARTMENT_HPP
#include "Employee.hpp"
#include <string>
#include <vector>
namespace companies101 {
class Visitor;
class MutateVisitor;

class Department {
public:
    Department(const std::string            & name        = "",
               const std::vector<Employee>  & employees   = {},
               const std::vector<Department>& departments = {});

    const std::string            & getName       () const;
    const std::vector<Employee>  & getEmployees  () const;
    const std::vector<Department>& getDepartments() const;

    void setName       (const std::string            & name);
    void setEmployees  (const std::vector<Employee>  & employees);
    void setDepartments(const std::vector<Department>& departments);

    std::vector<Employee>  & getMutableEmployees  ();
    std::vector<Department>& getMutableDepartments();

    void accept(const Visitor      & visitor) const;
    void accept(const MutateVisitor& visitor);

private:
    std::string             name;
    std::vector<Employee>   employees;
    std::vector<Department> departments;
};

}
#endif

