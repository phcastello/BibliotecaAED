#pragma once
#include "linked_list.hpp"

namespace dsl {

template <typename T>
class Queue {
private:
    LinkedList<T> queue_;

public:
    void enqueue(const T& value) {
        queue_.insertEnd(value);
    }

    T dequeue() {
        return queue_.removeStart();
    }

    bool isEmpty() const {
        return queue_.isEmpty();
    }

    Node<T>* getHead() {
        return queue_.getHead();
    }
    const Node<T>* getHead() const {
        return queue_.getHead();
    }
};

}

