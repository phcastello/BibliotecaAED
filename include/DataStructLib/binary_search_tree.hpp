#pragma once

#include <vector>

#include "bst_node.hpp"

namespace dsl {

template <typename T>
class BST {
private:
    BSTNode<T>* root_;

    BSTNode<T>* insertNodeRec(BSTNode<T>* node, const T& data) {
        if (node == nullptr) {
            return new BSTNode<T>(data);
        }

        if (data < node->data) {
            node->left = insertNodeRec(node->left, data);
        }
        else if (data > node->data) {
            node->right = insertNodeRec(node->right, data);
        }

        return node;
    }

    void inOrderRec(const BSTNode<T>* node, std::vector<T>& out) const {
        if (node == nullptr) {
            return;
        }
        inOrderRec(node->left, out);
        out.push_back(node->data);
        inOrderRec(node->right, out);
    }

    void preOrderRec(const BSTNode<T>* node, std::vector<T>& out) const {
        if (node == nullptr) {
            return;
        }
        out.push_back(node->data);
        preOrderRec(node->left, out);
        preOrderRec(node->right, out);
    }

    void postOrderRec(const BSTNode<T>* node, std::vector<T>& out) const {
        if (node == nullptr) {
            return;
        }
        postOrderRec(node->left, out);
        postOrderRec(node->right, out);
        out.push_back(node->data);
    }

    bool hasNodeRec(const BSTNode<T>* node, const T& searchData) const {
        if (node == nullptr) {
            return false;
        }
        if (searchData == node->data) {
            return true;
        }
        if (searchData < node->data) {
            return hasNodeRec(node->left, searchData);
        }
        return hasNodeRec(node->right, searchData);
    }

    void clearRec(BSTNode<T>* node) {
        if (node == nullptr) {
            return;
        }
        clearRec(node->left);
        clearRec(node->right);
        delete node;
    }

public:
    BST() : root_(nullptr) {}
    BST(const BST&) = delete;
    BST& operator=(const BST&) = delete;
    ~BST() { clear(); }

    BSTNode<T>* getRoot() { return root_; }
    const BSTNode<T>* getRoot() const { return root_; }

    bool isEmpty() const { return root_ == nullptr; }

    void insertNode(const T& data) { root_ = insertNodeRec(root_, data); }

    std::vector<T> inOrder() const {
        std::vector<T> ordered;
        inOrderRec(root_, ordered);
        return ordered;
    }

    std::vector<T> preOrder() const {
        std::vector<T> ordered;
        preOrderRec(root_, ordered);
        return ordered;
    }

    std::vector<T> postOrder() const {
        std::vector<T> ordered;
        postOrderRec(root_, ordered);
        return ordered;
    }

    bool hasNode(const T& searchData) const {
        return hasNodeRec(root_, searchData);
    }

    void clear() {
        clearRec(root_);
        root_ = nullptr;
    }
};

} // namespace dsl

