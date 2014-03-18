#include "Total.hpp"
#include <numeric>
namespace companies101
{ using namespace std;

template<typename T> static double
totalOp(const double& x, const T& y)
{
    return x + total(y);
}

double total(const Company& c)
{
    const auto& ds = c.getDepartments();
    return accumulate(ds.begin(), ds.end(), 0.0, totalOp<Department>);
}

double total(const Department& d)
{
    const auto& es = d.getEmployees();
    const auto& ds = d.getDepartments();
    return accumulate(es.begin(), es.end(), 0.0, totalOp<Employee>)
    	 + accumulate(ds.begin(), ds.end(), 0.0, totalOp<Department>);
}

double total(const Employee& e)
{
    return e.getSalary();
}

}

