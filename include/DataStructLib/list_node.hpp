#pragma once

namespace dsl {

// Nó de lista encadeada usando ponteiros simples
template <typename T>
class Node {
private:
    T info;
    Node* link;

public:
    Node() : info(), link(nullptr) {}
    Node(const T& value, Node* next = nullptr) : info(value), link(next) {}

    T& getInfo() {
        return info;
    }
    const T& getInfo() const {
        return info;
    }

    void setInfo(const T& v) {
        info = v;
    }

    Node* getLink() {
        return link;
    }
    const Node* getLink() const {
        return link;
    }

    void setLink(Node* n) {
        link = n;
    }
};

}

