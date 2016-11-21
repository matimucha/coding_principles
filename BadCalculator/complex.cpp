#include "complex.h"

Complex::Complex(std::complex<int> newResult) : result(newResult)
{

}

std::unique_ptr<Number> Complex::operator+ (const Number& rhs) const
{
    auto complexRhs = dynamic_cast<const Complex&>(rhs);

    return std::unique_ptr<Number> (new Complex(result + complexRhs.result));
}

std::unique_ptr<Number> Complex::operator- (const Number& rhs) const
{
    auto complexRhs = dynamic_cast<const Complex&>(rhs);

    return std::unique_ptr<Number> (new Complex(result - complexRhs.result));
}

std::unique_ptr<Number> Complex::operator* (const Number& rhs) const
{
    auto complexRhs = dynamic_cast<const Complex&>(rhs);

    return std::unique_ptr<Number> (new Complex(result * complexRhs.result));
}

std::unique_ptr<Number> Complex::operator/ (const Number& rhs) const
{
    auto complexRhs = dynamic_cast<const Complex&>(rhs);

    return std::unique_ptr<Number> (new Complex(result / complexRhs.result));
}

std::string Complex::toString() const
{
    return std::to_string(result.real()) + " + " + std::to_string(result.imag()) + "i";
}
