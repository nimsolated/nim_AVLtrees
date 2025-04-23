#pragma once
#include <iostream>

template <typename T>
struct Node{
    T data;
    Node<T>* left;
    Node<T>* right;

    Node() : data(T()), left(nullptr), right(nullptr) {}
};

template <typename T>
class TreeAVL{
public:
    Node<T>* root;

    TreeAVL() : root(nullptr) {}
};