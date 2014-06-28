#include "MutateVisitor.hpp"
#include "Company.hpp"
#include "Department.hpp"
#include "Employee.hpp"
namespace companies101 {

MutateVisitor::MutateVisitor(std::function<void (Company&)> nc,
                             std::function<void (Department&)> nd,
                             std::function<void (Employee&)> ne,
                             std::function<void (Company&)> xc,
                             std::function<void (Department&)> xd,
                             std::function<void (Employee&)> xe) :
    enterCompany   (nc), exitCompany   (xc),
    enterDepartment(nd), exitDepartment(xd),
    enterEmployee  (ne), exitEmployee  (xe) {}

MutateVisitor&
MutateVisitor::onEnter(std::function<void (Company&)> cb)
{ enterCompany    = cb; return *this; }

MutateVisitor&
MutateVisitor::onEnter(std::function<void (Department&)> cb)
{ enterDepartment = cb; return *this; }

MutateVisitor&
MutateVisitor::onEnter(std::function<void (Employee&)> cb)
{ enterEmployee   = cb; return *this; }

MutateVisitor&
MutateVisitor::onExit(std::function<void (Company&)> cb)
{ exitCompany     = cb; return *this; }

MutateVisitor&
MutateVisitor::onExit(std::function<void (Department&)> cb)
{ exitDepartment  = cb; return *this; }

MutateVisitor&
MutateVisitor::onExit(std::function<void (Employee&)> cb)
{ exitEmployee    = cb; return *this; }

void
MutateVisitor::enter(Company& obj) const
{ enterCompany(obj); }

void
MutateVisitor::enter(Department& obj) const
{ enterDepartment(obj); }

void
MutateVisitor::enter(Employee& obj) const
{ enterEmployee(obj); }

void
MutateVisitor::exit(Company& obj) const
{ exitCompany(obj); }

void
MutateVisitor::exit(Department& obj) const
{ exitDepartment(obj); }

void
MutateVisitor::exit(Employee& obj) const
{ exitEmployee(obj); }

}

