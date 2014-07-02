#ifndef COMPANIES101_OPERATIONS_HPP
#define COMPANIES101_OPERATIONS_HPP
namespace companies101 {
class Host;

void         cut   (      Host& host);

unsigned int depth (const Host& host);

double       median(const Host& host);

double       total (const Host& host);

void         print (const Host& host, unsigned int indent = 0);

}
#endif

