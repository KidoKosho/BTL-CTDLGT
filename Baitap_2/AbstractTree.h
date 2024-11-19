#ifndef AbstractTree_H
#define AbstractTree_H
#include "Node.h"
#include <thread>
#include <chrono>
#include "QUEUE.h"

template <typename T>
class AbstractTree {
protected:
    Node<T>* root;
    long long sumTree; // Biến lưu tổng
    int CountPath = 0;

    // Hàm đệ quy tính tổng từ nút đến lá
    void SumTree(Node<T>* node, long long value) {
        if (node == nullptr) return;

        value = value * 10 + node->GetData();

        if (node->GetLeft() == nullptr && node->GetRight() == nullptr) {
            sumTree += value;
            return;
        }

        SumTree(node->GetLeft(), value);
        SumTree(node->GetRight(), value);
    }

    // Hàm đệ quy tìm đường đi với tổng bằng giá trị cho trước
    void FindSum(Node<T>* node, long long a, long long value, string currentPath) {
        if (node == nullptr) return;

        value += node->GetData();
        currentPath += currentPath.empty() ? to_string(node->GetData()) : " -> " + to_string(node->GetData());

        if (value == a) {
            CountPath ++;
            cout << currentPath << endl;
        }

        FindSum(node->GetLeft(), a, value, currentPath);
        FindSum(node->GetRight(), a, value, currentPath);
    }

    // Hàm đệ quy hiển thị tất cả đường đi từ gốc đến lá
    void ShowPaths(Node<T>* node, string currentPath) {
        if (node == nullptr) return;

        currentPath += currentPath.empty() ? to_string(node->GetData()) : " -> " + to_string(node->GetData());

        if (node->GetLeft() == nullptr && node->GetRight() == nullptr) {
            cout << "Duong di: " << currentPath << endl;
            return;
        }

        ShowPaths(node->GetLeft(), currentPath);
        ShowPaths(node->GetRight(), currentPath);
    }

    // Hàm đệ quy duyệt PreOrder
    void PreOrder(Node<T>* node) const {
        if (node == nullptr) return;
        cout << node->GetData() << " ";
        PreOrder(node->GetLeft());
        PreOrder(node->GetRight());
    }

    // Hàm đệ quy duyệt InOrder
    void InOrder(Node<T>* node) const {
        if (node == nullptr) return;
        InOrder(node->GetLeft());
        cout << node->GetData() << " ";
        InOrder(node->GetRight());
    }

    // Hàm đệ quy duyệt PostOrder
    void PostOrder(Node<T>* node) const {
        if (node == nullptr) return;
        PostOrder(node->GetLeft());
        PostOrder(node->GetRight());
        cout << node->GetData() << " ";
    }

    // Hàm duyệt LevelOrder
    void LevelOrder(Node<T>* node) const {
        if (node == nullptr) return;
        QUEUE<Node<T>*> q;
        q.push(node);

        while (!q.size()) {
            Node<T>* current = q.front();
            q.pop();
            cout << current->GetData() << " ";
            if (current->GetLeft()) q.push(current->GetLeft());
            if (current->GetRight()) q.push(current->GetRight());
        }
    }
    virtual void clear(Node<T>* node) {
        if (node) {
            clear(node->GetLeft());
            clear(node->GetLeft());
            delete node;
        }
    }

public:
    AbstractTree() : root(nullptr), sumTree(0),CountPath(0) {}
    virtual void insert(T value) = 0; // Chèn nút (hàm ảo thuần túy)
    virtual ~AbstractTree(){clear(root);};
    // Hiển thị tất cả đường đi từ gốc đến lá
    void ShowPaths() {
        if (root == nullptr) {
            cout << "Cay rong!" << endl;
            return;
        }
        ShowPaths(root, "");
    }

    // Tính tổng từ gốc đến lá
    long long SumTree() {
        sumTree = 0;
        SumTree(root, 0);
        return sumTree;
    }

    // Tìm đường đi có tổng bằng giá trị cho trước
    bool FindSum(long long a) {
        CountPath  = 0;
        FindSum(root, a, 0, "");
        return CountPath;
    }
      virtual void printPreOrder() const {
        PreOrder(root);
        cout << endl;
    }

    virtual void printInOrder() const {
        InOrder(root);
        cout << endl;
    }

    virtual void printPostOrder() const {
        PostOrder(root);
        cout << endl;
    }

    virtual void printLevelOrder() const {
        LevelOrder(root);
        cout << endl;
    }
};

#endif