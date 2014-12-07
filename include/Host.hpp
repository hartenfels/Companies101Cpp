#ifndef COMPANIES101_HOST_HPP
#define COMPANIES101_HOST_HPP
namespace companies101 {
class Visitor;
class MutateVisitor;

class Host {
public:
    virtual ~Host()                                         = default;
    virtual void accept(const Visitor      & visitor) const = 0;
    virtual void accept(const MutateVisitor& visitor)       = 0;
};

}
// asdf
#endif
