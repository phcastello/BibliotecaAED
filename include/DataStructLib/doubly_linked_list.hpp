#pragma once
#include "doubly_list_node.hpp"

namespace dsl {

template <typename T>
class DoublyLinkedList {
private:
    DoublyNode<T>* head_;
    DoublyNode<T>* tail_;

public:
    DoublyLinkedList() : head_(nullptr), tail_(nullptr) {}
    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;
    ~DoublyLinkedList() { clear(); }

    DoublyNode<T>* getHead() {
        return head_;
    }
    const DoublyNode<T>* getHead() const {
        return head_;
    }

    DoublyNode<T>* getTail() {
        return tail_;
    }
    const DoublyNode<T>* getTail() const {
        return tail_;
    }

    bool isEmpty() const {
        return head_ == nullptr;
    }

    void setHead(DoublyNode<T>* h) {
        head_ = h;
    }

    void setTail(DoublyNode<T>* t) {
        tail_ = t;
    }

    void clear() {
        DoublyNode<T>* current = head_;
        while (current != nullptr) {
            DoublyNode<T>* next = current->getNext();
            delete current;
            current = next;
        }
        head_ = nullptr;
        tail_ = nullptr;
    }

    void insertStart(const T& value) {
        DoublyNode<T>* node = new DoublyNode<T>(value, nullptr, head_);
        if (head_ != nullptr) {
            head_->setPrevious(node);
        } else {
            tail_ = node;
        }
        head_ = node;
    }

    void insertEnd(const T& value) {
        DoublyNode<T>* node = new DoublyNode<T>(value, tail_, nullptr);
        if (tail_ != nullptr) {
            tail_->setNext(node);
        } else {
            head_ = node;
        }
        tail_ = node;
    }

    T removeStart() {
        if (isEmpty()) {
            throw "Lista vazia";
        }

        DoublyNode<T>* oldHead = head_;
        T value = oldHead->getInfo();
        head_ = oldHead->getNext();

        if (head_ != nullptr) {
            head_->setPrevious(nullptr);
        } else {
            tail_ = nullptr;
        }

        delete oldHead;
        return value;
    }

    T removeEnd() {
        if (isEmpty()) {
            throw "Lista vazia";
        }

        DoublyNode<T>* oldTail = tail_;
        T value = oldTail->getInfo();
        tail_ = oldTail->getPrevious();

        if (tail_ != nullptr) {
            tail_->setNext(nullptr);
        } else {
            head_ = nullptr;
        }

        delete oldTail;
        return value;
    }
};

} // namespace dsl
