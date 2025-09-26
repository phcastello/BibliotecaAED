#pragma once
#include "list_node.hpp"

namespace dsl {

template <typename T>
class CircularLinkedList {
private:
    Node<T>* tail_;

public:
    CircularLinkedList() : tail_(nullptr) {}
    CircularLinkedList(const CircularLinkedList&) = delete;
    CircularLinkedList& operator=(const CircularLinkedList&) = delete;
    ~CircularLinkedList() { clear(); }

    Node<T>* getTail() {
        return tail_;
    }
    const Node<T>* getTail() const {
        return tail_;
    }

    Node<T>* getHead() {
        return tail_ ? tail_->getLink() : nullptr;
    }
    const Node<T>* getHead() const {
        return tail_ ? tail_->getLink() : nullptr;
    }

    bool isEmpty() const {
        return tail_ == nullptr;
    }

    void clear() {
        if (tail_ == nullptr) {
            return;
        }

        Node<T>* head = tail_->getLink();
        tail_->setLink(nullptr);

        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->getLink();
            delete current;
            current = next;
        }

        tail_ = nullptr;
    }

    void insertEnd(const T& value) {
        Node<T>* node = new Node<T>(value);
        if (tail_ == nullptr) {
            tail_ = node;
            tail_->setLink(tail_);
            return;
        }
        node->setLink(tail_->getLink());
        tail_->setLink(node);
        tail_ = node;
    }

    void insertStart(const T& value) {
        Node<T>* node = new Node<T>(value);
        if (tail_ == nullptr) {
            tail_ = node;
            tail_->setLink(tail_);
            return;
        }
        node->setLink(tail_->getLink());
        tail_->setLink(node);
    }

    T removeStart() {
        if (isEmpty()) {
            throw "Lista vazia";
        }

        Node<T>* head = tail_->getLink();
        T value = head->getInfo();

        if (head == tail_) {
            delete head;
            tail_ = nullptr;
            return value;
        }

        tail_->setLink(head->getLink());
        delete head;
        return value;
    }

    T removeEnd() {
        if (isEmpty()) {
            throw "Lista vazia";
        }

        Node<T>* head = tail_->getLink();
        Node<T>* oldTail = tail_;
        T value = oldTail->getInfo();

        if (head == tail_) {
            delete oldTail;
            tail_ = nullptr;
            return value;
        }

        Node<T>* previous = head;
        while (previous->getLink() != tail_) {
            previous = previous->getLink();
        }

        previous->setLink(head);
        tail_ = previous;
        delete oldTail;
        return value;
    }
};

} // namespace dsl

