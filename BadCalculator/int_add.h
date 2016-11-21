#pragma once
#include "number.h"


struct IntAdd : Number
{
    IntAdd(int newResult);
    virtual ~IntAdd() {}
    virtual std::unique_ptr<Number> operator+ (const Number& rhs) const override;
    virtual std::unique_ptr<Number> operator- (const Number& rhs) const override;
    virtual std::unique_ptr<Number> operator* (const Number& rhs) const override;
    virtual std::unique_ptr<Number> operator/ (const Number& rhs) const override;
    virtual std::string toString() const override;
private:
    int result;
};
