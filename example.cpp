#include <iostream>
#include <optional>
#include "Try.h"

using namespace std;

double division(int a, int b) {
    if( b == 0 ) {
        throw std::runtime_error("Division by zero condition!");
    }
    return 1.0f * a / b;
}

Try<double> wrappedDivision(int a, int b) {
    try {
        return Try{ division(a, b) };
    } catch (std::exception& e) {
        return Try<double>{e};
    }
}

void displayResult(int order, Try<double> result) {
    if (result.isSuccess()) {
        std::cout << "Division result " << order << " is " << result.get().value() << std::endl;
    } else {
        std::cout << "Division result " << order << " error " << result.getErrorMessage() << std::endl;
    }
}

int main() {
    auto result = wrappedDivision(3,2);
    displayResult(1, result);

    result = wrappedDivision(3,0);
    displayResult(2, result);

    return 0;
}