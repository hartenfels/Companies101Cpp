#include "Persistence.hpp"
namespace companies101 {
using boost::property_tree::ptree;

template<typename T> static ptree
unparseArray(const T& elements)
{
    ptree tree;
    for (const auto& elem : elements)
       tree.push_back({"", unparse(elem)}); 
    return tree;
}

ptree
unparse(const Company& company)
{
    ptree tree;
    tree.put("name", company.getName());
    tree.add_child("departments", unparseArray(company.getDepartments()));
    return tree;
}

ptree
unparse(const Department& department)
{
    ptree tree;
    tree.put("name", department.getName());
    tree.add_child("departments", unparseArray(department.getDepartments()));
    tree.add_child("employees",   unparseArray(department.getEmployees()));
    return tree;
}

ptree
unparse(const Employee& employee)
{
    ptree tree;
    tree.put("name",    employee.getName());
    tree.put("address", employee.getAddress());
    tree.put("salary",  employee.getSalary());
    return tree;
}


Company
parseCompany(const ptree& tree)
{
    std::vector<Department> depts;
    for (const auto& child : tree.get_child("departments"))
        depts.push_back(parseDepartment(child.second));

    return {tree.get<std::string>("name"), depts};
}

Department
parseDepartment(const ptree& tree)
{
    std::vector<Employee> empls;
    for (const auto& child : tree.get_child("employees"))
        empls.push_back(parseEmployee(child.second));

    std::vector<Department> depts;
    for (const auto& child : tree.get_child("departments"))
        depts.push_back(parseDepartment(child.second));

    return {tree.get<std::string>("name"), empls, depts};
}

Employee
parseEmployee(const ptree& tree)
{
    return {tree.get<std::string>("name"   ),
            tree.get<std::string>("address"),
            tree.get<double     >("salary" )};
}

}

