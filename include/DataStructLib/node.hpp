#pragma once
#include <utility>

namespace dsl {

// Nó da lista encadeada (didático, usa ponteiros brutos de propósito)
template <typename T>
class Node {
private:
    T info;
    Node* link;

public:
    // Construtores
    Node() : info(), link(nullptr) {}
    Node(const T& value, Node* next = nullptr) : info(value), link(next) {}
    Node(T&& value, Node* next = nullptr) : info(std::move(value)), link(next) {}

    // Acessores
    T& getInfo(){
        return info;
    }
    const T& getInfo() const {
        return info;
    }

    void setInfo(const T& v){
        info = v;
    }
    void setInfo(T&& v){
        info = std::move(v);
    }

    Node* getLink(){
        return link;
    }
    const Node* getLink() const {
        return link;
    }
    void setLink(Node* n){
        link = n;
    }
};

}
