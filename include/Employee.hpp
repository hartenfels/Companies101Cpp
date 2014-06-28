#ifndef COMPANIES101_EMPLOYEE_HPP
#define COMPANIES101_EMPLOYEE_HPP
#include <string>
namespace companies101 {
class Visitor;
class MutateVisitor;

class Employee {
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

    void accept(const Visitor      & visitor) const;
    void accept(const MutateVisitor& visitor);

private:
    std::string name;
    std::string address;
    double      salary;
};

}
#endif

