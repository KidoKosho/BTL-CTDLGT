#include"Tree.cpp"

int main() {
    Tree<int>* BST = new Tree<int>();
    cout << "Nhap gia tri cua n:";
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Nhap gia tri cua x de them vao cay : ";
        int x;
        cin >> x;
        BST->add(x);
    }
    cout << "Nhap gia tri cua y de tim duong tu diem tu diem den cac node co gia tri bang y:";
    int y;cin>>y;
    if(BST->FindSum(y)){
        for(auto x:BST->GetPath()){cout << x << endl;}
    }
    else{
        cout << "Khong co duong di nao co gia tri bang " << y << " \n";
    }
    delete BST;
    return 0;
}