#ifndef COMPANIES101_EMPLOYEE_HPP
#define COMPANIES101_EMPLOYEE_HPP
#include <string>
namespace companies101
{

class Employee
{
public:
    Employee(const std::string& name    = "",
             const std::string& address = "",
             const double     & salary  = 0.0);
    virtual ~Employee();

    virtual const std::string& getName   () const;
    virtual const std::string& getAddress() const;
    virtual const double     & getSalary () const;

    virtual void setName   (const std::string& name);
    virtual void setAddress(const std::string& address);
    virtual void setSalary (const double     & salary);

private:
    std::string name;
    std::string address;
    double      salary;
};

}
#endif

