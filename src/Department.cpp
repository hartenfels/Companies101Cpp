#include "Department.hpp"
namespace companies101
{ using namespace std;

Department::Department(const string& n, const vector<Employee>& es,
        const vector<Department>& ds) :
    name(n), employees(es), departments(ds) {}

Department::~Department() {}


const std::string&
Department::getName() const
{
    return name;
}

const vector<Employee>&
Department::getEmployees() const
{
    return employees;
}

const vector<Department>&
Department::getDepartments() const
{
    return departments;
}


vector<Employee>&
Department::getMutableEmployees()
{
    return employees;
}

vector<Department>&
Department::getMutableDepartments()
{
    return departments;
}


void
Department::setName(const string& n)
{
    name = n;
}

void
Department::setEmployees(const vector<Employee>& es)
{
    employees = es;
}

void
Department::setDepartments(const vector<Department>& ds)
{
    departments = ds;
}

}

