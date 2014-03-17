#ifndef COMPANIES101_DEPARTMENT_HPP
#define COMPANIES101_DEPARTMENT_HPP
#include "Employee.hpp"
#include <string>
#include <vector>
namespace companies101
{

class Department
{
public:
    Department(const std::string            & name        = "",
               const std::vector<Employee>  & employees   = {},
               const std::vector<Department>& departments = {});
    virtual ~Department();

    virtual const std::string            & getName       () const;
    virtual const std::vector<Employee>  & getEmployees  () const;
    virtual const std::vector<Department>& getDepartments() const;

    virtual std::vector<Employee>  & getMutableEmployees  ();
    virtual std::vector<Department>& getMutableDepartments();

    virtual void setName       (const std::string            & name);
    virtual void setEmployees  (const std::vector<Employee>  & employees);
    virtual void setDepartments(const std::vector<Department>& departments);

private:
    std::string             name;
    std::vector<Employee>   employees;
    std::vector<Department> departments;
};

}
#endif

