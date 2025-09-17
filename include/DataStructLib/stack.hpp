#pragma once
#include "linked_list.hpp"

namespace dsl {

template <typename T>
class Stack {
private:
    LinkedList<T> stack_;

public:
    void push(const T& value) {
        stack_.insertStart(value);
    }

    T pop() {
        return stack_.removeStart();
    }

    bool isEmpty() const {
        return stack_.isEmpty();
    }
};

}

