#pragma once
#include "linked_list.hpp"

namespace dsl {

// Pilha (LIFO) construída sobre LinkedList
template <typename T>
class Stack {
private:
    LinkedList<T> stack_;

public:
    void push(const T& x){
        stack_.insertStart(x);
    }
    void push(T&& x){
        stack_.insertStart(std::move(x));
    }

    T pop(){
        return stack_.removeStart();
    }

    bool isEmpty() const {
        return stack_.isEmpty();
    }

    void printStack() const {
        stack_.imprimeLista();
    }
};

} // namespace dsl
