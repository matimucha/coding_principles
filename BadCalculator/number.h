#pragma once

#include <memory>
#include <string>

struct Number
{
    virtual std::unique_ptr<Number> operator+ (const Number& rhs) const = 0;
    virtual std::unique_ptr<Number> operator- (const Number& rhs) const = 0;
    virtual std::unique_ptr<Number> operator* (const Number& rhs) const = 0;
    virtual std::unique_ptr<Number> operator/ (const Number& rhs) const = 0;

    virtual std::string toString() const = 0;

    virtual ~Number(){}
};


