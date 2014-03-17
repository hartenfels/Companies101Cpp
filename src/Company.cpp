#include "Company.hpp"
namespace companies101
{ using namespace std;

Company::Company(const string& n) :
    name(n) {}

Company::~Company() {}

const string&
Company::getName() const
{
    return name;
}

void
Company::setName(const string& n)
{
    name = n;
}

}

