#include "Visitor.hpp"
#include "Company.hpp"
#include "Department.hpp"
#include "Employee.hpp"
namespace companies101 {

Visitor::Visitor(std::function<void (const Company&)> nc,
                 std::function<void (const Department&)> nd,
                 std::function<void (const Employee&)> ne,
                 std::function<void (const Company&)> xc,
                 std::function<void (const Department&)> xd,
                 std::function<void (const Employee&)> xe) :
    enterCompany   (nc), exitCompany   (xc),
    enterDepartment(nd), exitDepartment(xd),
    enterEmployee  (ne), exitEmployee  (xe) {}

Visitor&
Visitor::onEnter(const std::function<void (const Company&)> cb)
{ enterCompany    = cb; return *this; }

Visitor&
Visitor::onEnter(const std::function<void (const Department&)> cb)
{ enterDepartment = cb; return *this; }

Visitor&
Visitor::onEnter(const std::function<void (const Employee&)> cb)
{ enterEmployee   = cb; return *this; }

Visitor&
Visitor::onExit(const std::function<void (const Company&)> cb)
{ exitCompany     = cb; return *this; }

Visitor&
Visitor::onExit(const std::function<void (const Department&)> cb)
{ exitDepartment  = cb; return *this; }

Visitor&
Visitor::onExit(const std::function<void (const Employee&)> cb)
{ exitEmployee    = cb; return *this; }

void
Visitor::enter(const Company& obj) const
{ enterCompany(obj); }

void
Visitor::enter(const Department& obj) const
{ enterDepartment(obj); }

void
Visitor::enter(const Employee& obj) const
{ enterEmployee(obj); }

void
Visitor::exit(const Company& obj) const
{ exitCompany(obj); }

void
Visitor::exit(const Department& obj) const
{ exitDepartment(obj); }

void
Visitor::exit(const Employee& obj) const
{ exitEmployee(obj); }

}

