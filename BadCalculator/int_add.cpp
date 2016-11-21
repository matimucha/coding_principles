#include "int_add.h"

IntAdd::IntAdd(int newResult) : result(newResult)
{

}

std::unique_ptr<Number> IntAdd::operator+ (const Number& rhs) const
{
    auto intRhs = dynamic_cast<const IntAdd&>(rhs);

    return std::unique_ptr<Number> (new IntAdd(result + intRhs.result));
}

std::unique_ptr<Number> IntAdd::operator- (const Number& rhs) const
{
    auto intRhs = dynamic_cast<const IntAdd&>(rhs);

    return std::unique_ptr<Number> (new IntAdd(result - intRhs.result));
}

std::unique_ptr<Number> IntAdd::operator* (const Number& rhs) const
{
    auto intRhs = dynamic_cast<const IntAdd&>(rhs);

    return std::unique_ptr<Number> (new IntAdd(result * intRhs.result));
}

std::unique_ptr<Number> IntAdd::operator/ (const Number& rhs) const
{
    auto intRhs = dynamic_cast<const IntAdd&>(rhs);

    return std::unique_ptr<Number> (new IntAdd(result / intRhs.result));
}


std::string IntAdd::toString() const
{
    return std::to_string(result);
}
