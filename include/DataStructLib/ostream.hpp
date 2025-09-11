#pragma once
#include <ostream>
#include "linked_list.hpp"
#include "prioritized_element.hpp"

namespace dsl {

// Mostra apenas o valor para PrioritizedElement<T>
template <typename T>
inline std::ostream& operator<<(std::ostream& os, const PrioritizedElement<T>& elem) {
    os << elem.getValue();
    return os;
}

// Imprime elementos de uma LinkedList<T>
template <typename T>
inline std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) {
    const Node<T>* current = list.getHead();
    os << "Itens da lista: ";
    while (current != nullptr) {
        os << current->getInfo() << ' ';
        current = current->getLink();
    }
    return os;
}

} // namespace dsl
