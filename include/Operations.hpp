#ifndef COMPANIES101_OPERATIONS_HPP
#define COMPANIES101_OPERATIONS_HPP
#include "Company.hpp"
#include "Department.hpp"
#include "Employee.hpp"
#include "MutateVisitor.hpp"
#include "Visitor.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
namespace companies101 {

template<typename T>
void cut(T& t)
{
    t.accept(MutateVisitor()
        .onEnter([](Employee& e){
            const double& sal = e.getSalary();
            e.setSalary(sal ? sal / 2 : 0);
        }));
}

template<typename T>
unsigned int depth(const T& t)
{
    unsigned int max = 0, cur = 0;
    t.accept(Visitor()
        .onEnter([&](const Department& d){
            ++cur;
        })
        .onExit ([&](const Department& d){
            if (cur > max) max = cur;
            --cur;
        }));
    return max;
}

template<typename T>
double median(const T& t)
{
    double       total = 0;
    unsigned int empls = 0;
    t.accept(Visitor()
        .onEnter([&](const Employee& e){
            total += e.getSalary();
            ++empls;
        }));
    return empls ? total / empls : 0;
}

template<typename T>
void print(const T& t, unsigned int i = 0)
{
    t.accept(Visitor()
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

template<typename T>
double total(const T& t)
{
    double total = 0;
    t.accept(Visitor()
        .onEnter([&](const Employee& e){
            total += e.getSalary();
        }));
    return total;
}

}
#endif

