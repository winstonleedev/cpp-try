#include <iostream>
#include <optional>
#include "Try.h"

using namespace std;

// Catch external exceptions

double division(int a, int b) {
    if (b == 0) {
        throw runtime_error("Division by zero condition!");
    }
    return 1.0f * a / b;
}

Try<double> wrappedDivision(int a, int b) {
    try {
        return Try{division(a, b)};
    } catch (exception &e) {
        return Try<double>{e};
    }
}

// Handling our own errors

Try<double> safeDivision(int a, int b) {
    if (b == 0) {
        return Try<double>(std::runtime_error("Division by zero condition!"));
    }
    return Try<double>(1.0f * a / b);
}

void displayResult(const string &desc, Try<double> result) {
    cout << "Division result for " << desc << " : ";
    if (result.isSuccess()) {
        cout << result.get().value() << endl;
    } else {
        cout << " error " << result.getErrorMessage() << endl;
    }
}

int main() {
    auto result = wrappedDivision(3, 2);
    displayResult("not our code, normal case", result);

    result = wrappedDivision(3, 0);
    displayResult("not our code, exception case", result);

    result = safeDivision(3, 2);
    displayResult("our code, normal case", result);

    result = safeDivision(3, 0);
    displayResult("our code, exception case", result);
    return 0;
}