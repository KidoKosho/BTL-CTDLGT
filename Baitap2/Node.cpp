#ifndef Node_H
#define Node_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
class Node {
    private:
        T data;
        Node<T>* left;
        Node<T>* right;
    public:
        Node() : left(nullptr), right(nullptr) {}
        Node(int val) : data(val), left(nullptr), right(nullptr) {}
        Node<T>* GetLeft() { return left; }
        Node<T>* GetRight() { return right; }
        int GetData() { return data; }
        void SetData(int data) { this->data = data; }
        void SetLeft(Node<T>* left) { this->left = left; }
        void SetRight(Node<T>* right) { this->right = right; }
        ~Node(){delete left;delete right;}
};
#endif