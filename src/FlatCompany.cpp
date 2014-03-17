#include "FlatCompany.hpp"
namespace companies101
{ using namespace std;

FlatCompany::FlatCompany(const string& n, const vector<Employee>& es) :
    Company(n), employees(es) {}

FlatCompany::~FlatCompany() {}


const vector<Employee>&
FlatCompany::getEmployees() const
{
    return employees;
}


vector<Employee>&
FlatCompany::getMutableEmployees()
{
    return employees;
}


void
FlatCompany::setEmployees(const vector<Employee>& es)
{
    employees = es;
}

}

