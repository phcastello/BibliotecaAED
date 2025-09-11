#pragma once
#include "linked_list.hpp"

namespace dsl {

// Fila (FIFO) construída sobre LinkedList
template <typename T>
class Queue {
private:
    LinkedList<T> queue_;

public:
    void enqueue(const T& x){
        queue_.insertEnd(x);
    }

    void enqueue(T&& x){
        queue_.insertEnd(std::move(x));
    }

    T dequeue(){
        return queue_.removeStart();
    }

    bool isEmpty() const {
        return queue_.isEmpty();
    }

    void printQueue() const {
        queue_.imprimeLista();
    }

    Node<T>* getHead(){
        return queue_.getHead();
    }
    const Node<T>* getHead() const {
        return queue_.getHead();
    }
    
};

} // namespace dsl
