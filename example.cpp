#include <iostream>
#include <optional>
#include "Try.h"

using namespace std;

double division(int a, int b) {
    if( b == 0 ) {
        throw "Division by zero condition!";
    }
    return a / b;
}

Try<double> wrappedDivision(int a, int b) {
    try {
        return Try{ division(a, b) };
    } catch (std::exception& e) {
        return Try<double>{e};
    }
}

int main() {
    std::cout << "Division result 1 is " << wrappedDivision(3,2).getOrElse(0) << std::endl;
    std::cout << "Division result 1 is " << wrappedDivision(3,2).get().value() << std::endl;
    std::cout << "Division result 2 is " << wrappedDivision(3,0).get().value() << std::endl;
    std::cout << "Division error  2 is " << wrappedDivision(3,0).getError().value().what() << std::endl;

    return 0;
}