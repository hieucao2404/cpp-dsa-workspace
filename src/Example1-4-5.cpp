/*	Another example is a function that find a root of a continuous function in an interbal. The root is found by reperitively bisecting an interval and ding a midpoint of th current interval.If the midpoint is zero or the interval is smaller than some small value, the midpoint is returned. IF the values of the function on the left limit of the current interval and on the mid point have opposite signs, the search cotinus in the left half of the current interval; otherwise, the current interval becomse its right half
*/

#include <iostream>
#include <cmath>

double f(double x){
    return 2*x;
}


double root(double (*f)(double), double a, double b, double epsilon){
    double middle = (a + b) /2;
    while(f(middle) != 0 && fabs(b-a) > epsilon){
        if (f(a) *f(middle) < 0) //if f(a) and f(middle) have opposite signsl
        b = middle;
        else a = middle;
        middle = (a+b) /2;
    }
    return middle;
}

int main() {
    //exampe fid root
    auto func = [](double x){
        return 2 * x -4;
    };
    double a = 0.0, b =5.0, epsilon = 1e-6;
    double r = root(func, a, b, epsilon);
    std::cout << "Root found at x = " << r << ", f(x) = " << func(r) << std::endl;
    return 0;
}