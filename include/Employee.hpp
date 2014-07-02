#ifndef COMPANIES101_EMPLOYEE_HPP
#define COMPANIES101_EMPLOYEE_HPP
#include "Host.hpp"
#include <string>
namespace companies101 {
class Visitor;
class MutateVisitor;

class Employee : public Host {
public:
    Employee(const std::string& name    = "",
             const std::string& address = "",
             const double     & salary  = 0.0);

    const std::string& getName   () const;
    const std::string& getAddress() const;
    const double     & getSalary () const;

    void setName   (const std::string& name);
    void setAddress(const std::string& address);
    void setSalary (const double     & salary);

    void accept(const Visitor      & visitor) const override;
    void accept(const MutateVisitor& visitor)       override;

private:
    std::string name;
    std::string address;
    double      salary;
};

}
#endif

