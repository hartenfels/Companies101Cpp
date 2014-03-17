#ifndef COMPANIES101_NESTEDCOMPANY_HPP
#define COMPANIES101_NESTEDCOMPANY_HPP
#include "Company.hpp"
#include "Department.hpp"
#include <vector>
namespace companies101
{

class NestedCompany : public Company
{
public:
    NestedCompany(const std::string            & name        = "",
                  const std::vector<Department>& departments = {});
    virtual ~NestedCompany();

    virtual const std::vector<Department>& getDepartments() const;

    virtual std::vector<Department>& getMutableDepartments();

    virtual void setDepartments(const std::vector<Department>& departments);

private:
    std::vector<Department> departments;
};

}
#endif

