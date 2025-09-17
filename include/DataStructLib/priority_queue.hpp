#pragma once
#include "linked_list.hpp"

namespace dsl {

template <typename T>
class PriorityQueue {
private:
    struct Entry {
        T value;
        unsigned int priority;
        unsigned long arrivalOrder;

        Entry() : value(), priority(0), arrivalOrder(0) {}
        Entry(const T& v, unsigned int p, unsigned long order)
            : value(v), priority(p), arrivalOrder(order) {}
    };

    LinkedList<Entry> list_;
    unsigned long counter_;

public:
    PriorityQueue() : counter_(0) {}

    void enqueue(const T& value, unsigned int priority) {
        Entry element(value, priority, counter_++);

        Node<Entry>* previous = nullptr;
        Node<Entry>* current = list_.getHead();

        while (current != nullptr) {
            const Entry& info = current->getInfo();
            bool lowerPriority = info.priority < element.priority;
            bool samePriorityEarlier = info.priority == element.priority
                                     && info.arrivalOrder < element.arrivalOrder;
            if (lowerPriority || samePriorityEarlier) {
                previous = current;
                current = current->getLink();
            } else {
                break;
            }
        }

        Node<Entry>* newNode = new Node<Entry>(element, current);
        if (previous == nullptr) {
            list_.setHead(newNode);
        } else {
            previous->setLink(newNode);
        }
    }

    T dequeue() {
        Entry removed = list_.removeStart();
        return removed.value;
    }

    bool isEmpty() const {
        return list_.isEmpty();
    }
};

}
