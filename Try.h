//
// Created by Thanh Phu on 7/12/2019.
//

#ifndef CPP_TRY_TRY_H
#define CPP_TRY_TRY_H

#include <exception>
#include <optional>
#include <functional>

template<typename T>
class Try {
    bool isError;
    std::string errorMessage;
    std::optional<T> result;

public:
    explicit Try(T);

    // What if we want the result to be a string?
    // explicit Try(const std::string&);

    explicit Try(const std::exception &);

    explicit Try(std::optional<T>);
    // TODO make this monster
    // explicit Try(std::function<T>);

    bool isFailure();

    bool isSuccess();

    std::optional<T> get();

    T getOrElse(T other);

    std::optional<T> toOption();

    std::string getErrorMessage();
};


template<typename T>
Try<T>::Try(std::optional<T> value) {
    result = value;
    isError = false;
}

template<typename T>
Try<T>::Try(const std::exception &exception) {
    result = std::nullopt;
    errorMessage = exception.what();
    isError = true;
}

template<typename T>
bool Try<T>::isFailure() {
    return isError;
}

template<typename T>
bool Try<T>::isSuccess() {
    return !isFailure();
}

template<typename T>
std::optional<T> Try<T>::get() {
    return result;
}

template<typename T>
T Try<T>::getOrElse(T other) {
    if (isFailure()) {
        return other;
    }
    return result.value_or(other);
}

template<typename T>
std::optional<T> Try<T>::toOption() {
    return result;
}

template<typename T>
std::string Try<T>::getErrorMessage() {
    if (isSuccess()) {
        return "";
    }
    return errorMessage;
}

template<typename T>
Try<T>::Try(T t) {
    result = std::make_optional(t);
    isError = false;
}

//template<typename T>
//Try<T>::Try(const std::string &message) {
//    isError = true;
//    errorMessage = message;
//    result = std::nullopt;
//}


#endif //CPP_TRY_TRY_H
