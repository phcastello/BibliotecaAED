#pragma once

namespace dsl {

template <typename T>
class BSTNode {
public:
    T data;
    BSTNode* left;
    BSTNode* right;

    explicit BSTNode(const T& value)
        : data(value), left(nullptr), right(nullptr) {}
};

} // namespace dsl

