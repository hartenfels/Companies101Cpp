#ifndef COMPANIES101_COMPANY_HPP
#define COMPANIES101_COMPANY_HPP
#include "Department.hpp"
#include <vector>
namespace companies101
{

class Company
{
public:
    Company(const std::string            & name        = "",
            const std::vector<Department>& departments = {});
    virtual ~Company();

    virtual const std::string& getName() const;
    virtual const std::vector<Department>& getDepartments() const;

    virtual std::vector<Department>& getMutableDepartments();

    virtual void setName(const std::string& name);
    virtual void setDepartments(const std::vector<Department>& departments);

private:
    std::string name;
    std::vector<Department> departments;
};

}
#endif

