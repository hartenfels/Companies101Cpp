#ifndef COMPANIES101_COMPANY_HPP
#define COMPANIES101_COMPANY_HPP
#include <string>
namespace companies101
{

class Company
{
public:
    Company(const std::string& name = "");
    virtual ~Company();

    virtual const std::string& getName() const;

    virtual void setName(const std::string& name);

private:
    std::string name;
};

}
#endif

