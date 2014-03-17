#include "Cut.hpp"
#include <algorithm>
namespace companies101
{ using namespace std;

void cut(FlatCompany& fc)
{
    auto& es = fc.getMutableEmployees();
    void (*efun)(Employee&) = cut;
    for_each(es.begin(), es.end(), efun);
}

void cut(NestedCompany& nc)
{
    auto& ds = nc.getMutableDepartments();
    void (*dfun)(Department&) = cut;
    for_each(ds.begin(), ds.end(), dfun);
}

void cut(Department& d)
{
    auto& es = d.getMutableEmployees  ();
    auto& ds = d.getMutableDepartments();
    void (*efun)(Employee  &) = cut;
    void (*dfun)(Department&) = cut;
    for_each(es.begin(), es.end(), efun);
    for_each(ds.begin(), ds.end(), dfun);
}

void cut(Employee& e)
{
    e.setSalary(e.getSalary() / 2.0);
}

}

