#pragma once

namespace dsl {

template <typename T>
class BSTNode {
public:
    T data;
    BSTNode* left;
    BSTNode* right;
    int height;

    explicit BSTNode(const T& value)
        : data(value), left(nullptr), right(nullptr), height(0) {}
};

} // namespace dsl

