#pragma once
#include <cstddef>
#include "linked_list.hpp"
#include "prioritized_element.hpp"

namespace dsl {

// Fila de prioridade estável (ordena por prioridade e, em empate, por ordem de chegada)
template <typename T>
class PriorityQueue {
private:
    LinkedList<PrioritizedElement<T>> list_;
    std::size_t counter_ {0}; // ordem de chegada

public:
    PriorityQueue() = default;

    void enqueue(const T& value, unsigned int priority) {
        PrioritizedElement<T> elem(value, priority, counter_++);
        // Encontrar posição de inserção
        Node<PrioritizedElement<T>>* prev = nullptr;
        Node<PrioritizedElement<T>>* cur  = list_.getHead();

        while (cur != nullptr) {
            const auto& info = cur->getInfo();
            const bool lowerPriority = (info.getPriority() < elem.getPriority()); // número menor = maior prioridade
            const bool samePriorityEarlier = (info.getPriority() == elem.getPriority())
                                           && (info.getArrivalOrder() < elem.getArrivalOrder());
            if (lowerPriority || samePriorityEarlier) {
                prev = cur;
                cur  = cur->getLink();
            } else {
                break;
            }
        }

        // Inserir novo nó
        auto* newNode = new Node<PrioritizedElement<T>>(elem, cur);
        if (prev == nullptr) {
            // início
            list_.setHead(newNode);
        }
        else {
            prev->setLink(newNode);
        }
    }

    T dequeue() {
        // elemento de maior prioridade está no início
        return list_.removeStart().getValue();
    }

    bool isEmpty() const { return list_.isEmpty(); }
};

}
