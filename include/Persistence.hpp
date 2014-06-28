#ifndef COMPANIES101_PERSISTENCE_HPP
#define COMPANIES101_PERSISTENCE_HPP
#include "Company.hpp"
#include "Department.hpp"
#include "Employee.hpp"
#include <boost/property_tree/ptree.hpp>
namespace companies101 {

boost::property_tree::ptree unparse(const Company    & company);
boost::property_tree::ptree unparse(const Department & department);
boost::property_tree::ptree unparse(const Employee   & employee);

Company    parseCompany   (const boost::property_tree::ptree& tree);
Department parseDepartment(const boost::property_tree::ptree& tree);
Employee   parseEmployee  (const boost::property_tree::ptree& tree);

}
#endif

