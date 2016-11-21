#include "stringtonumberconverterfactory.h"
#include <complex>
#include <cassert>
namespace {
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
}//namespace

StringToNumberConverterFactory::StringToNumberConverterFactory(const NumberType& ct) : converterType(ct)
{

}

std::function<std::unique_ptr<Number>(const std::string&)> StringToNumberConverterFactory::create()
{
    switch(converterType)
    {
        case NumberType::Integer : return [](const std::string& s)
                                    { return std::unique_ptr<Number>(new AddInt(std::stoi(s))); }
        case NumberType::Complex : std::unique_ptr<Number> stringToComplex(const std::string& text)
            {
                auto splitPosition = std::find_if(text.rbegin(), text.rend(), [](char c){return c == '-' || c == '+';});
                auto splitPoint = text.begin() + std::distance(splitPosition, text.rend())-1;

                re = std::stof(std::string(text.begin(), splitPoint));
                im = std::stof(std::string(splitPoint, text.end()));

                return std::unique_ptr<Number>(new Complex(std::complex<int>(re, im)));
            }
        assert(0&& "unknown conversion type");
    }
}
