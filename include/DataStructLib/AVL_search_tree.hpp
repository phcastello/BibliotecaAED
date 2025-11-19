#pragma once

#include <algorithm>
#include <cstddef>
#include <queue>
#include <random>
#include <type_traits>
#include <vector>

#include "binary_search_tree.hpp"

namespace dsl {

template <typename T>
class AVL : public BST<T> {
public:
    using BST<T>::BST; // Herda os construtores da BST

    // O(1) approach (utilizando a altura armazenada)
    int balanceFactorO_of_1(const BSTNode<T>* node) const{
        if(!node) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    // O(n) approach (caso não fosse guardado a altura de cada nó)
    int balanceFactorO_of_N(const BSTNode<T>* node) const{
        if(!node) return 0;
        return findNodeHeightO_of_N(node->left) - findNodeHeightO_of_N(node->right);
    }

    void rightRotate(const BSTNode<T>* _root) const{
        
    }

private:
    int findNodeHeightO_of_N(const BSTNode<T>* node) const {
        if (node == nullptr) {
            return -1;
        }

        if (node->right == nullptr && node->left == nullptr) {
            return 0;
        }

        const int leftHeight = findNodeHeightO_of_N(node->left);
        const int rightHeight = findNodeHeightO_of_N(node->right);
        return 1 + std::max(leftHeight, rightHeight);
    }
};
}
