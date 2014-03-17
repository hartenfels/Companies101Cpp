#include "NestedCompany.hpp"
namespace companies101
{ using namespace std;

NestedCompany::NestedCompany(const string& n, const vector<Department>& ds) :
    Company(n), departments(ds) {}

NestedCompany::~NestedCompany() {}


const vector<Department>&
NestedCompany::getDepartments() const
{
    return departments;
}


vector<Department>&
NestedCompany::getMutableDepartments()
{
    return departments;
}


void
NestedCompany::setDepartments(const vector<Department>& ds)
{
    departments = ds;
}

}

