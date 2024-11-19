#include "BinarySearchTree.h"
#include "BinaryTree.h"

int main() {
    AbstractTree<int>* BT = new BinaryTree<int>();
    cout << "Nhap gia tri cua n:";
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Nhap gia tri cua x de them vao cay : ";
        int x;
        cin >> x;
        BT->insert(x);
    }
    cout << "1.1)Duong di tu goc den cac la : \n";
    BT->ShowPaths();// đường đi từ gốc đến các lá
    cout << "1.2)Tong tat ca cac so tu goc den la : ";
    cout << BT->SumTree() << endl;
    cout << "1.3)Nhap gia tri cua y de tim duong tu diem tu diem den cac node co gia tri bang y : ";
    int y;cin>>y;
    cout << "Vay duong di cua cay nhi phan de co duong di la " << y <<" :\n";
    if(BT->FindSum(y)){
    }
    else{
        cout << "Khong co duong di nao"<< " \n";
    }
    delete BT;
    return 0;
    