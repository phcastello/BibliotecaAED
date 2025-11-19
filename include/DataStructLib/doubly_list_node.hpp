#pragma once

namespace dsl {

// Nó de lista duplamente encadeada para fins didáticos
template <typename T>
class DoublyNode {
private:
    T info;
    DoublyNode* previous;
    DoublyNode* next;

public:
    DoublyNode() : info(), previous(nullptr), next(nullptr) {}
    DoublyNode(const T& value, DoublyNode* prev = nullptr, DoublyNode* nextNode = nullptr)
        : info(value), previous(prev), next(nextNode) {}

    T& getInfo() {
        return info;
    }
    const T& getInfo() const {
        return info;
    }

    void setInfo(const T& v) {
        info = v;
    }

    DoublyNode* getNext() {
        return next;
    }
    const DoublyNode* getNext() const {
        return next;
    }

    void setNext(DoublyNode* n) {
        next = n;
    }

    DoublyNode* getPrevious() {
        return previous;
    }
    const DoublyNode* getPrevious() const {
        return previous;
    }

    void setPrevious(DoublyNode* p) {
        previous = p;
    }
};

} // namespace dsl
