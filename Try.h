//
// Created by Thanh Phu on 7/12/2019.
//

#ifndef CPP_TRY_TRY_H
#define CPP_TRY_TRY_H

#include <exception>
#include <optional>
#include <functional>

template <typename T>
class Try {
    std::exception* error;
    std::optional<T> result;

public:
    explicit Try(T);
    explicit Try(const std::exception&);
    explicit Try(std::optional<T>);
    // TODO make this monster
    // explicit Try(std::function<T>);

    bool isFailure();
    bool isSuccess();
    std::optional<T> get();
    T getOrElse(T other);
    std::optional<T> toOption();
    std::optional<std::exception> getError();
};


template<typename T>
Try<T>::Try(std::optional<T> value) {
    result = value;
    error = nullptr;
}

template<typename T>
Try<T>::Try(const std::exception& exception) {
    result = std::nullopt;
    error = *exception;
}

template<typename T>
bool Try<T>::isFailure() {
    return error != nullptr;
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
    if (result == std::nullopt) {
        return other;
    }
    return result.value();
}

template<typename T>
std::optional<T> Try<T>::toOption() {
    return result;
}

template<typename T>
std::optional<std::exception> Try<T>::getError() {
    if (error == nullptr) {
        return std::nullopt;
    }
    return std::make_optional(*error);
}

template<typename T>
Try<T>::Try(T t) {
    Try(std::make_optional(t));
}


#endif //CPP_TRY_TRY_H
