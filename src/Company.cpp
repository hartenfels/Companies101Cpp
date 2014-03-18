#include "Company.hpp"
namespace companies101
{ using namespace std;

Company::Company(const string& n, const vector<Department>& ds) :
    name(n), departments(ds) {}

Company::~Company() {}


const string&
Company::getName() const
{
    return name;
}

const vector<Department>&
Company::getDepartments() const
{
    return departments;
}


vector<Department>&
Company::getMutableDepartments()
{
    return departments;
}


void
Company::setName(const string& n)
{
    name = n;
}

void
Company::setDepartments(const vector<Department>& ds)
{
    departments = ds;
}

}

