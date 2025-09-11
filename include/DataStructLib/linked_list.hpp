#pragma once
#include <iostream>
#include <stdexcept>
#include "node.hpp"

// Aqui criamos um namespace, assim falamos para o compilador que quem estiver usando a bilioteca, quer 
// usar as classes que estão dentro do namespace dsl (Data Struct Lib), evitando conflitos de nomes.
namespace dsl {

// Lista encadeada simples (didática)
template <typename T>
class LinkedList {
private:
    Node<T>* head_; // ponteiro para o primeiro nó

public:
    // Observadores básicos
    Node<T>* getHead(){
        return head_;
    }
    const Node<T>* getHead() const {
        return head_;
    }
    void setHead(Node<T>* h) {
        head_ = h;
    }


    // A parte de construtores e destrutores do c++ é um pouco chata e relativamente difícil de compreender.
    // Portanto, a parte de construtores e destrutores pode ficar para os curiosos.

    // Construtor / Destrutor
    LinkedList() : head_(nullptr) {}

    // Regra dos 5 – simples e didática: proibimos cópia para evitar dupla liberação
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    // Permitimos move para facilitar retornos por valor
    LinkedList(LinkedList&& other) noexcept : head_(other.head_) { other.head_ = nullptr; }
    LinkedList& operator=(LinkedList&& other) noexcept {
        if (this != &other) {
            clear();
            head_ = other.head_;
            other.head_ = nullptr;
        }
        return *this;
    }

    ~LinkedList() {clear(); }

    // Limpa a lista, liberando memória
    void clear() {
        Node<T>* p = head_;
        while (p != nullptr) {
            Node<T>* tmp = p;
            p = p->getLink();
            delete tmp;
        }
        head_ = nullptr;
    }

    bool isEmpty() const {
        return head_ == nullptr;
    }

    // Insere no início. Overloads para cópia e movimento.
    void insertStart(const T& x) {
        Node<T>* n = new Node<T>(x, head_);
        head_ = n;
    }
    void insertStart(T&& x) {
        Node<T>* n = new Node<T>(std::move(x), head_);
        head_ = n;
    }

    // Remove do início e retorna o valor
    T removeStart() {
        if (isEmpty()) throw std::runtime_error("Lista vazia");
        Node<T>* old = head_;
        T value = std::move(old->getInfo());
        head_ = old->getLink();
        delete old;
        return value;
    }

    // Insere no fim. Overloads para cópia e movimento também.
    void insertEnd(const T& x) {
        Node<T>* n = new Node<T>(x, nullptr);
        if (isEmpty()) { head_ = n; return; }
        Node<T>* p = head_;
        while (p->getLink() != nullptr) p = p->getLink();
        p->setLink(n);
    }
    void insertEnd(T&& x) {
        Node<T>* n = new Node<T>(std::move(x), nullptr);
        if (isEmpty()) { head_ = n; return; }
        Node<T>* p = head_;
        while (p->getLink() != nullptr) p = p->getLink();
        p->setLink(n);
    }
};

} // namespace dsl
