#ifndef COMPANIES101_FLATCOMPANY_HPP
#define COMPANIES101_FLATCOMPANY_HPP
#include "Company.hpp"
#include "Employee.hpp"
#include <vector>
namespace companies101
{

class FlatCompany : public Company
{
public:
    FlatCompany(const std::string          & name      = "",
                const std::vector<Employee>& employees = {});
    virtual ~FlatCompany();

    virtual const std::vector<Employee>& getEmployees() const;

    virtual std::vector<Employee>& getMutableEmployees();

    virtual void setEmployees(const std::vector<Employee>& employees);

private:
    std::vector<Employee> employees;
};

}
#endif

