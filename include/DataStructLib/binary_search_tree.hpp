#pragma once

#include <algorithm>
#include <cstddef>
#include <queue>
#include <random>
#include <type_traits>
#include <vector>

#include "bst_node.hpp"

namespace dsl {

template <typename T>
class BST {
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

    std::size_t nodeCount() const {
        return inOrder().size();
    }

    BST randomIntTree(std::size_t count, int minValue = -100, int maxValue = 100) {
        assert(std::is_constructible_v<T, int>,
            "Esse método exige que T possa ser construido a partir de int."
        );
        BST tree;
        if(count == 0){
            return tree;
        }
        if(minValue > maxValue){
            std::swap(minValue, maxValue);
        }

        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> distribution(minValue, maxValue);

        for(std::size_t i=0; i < count; i++){
            tree.insertNode(static_cast<T>(distribution(generator)));
        }

        return tree;
    }

    bool removeValue(const T& value) {
        bool removed = false;
        root_ = removeRec(root_, value, removed);
        return removed;
    }

    // Executa uma busca em largura e devolve uma matriz onde cada linha representa um
    // nivel da arvore: uma fila percorre os nos nivel a nivel, os valores visitados
    // sao armazenados num vetor temporario que vira a linha da matriz e os filhos sao
    // enfileirados para compor a proxima linha.
    std::vector<std::vector<T>> breadthLevels() const {
        std::vector<std::vector<T>> levels;
        if (root_ == nullptr) {
            return levels;
        }

        std::queue<const BSTNode<T>*> queue;
        queue.push(root_);

        while (!queue.empty()) {
            const std::size_t levelSize = queue.size();
            std::vector<T> currentLevel;
            currentLevel.reserve(levelSize);

            for (std::size_t i = 0; i < levelSize; ++i) {
                const auto* node = queue.front();
                queue.pop();

                currentLevel.push_back(node->data);

                if (node->left != nullptr) {
                    queue.push(node->left);
                }
                if (node->right != nullptr) {
                    queue.push(node->right);
                }
            }

            levels.push_back(std::move(currentLevel));
        }

        return levels;
    }

    void clear() {
        clearRec(root_);
        root_ = nullptr;
    }

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

    BSTNode<T> removeRec(BSTNode<T>* node, const T& key, bool& removed){
        if(!node) return nullptr;
        if(key < node->data){
            node->left = removeRec(node->left, key, removed);
        }
        else if(key > node->data){
            node->right = removeRec(node->right, key, removed);
        }
        else{
            removed = true;
            if(!node->left){
                BSTNode<T>* right = node->right;
                delete node;
                return right;
            }
            else if(!node->right){
                BSTNode<T>* left = node->left;
                delete node;
                return left;
            }
            else{
                BSTNode<T>* sucessor = node->right;
                while(sucessor->left){
                    sucessor = sucessor->left;
                }
                node->data = sucessor->data;
                node->right = removeRec(node->right, sucessor->data, removed);
            }
        }
        return node;
    }

};

}
