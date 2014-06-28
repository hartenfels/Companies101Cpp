#include "Persistence.hpp"
namespace companies101 {
using boost::property_tree::ptree;

template<typename T> static void
unparseElements(ptree& tree, const std::string& key, const T& elements)
{
    if (elements.size()) {
        ptree list;
        for (const auto& elem : elements)
           list.push_back({"", unparse(elem)});
        tree.add_child(key, list);
    }
}

ptree
unparse(const Company& company)
{
    ptree tree;
    tree.put("name", company.getName());
    unparseElements(tree, "departments", company.getDepartments());
    return tree;
}

ptree
unparse(const Department& department)
{
    ptree tree;
    tree.put("name", department.getName());
    unparseElements(tree, "departments", department.getDepartments());
    unparseElements(tree, "employees",   department.getEmployees  ());
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
    for (const auto& child : tree.get_child("departments", {}))
        depts.push_back(parseDepartment(child.second));

    return {tree.get<std::string>("name"), depts};
}

Department
parseDepartment(const ptree& tree)
{
    std::vector<Employee> empls;
    for (const auto& child : tree.get_child("employees", {}))
        empls.push_back(parseEmployee(child.second));

    std::vector<Department> depts;
    for (const auto& child : tree.get_child("departments", {}))
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

