#pragma once
#include <iostream>

template <typename T>
struct Node{
    T data;
    size_t height;
    Node<T>* left;
    Node<T>* right;

    Node() : data(T()), left(nullptr), right(nullptr) {}
    Node(const T& _data) : data(_data), left(nullptr), right(nullptr) {}
    Node(T&& _data) : data(_data), left(nullptr), right(nullptr) {}
};

template <typename T>
class TreeAVL{
public:
    Node<T>* root;

    TreeAVL() : root(nullptr) {}

    Node<T>* calcBalance(Node<T>* _curr){
        long long balance = _curr->left->height - _curr->right->height;
        if (balance == 2){
            if (calcBalance(Node<T>* _curr->left) == -1){
                _curr->left = rotateLeft(_curr->left);
            }
            
            return rotateRight(_curr);
        }
        else if (balance == -2){
            if (calcBalance(Node<T>* _curr->right) == 1){
                _curr->right = rotateRight(_curr->right);
                return rotateLeft(_curr);
            }

            return rotateLeft(_curr);
        }
        else{
            return _curr;
        }
    }

    Node<T>* rotateRight(Node<T>* x){
        Node<T>* y = x->left;
        Node<T>* z = y->right;
        y->right = x;
        x->left = z;
        x->height = std::max(x->left->height, x->right->height) + 1;
        y->height = std::max(y->left->height, y->right->height) + 1;
        return y;
    }
};