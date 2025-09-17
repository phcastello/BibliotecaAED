#pragma once
#include "node.hpp"

namespace dsl {

    
template <typename T>
class LinkedList {
private:
    Node<T>* head_;

public:
    LinkedList() : head_(nullptr) {}
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;
    ~LinkedList() { clear(); }

    Node<T>* getHead() {
        return head_;
    }
    const Node<T>* getHead() const {
        return head_;
    }
    void setHead(Node<T>* h) {
        head_ = h;
    }

    void clear() {
        Node<T>* current = head_;
        while (current != nullptr) {
            Node<T>* next = current->getLink();
            delete current;
            current = next;
        }
        head_ = nullptr;
    }

    bool isEmpty() const {
        return head_ == nullptr;
    }

    void insertStart(const T& value) {
        Node<T>* node = new Node<T>(value, head_);
        head_ = node;
    }

    void insertEnd(const T& value) {
        Node<T>* node = new Node<T>(value, nullptr);
        if (head_ == nullptr) {
            head_ = node;
            return;
        }

        Node<T>* current = head_;
        while (current->getLink() != nullptr) {
            current = current->getLink();
        }
        current->setLink(node);
    }

    T removeStart() {
        if (isEmpty()) {
            throw "Lista vazia";
        }

        Node<T>* oldHead = head_;
        T value = oldHead->getInfo();
        head_ = oldHead->getLink();
        delete oldHead;
        return value;
    }
};

} // namespace dsl

