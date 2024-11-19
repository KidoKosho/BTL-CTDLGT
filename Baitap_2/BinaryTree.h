 #ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "AbstractTree.h"

template <typename T>
class BinaryTree : public AbstractTree<T> {
public:
    BinaryTree() : AbstractTree<T>() {}

    // Triển khai phương thức chèn nút theo duyệt chiều rộng
    void insert(T value) override {
        Node<T>* newNode = new Node<T>(value);
        if (this->root == nullptr) {
            this->root = newNode;
            return;
        }

        // Sử dụng hàng đợi để duyệt cây theo chiều rộng
        QUEUE<Node<T>*> q;
        q.push(this->root);

        while (q.size()) {
            Node<T>* current = q.front();
            q.pop();

            // Kiểm tra con trái
            if (current->GetLeft() == nullptr) {
                current->SetLeft(newNode);
                return;
            } else {
                q.push(current->GetLeft());
            }

            // Kiểm tra con phải
            if (current->GetRight() == nullptr) {
                current->SetRight(newNode);
                return;
            } else {
                q.push(current->GetRight());
            }
        }
    }
    void addLeft(Node<T>* parent, T value) {
        if (parent == nullptr) return;
        Node<T>* node = new Node<T>(value);
        if (parent->GetLeft() == nullptr) {
            parent->SetLeft(node);
        } else {
            node->SetLeft(parent->GetLeft());
            parent->SetLeft(node);
        }
    }

    // Thêm một nút ngay bên phải
    void addRight(Node<T>* parent, T value) {
        if (parent == nullptr) return;
        Node<T>* node = new Node<T>(value);
        if (parent->GetRight() == nullptr) {
            parent->SetRight(node);
        } else {
            node->SetRight(parent->GetRight());
            parent->SetRight(node);
        }
    }

    // Thêm một nút vào vị trí cuối cùng bên trái
    void addLeftEnd(Node<T>* parent, T value) {
        if (parent == nullptr) return;
        if (parent->GetLeft() == nullptr) {
            parent->SetLeft(new Node<T>(value));
        } else {
            addLeftEnd(parent->GetLeft(), value);
        }
    }

    // Thêm một nút vào vị trí cuối cùng bên phải
    void addRightEnd(Node<T>* parent, T value) {
        if (parent == nullptr) return;
        if (parent->GetRight() == nullptr) {
            parent->SetRight(new Node<T>(value));
        } else {
            addRightEnd(parent->GetRight(), value);
        }
    }
};

#endif // BINARY_TREE_H
