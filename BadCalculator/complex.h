#pragma once
#include "number.h"
#include <complex>
#include <algorithm>

struct Complex : Number
{
    Complex(std::complex<int> newResult);
    virtual ~Complex();

    virtual std::unique_ptr<Number> operator+ (const Number& rhs) const override;
    virtual std::unique_ptr<Number> operator- (const Number& rhs) const override;
    virtual std::unique_ptr<Number> operator* (const Number& rhs) const override;
    virtual std::unique_ptr<Number> operator/ (const Number& rhs) const override;

    virtual std::string toString() const override;

private:
    std::complex<int> result;
};
