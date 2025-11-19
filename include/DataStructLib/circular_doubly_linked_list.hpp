#pragma once
#include "doubly_list_node.hpp"

namespace dsl {

template <typename T>
class CircularDoublyLinkedList {
private:
    DoublyNode<T>* tail_;

public:
    CircularDoublyLinkedList() : tail_(nullptr) {}
    CircularDoublyLinkedList(const CircularDoublyLinkedList&) = delete;
    CircularDoublyLinkedList& operator=(const CircularDoublyLinkedList&) = delete;
    ~CircularDoublyLinkedList() { clear(); }

    DoublyNode<T>* getTail() {
        return tail_;
    }
    const DoublyNode<T>* getTail() const {
        return tail_;
    }

    DoublyNode<T>* getHead() {
        return tail_ ? tail_->getNext() : nullptr;
    }
    const DoublyNode<T>* getHead() const {
        return tail_ ? tail_->getNext() : nullptr;
    }

    bool isEmpty() const {
        return tail_ == nullptr;
    }

    void clear() {
        if (tail_ == nullptr) {
            return;
        }

        DoublyNode<T>* head = tail_->getNext();
        head->setPrevious(nullptr);
        tail_->setNext(nullptr);

        DoublyNode<T>* current = head;
        while (current != nullptr) {
            DoublyNode<T>* next = current->getNext();
            delete current;
            current = next;
        }

        tail_ = nullptr;
    }

    void insertEnd(const T& value) {
        DoublyNode<T>* node = new DoublyNode<T>(value);

        if (tail_ == nullptr) {
            node->setNext(node);
            node->setPrevious(node);
            tail_ = node;
            return;
        }

        DoublyNode<T>* head = tail_->getNext();
        node->setNext(head);
        node->setPrevious(tail_);
        tail_->setNext(node);
        head->setPrevious(node);
        tail_ = node;
    }

    void insertStart(const T& value) {
        DoublyNode<T>* node = new DoublyNode<T>(value);

        if (tail_ == nullptr) {
            node->setNext(node);
            node->setPrevious(node);
            tail_ = node;
            return;
        }

        DoublyNode<T>* head = tail_->getNext();
        node->setNext(head);
        node->setPrevious(tail_);
        tail_->setNext(node);
        head->setPrevious(node);
    }

    T removeStart() {
        if (isEmpty()) {
            throw "Lista vazia";
        }

        DoublyNode<T>* head = tail_->getNext();
        T value = head->getInfo();

        if (head == tail_) {
            delete head;
            tail_ = nullptr;
            return value;
        }

        DoublyNode<T>* newHead = head->getNext();
        tail_->setNext(newHead);
        newHead->setPrevious(tail_);
        delete head;
        return value;
    }

    T removeEnd() {
        if (isEmpty()) {
            throw "Lista vazia";
        }

        DoublyNode<T>* oldTail = tail_;
        T value = oldTail->getInfo();

        if (oldTail->getNext() == oldTail) {
            delete oldTail;
            tail_ = nullptr;
            return value;
        }

        DoublyNode<T>* newTail = oldTail->getPrevious();
        DoublyNode<T>* head = oldTail->getNext();

        newTail->setNext(head);
        head->setPrevious(newTail);
        tail_ = newTail;
        delete oldTail;
        return value;
    }
};

} // namespace dsl
