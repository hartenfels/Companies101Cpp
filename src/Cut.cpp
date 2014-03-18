#include "Cut.hpp"
#include <algorithm>
namespace companies101
{ using namespace std;

void cut(Company& c)
{
    auto& ds = c.getMutableDepartments();
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
    e.setSalary(e.getSalary() / 2);
}

}

