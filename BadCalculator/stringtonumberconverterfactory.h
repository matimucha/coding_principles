#pragma once
#include <string>
#include <functional>
#include <algorithm>
#include "number.h"

enum class NumberType {Integer, Complex};

class StringToNumberConverterFactory
{
public:
    StringToNumberConverterFactory(const NumberType& ct);
    std::function<std::unique_ptr<Number>(const std::string&)> create();
private:
    NumberType converterType;
};
