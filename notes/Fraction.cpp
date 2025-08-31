#include <iostream>
#include <numeric>
/*Write a class Fraction that defines adding, subtracting, multiplying, and
dividing fractions by overloading standard operators for these operations. Write
a function member for reducing factors and overload I/O operators to input and
output fractions.*/
class Fraction {
    int num, den;

    void reduce() {
        int g = std::gcd(num, den);
        num /= g;
        den /= g;
        if(den < 0) {
            num = -num;
            den = -den;
        }
    }

public:
    Fraction(int n = 0, int d = 1) : num(n), den(d) { reduce(); }

    // Operator overloads
    Fraction operator+(const Fraction& rhs) const {
        return Fraction(num * rhs.den + rhs.num * den, den * rhs.den);
    }
    Fraction operator-(const Fraction& rhs) const {
        return Fraction(num * rhs.den - rhs.num * den, den * rhs.den);
    }
    Fraction operator*(const Fraction& rhs) const {
        return Fraction(num * rhs.num, den * rhs.den);
    }
    Fraction operator/(const Fraction& rhs) const {
        return Fraction(num * rhs.den, den * rhs.num);
    }

    // I/O operators
    friend std::ostream& operator<<(std::ostream& out, const Fraction& f) {
        out << f.num << "/" << f.den;
        return out;
    }
    friend std::istream& operator>>(std::istream& in, Fraction& f) {
        char slash;
        in >> f.num >> slash >> f.den;
        f.reduce();
        return in;
    }
};

int main() {
    Fraction a, b;
    std::cout << "Enter two fractions (format: num/den): ";
    std::cin >> a >> b;
    std::cout << "Sum: " << a + b << "\n";
    std::cout << "Difference: " << a - b << "\n";
    std::cout << "Product: " << a * b << "\n";
    std::cout << "Quotient: " << a / b << "\n";
}

/*

Here are the issues in your Fraction.cpp:

Operator Overloading Syntax:
You defined add, subtract, multi, and divi as member functions, but in main you use a + b, a - b, etc.
You need to overload the operators (operator+, operator-, operator*, operator/) instead.

I/O Operator Names:
The standard names are operator<< and operator>>, not outoperator and inoperator.
Also, they should take const Fraction& for output.

I/O Operator Usage:
In main, you use std::cin >> a >> b; and std::cout << a + b; but you haven't overloaded these operators correctly.

Corrected Example
Summary:

Use operator overloading (operator+, etc.) for arithmetic.
Use operator<< and operator>> for I/O.
Your main function will then work as expected.
Similar code found with 1 license type - View matches
I though the name does not matter

In C++, the name of an overloaded operator function does matter. For operator overloading, you must use the exact operator function name, such as operator+, operator-, operator*, operator/, operator<<, and operator>>.

For example:

To overload addition, use Fraction operator+(const Fraction&) const.
For output, use friend std::ostream& operator<<(std::ostream&, const Fraction&).
If you use other names (like add, outoperator), the compiler will not recognize them as operator overloads, and expressions like a + b or std::cout << a will not work.*/