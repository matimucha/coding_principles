#include <iostream>
#include <string>
#include <complex>
#include <vector>
#include <algorithm>


//#BAD_CODE

using Complex = std::complex<double>;

enum class NumberType {Integer, Complex};

namespace
{
    Complex stringToComplex(const std::string& text)
    {
        auto splitPosition = std::find_if(text.rbegin(), text.rend(), [](char c){return c == '-' || c == '+';});
        auto splitPoint = text.begin() + std::distance(splitPosition, text.rend())-1;

        return Complex(std::stof(std::string(text.begin(), splitPoint)),
                       std::stof(std::string(splitPoint, text.end())));
    }
}

class Calculator
{
public:
    Calculator() {}
    void calculate(NumberType numType, char* n1, char* op,char* n2);
};

void Calculator::calculate(NumberType numType, char *n1, char *op, char *n2)
{
    if(numType == NumberType::Integer)
    {
        int result = 0;
        switch(*op)
        {
            case '+': result = std::stoi(n1) + std::stoi(n2); break;
            case '-': result = std::stoi(n1) - std::stoi(n2); break;
            case '*': result = std::stoi(n1) * std::stoi(n2); break;
            case '/': result = std::stoi(n1) / std::stoi(n2); break;
        }
        std::cout << result << std::endl;
    }
    else if(numType == NumberType::Complex)
    {
        auto c1 = stringToComplex(std::string(n1));
        auto c2 = stringToComplex(std::string(n2));

        Complex result;
        switch(*op)
        {
            case '+': result = Complex(c1) + Complex(c2); break;
            case '-': result = Complex(c1) - Complex(c2); break;
            case '*': result = Complex(c1) * Complex(c2); break;
            case '/': result = Complex(c1) / Complex(c2); break;
        }

        std::cout << result.real() << " + " << result.imag() << "i" << std::endl;
    }

}

int main(int argc, char *argv[])
{

    if(argc != 5)
    {
        std::cout << "missing arguments: " << argc << std::endl;
        return 0;
    }

    NumberType numType;
    if(std::string(argv[1]) == "-i")
    {
        numType = NumberType::Integer;
    }
    else if(std::string(argv[1]) == "-c")
    {
        numType = NumberType::Complex;
    }

    Calculator().calculate(numType, argv[2], argv[3], argv[4]);

    return 0;
}
