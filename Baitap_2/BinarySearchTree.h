#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "BinaryTree.h"

template <typename T>
class BinarySearchTree : public BinaryTree<T> {
public:
    BinarySearchTree() : BinaryTree<T>() {}

    // Override phương thức insert để đảm bảo tính chất của Binary Search Tree
    void insert(T value) override {
        this->root = insert(this->root, value);
    }

    // Hàm tìm kiếm phần tử trong cây
    bool search(T value) {
        return search(this->root, value);
    }

    // Hàm tìm giá trị nhỏ nhất trong cây
    T findMin() {
        if (this->root == nullptr) throw std::runtime_error("Cây rỗng!");
        Node<T>* current = this->root;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current->GetData();
    }

    // Hàm tìm giá trị lớn nhất trong cây
    T findMax() {
        if (this->root == nullptr) throw std::runtime_error("Cây rỗng!");
        Node<T>* current = this->root;
        while (current->right != nullptr) {
            current = current->right;
        }
        return current->GetData();
    }

private:
    // Hàm chèn phần tử vào cây (đệ quy)
    Node<T>* insert(Node<T>* root, T value) {
        if (root == nullptr) return new Node<T>(value);
        if (value < root->GetData()) {
            root->SetLeft(insert(root->GetLeft(), value));
        } else if (value > root->GetData()) {
            root->SetRight(insert(root->GetRight(), value));
        }
        return root;
    }

    // Hàm tìm kiếm phần tử (đệ quy)
    bool search(Node<T>* root, T value) {
        if (root == nullptr) return false;
        if (root->GetData() == value) return true;
        if (value < root->GetData()) {
            return search(root->GetLeft(), value);
        } else {
            return search(root->GetRight(), value);
        }
    }
};

#endif // BINARY_SEARCH_TREE_H
