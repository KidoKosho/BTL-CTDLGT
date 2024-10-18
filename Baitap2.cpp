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

template <typename T>
class Tree {
    private:
        Node<T>* tree;
        long long sumTree =0;
        vector<string> path;
    public:
        Tree() { tree = nullptr; }
        vector<string> GetPath(){return path;}
        void add(T value) {
            tree = add(tree, value);
        }
        Node<T>* add(Node<T>* root, T value) {//cay nhi phan hoan chinh
            if (root == nullptr) return new Node<T>(value);
            else if (value < root->GetData()) root->SetLeft(add(root->GetLeft(), value));
            else if (value > root->GetData()) root->SetRight(add(root->GetRight(), value));
            return root;
        }
        Node<T>* addLeft(Node<T>*root,T value){// them ngay ben trai cua node day
            Node<T>* node = new Node<T>(value);
            if(root == nullptr) return node;
            else if(root->GetLeft()==nullptr) root->SetLeft(node);
            else{
                node-> SetLeft(root->GetLeft());
                root->SetLeft(node);
            }
            return root;
        }
        Node<T>* addRight(Node<T>*root,T value){//them vao node ngay ben phai
            Node<T>* node = new Node<T>(value);
            if(root == nullptr) return node;
            else if(root->GetRight()==nullptr) root->SetRight(node);
            else{
                node-> SetRight(root->GetRight());
                root->SetRight(node);
            }
            return root;
        }
        Node<T>* addLeftEnd(Node<T>*root,T value){//them vao node cuoi cung ban trai cua node nay
            if (root == nullptr) return new Node<T>(value);
            root->SetLeft(add(root->GetLeft(), value));
            return root;
        }
        Node<T>* addRightEnd(Node<T>*root,T value){//them vao node cuoi cung cua ban phai cua node nay
            if (root == nullptr) return new Node<T>(value);
            root->SetRight(add(root->GetRight(), value));
            return root;
        }
        void ShowPaths() {
            if (tree == nullptr) {
                cout << "Cây rỗng!" << endl;
                return;
            }
            ShowPaths(tree, "");
        }
        void ShowPaths(Node<T>* node, string path) {
            if (node == nullptr) return;

            if (path.empty())
                path = to_string(node->GetData());
            else
                path += " -> " + to_string(node->GetData());

            if (node->GetLeft() == nullptr && node->GetRight() == nullptr) {
                cout << "Đường dẫn: " << path << endl;
                return;
            }
            ShowPaths(node->GetLeft(), path);
            ShowPaths(node->GetRight(), path);
        }
        long long SumTree(){
            SumTree(tree,0);
            return sumTree;
        }
        void SumTree(Node<T> *node ,long long value){
            if(node==nullptr) {
                return;
            }
            value = value*10+node->GetData();
            if(node->GetLeft()==nullptr&&node->GetRight() == nullptr){sumTree+=value;return;}
            SumTree(node->GetLeft(),value);
            SumTree(node->GetRight(),value);
        }
        bool FindSum(long long a){
            this->path.clear();
            FindSum(tree,a,0,"");
            return path.size() != 0;
        }
        void FindSum(Node<T>* node,long long a,long long value,string path){
            if(node==nullptr) return;
            value+=node->GetData();
            if (path.empty())
            {
                path = to_string(node->GetData());
            }
            else path+= "->"+to_string(node->GetData());
            if(value == a){
                this->path.push_back(path);
            }
            FindSum(node->GetLeft(),a,value,path);
            FindSum(node->GetRight(),a,value,path);
        }
        ~Tree() {
            delete tree;
        }
};

int main() {
    Tree<int>* BST = new Tree<int>();
    cout << "Nhap gia tri cua n:";
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        BST->add(x);
    }
    cout << "Nhap gia tri cua y:";
    int y;cin>>y;
    if(BST->FindSum(y)){
        for(auto x:BST->GetPath()){cout << x << endl;}
    }
    else{
        cout << "Khong co duong di nao co gia tri bang y\n";
    }
    delete BST;
    return 0;
}