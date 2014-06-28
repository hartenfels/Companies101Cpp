#ifndef COMPANIES101_MUTATEVISITOR_HPP
#define COMPANIES101_MUTATEVISITOR_HPP
#include <functional>
namespace companies101 {
class Company;
class Department;
class Employee;

class MutateVisitor {
public:
    MutateVisitor(std::function<void (Company   &)> nc = [](Company   &){},
                  std::function<void (Department&)> nd = [](Department&){},
                  std::function<void (Employee  &)> ne = [](Employee  &){},
                  std::function<void (Company   &)> xc = [](Company   &){},
                  std::function<void (Department&)> xd = [](Department&){},
                  std::function<void (Employee  &)> xe = [](Employee  &){});

    MutateVisitor& onEnter(const std::function<void (Company   &)> callback);
    MutateVisitor& onEnter(const std::function<void (Department&)> callback);
    MutateVisitor& onEnter(const std::function<void (Employee  &)> callback);

    MutateVisitor& onExit (const std::function<void (Company   &)> callback);
    MutateVisitor& onExit (const std::function<void (Department&)> callback);
    MutateVisitor& onExit (const std::function<void (Employee  &)> callback);

    void enter(Company   & company   ) const;
    void enter(Department& department) const;
    void enter(Employee  & employee  ) const;

    void exit (Company   & company   ) const;
    void exit (Department& department) const;
    void exit (Employee  & employee  ) const;

private:
    std::function<void (Company   &)> enterCompany,    exitCompany;
    std::function<void (Department&)> enterDepartment, exitDepartment;
    std::function<void (Employee  &)> enterEmployee,   exitEmployee;
};

}
#endif

