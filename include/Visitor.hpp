#ifndef COMPANIES101_VISITOR_HPP
#define COMPANIES101_VISITOR_HPP
#include <functional>
namespace companies101 {
class Company;
class Department;
class Employee;

class Visitor {
public:
    Visitor(std::function<void (const Company   &)> nc = [](const Company   &){},
            std::function<void (const Department&)> nd = [](const Department&){},
            std::function<void (const Employee  &)> ne = [](const Employee  &){},
            std::function<void (const Company   &)> xc = [](const Company   &){},
            std::function<void (const Department&)> xd = [](const Department&){},
            std::function<void (const Employee  &)> xe = [](const Employee  &){});

    Visitor& onEnter(const std::function<void (const Company   &)> callback);
    Visitor& onEnter(const std::function<void (const Department&)> callback);
    Visitor& onEnter(const std::function<void (const Employee  &)> callback);

    Visitor& onExit (const std::function<void (const Company   &)> callback);
    Visitor& onExit (const std::function<void (const Department&)> callback);
    Visitor& onExit (const std::function<void (const Employee  &)> callback);

    void enter(const Company   & company   ) const;
    void enter(const Department& department) const;
    void enter(const Employee  & employee  ) const;

    void exit (const Company   & company   ) const;
    void exit (const Department& department) const;
    void exit (const Employee  & employee  ) const;

private:
    std::function<void (const Company   &)> enterCompany,    exitCompany;
    std::function<void (const Department&)> enterDepartment, exitDepartment;
    std::function<void (const Employee  &)> enterEmployee,   exitEmployee;
};

}
#endif

