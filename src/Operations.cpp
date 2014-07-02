#include "Operations.hpp"
#include "Company.hpp"
#include "Department.hpp"
#include "Employee.hpp"
#include "MutateVisitor.hpp"
#include "Visitor.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
namespace companies101 {

void
cut(Host& h)
{
    h.accept(MutateVisitor()
        .onEnter([](Employee& e){
            const double& sal = e.getSalary();
            e.setSalary(sal ? sal / 2 : 0);
        }));
}

unsigned int
depth(const Host& h)
{
    unsigned int max = 0, cur = 0;
    h.accept(Visitor()
        .onEnter([&](const Department&){
            ++cur;
        })
        .onExit ([&](const Department&){
            if (cur > max) max = cur;
            --cur;
        }));
    return max;
}

double
median(const Host& h)
{
    double       total = 0;
    unsigned int empls = 0;
    h.accept(Visitor()
        .onEnter([&](const Employee& e){
            total += e.getSalary();
            ++empls;
        }));
    return empls ? total / empls : 0;
}

double
total(const Host& h)
{
    double total = 0;
    h.accept(Visitor()
        .onEnter([&](const Employee& e){
            total += e.getSalary();
        }));
    return total;
}

void
print(const Host& h, unsigned int i)
{
    h.accept(Visitor()
        .onEnter([&](const Company   & c){
            std::fill_n(std::ostream_iterator<char>(std::cout), i++, '\t');
            std::cout << c.getName() << "\n";
        })
        .onEnter([&](const Department& d){
            std::fill_n(std::ostream_iterator<char>(std::cout), i++, '\t');
            std::cout << d.getName() << "\n";
        })
        .onEnter([&](const Employee  & e){
            std::fill_n(std::ostream_iterator<char>(std::cout), i,   '\t');
            std::cout << e.getName   () << ", "
                      << e.getAddress() << ", "
                      << e.getSalary () << '\n';
        })
        .onExit ([&](const Company   &){ --i; })
        .onExit ([&](const Department&){ --i; }));
}

}

