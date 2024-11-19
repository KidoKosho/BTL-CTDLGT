    #ifndef LIST_SV_H
    #define LIST_SV_H

    #include <iostream>
    #include <algorithm>
    #include <list>
    #include <vector>
    #include <fstream>
    #include "SinhVien.h"
    using namespace std;

    class ListSV {
        private:
            list<SinhVien> listsv; // Con trỏ đến danh sách sinh viên
            vector<SinhVien> kq;
            int soluong;  // Số lượng sinh viên

        public:
            ListSV(int size) : soluong(size) {
                NhapSV();
            }
            ListSV(){}
            ~ListSV() {
                Clear();
            }
            void NhapDanhSachSV(){
                this_thread::sleep_for(chrono::milliseconds(100));
                cout <<"------------------------------------------------------\n";
                this_thread::sleep_for(chrono::milliseconds(200));
                cout << "Nhap so luong sinh vien:";
                cin >> soluong;
                this_thread::sleep_for(chrono::milliseconds(100));
                cout <<"------------------------------------------------------\n";
                NhapSV();
            }
            void NhapSV() {
                for (int i = 0; i < soluong; ++i) {
                    cout <<"------------------------------------------------------\n";
                    this_thread::sleep_for(chrono::milliseconds(200));
                    cout << "Nhap thong tin cho sinh vien " << (i + 1) << ":" << endl;
                    this_thread::sleep_for(chrono::milliseconds(200));
                    cout <<"------------------------------------------------------\n";
                    AddSv();
                }
            }
            void AddSvFromFile(){
                ifstream file;
                do{
                    cout << "Nhap dia chi file:";
                    string filename;
                    cin >> filename;
                    file.open(filename);
                    if(!file.is_open())cout << "Khong the mo file: " << filename << endl;
                }while (!file.is_open());
                AddSvFromFile(file);
            }
            void AddSvFromFile(ifstream& file) {
                string msv, hovaten, ngaysinh, gioitinh, diachi, sodienthoai, email;
                float GPA;
                while (getline(file, msv, ',')) {
                    getline(file, hovaten, ',');
                    getline(file, ngaysinh, ',');
                    getline(file, gioitinh, ',');
                    getline(file, diachi, ',');
                    getline(file, sodienthoai, ',');
                    getline(file, email, ',');
                    file >> GPA;
                    file.ignore(); // Bỏ qua ký tự xuống dòng

                    // Tạo đối tượng SinhVien từ dữ liệu đọc được
                    SinhVien sv(msv, hovaten, ngaysinh, gioitinh, diachi, sodienthoai, email, GPA);

                    // Thêm vào danh sách sinh viên
                    SaveSvToFile(sv);
                    listsv.push_back(sv);
                }

                file.close();
                cout << "Da them sinh vien tu file: " << endl;
            }
            void ThaydoithongtinSinhVien(){
                cout <<"------------------------------------------------------\n";
                cout << "Nhap ten MSV muon tim:";
                string msv;cin >> msv;
                if(!FindMSV(msv)) cout << "Khong tim thay duoc sinh vien nao";
                else{
                    for(int i=0;i<(int)kq.size();i++){
                        cout <<"Thu tu " << i+1 << ":\n " << kq[i] << endl;
                    }
                    cout << "nhap so thu tu sinh vien muon thay doi";
                    int n;
                    cin >> n;
                    if(n <= (int)kq.size()&&n>0)Thaydoithongtin(kq[n-1]);
                }
                cout <<"------------------------------------------------------\n";
            }
            void HienThiDanhSach() {
                kq.clear();
                cout <<"-----------------\n";
                if(listsv.size()==0) cout << "Chua co du lieu sinh vien nao!!!\n";
                for(auto it : listsv){
                    this_thread::sleep_for(chrono::milliseconds(200));
                    kq.push_back(it);
                    cout << it << endl;
                }
            }
            //Sap xep 
            void SortName() {// Sắp xếp theo tên
                listsv.sort([](SinhVien& a, SinhVien& b) {
                    return a.GetHovaten() < b.GetHovaten();
                });
            }
            void SortMSV() {// Sắp xếp theo MSV
                listsv.sort([](SinhVien& a, SinhVien& b) {
                    return a.GetMSV() < b.GetMSV();
                });
            }
            void SortGPA() {// Sắp xếp theo GPA
                listsv.sort([](SinhVien& a,SinhVien& b) {
                    return a.GetGPA() > b.GetGPA();
                });
            }

            //Them hoac xoa sinh vien
            void Remove(){
                cout <<"------------------------------------------------------\n";
                cout << "Nhap thu tu sinh vien muon xoa";
                int thutu;
                cin >> thutu;
                cout <<"------------------------------------------------------\n";
                if (thutu < 1 || thutu > (int)kq.size()){
                    cout << "nhap thu tu sai\n";  
                }
                else{
                    Remove(kq[thutu-1]);
                    cout << "Da xoa xong\n";
                }
            }
            void Remove(SinhVien sv){
                listsv.remove(sv);
            }
            void Clear(){
                listsv.clear();
            }
            void AddSv(){
                SinhVien sv;
                cin >> sv; // Nhập thông tin sinh viên
                listsv.push_back(sv);
                SaveSvToFile(sv);
            }
            void AddSv(SinhVien sv){
                listsv.push_back(sv);
            }
            void SaveSvToFile(const SinhVien& sv) {
                ofstream file;
                file.open("E:/Code/Cpp/BTL_CTDL_GT/Bai1/SinhVienData.txt", ios::app); // Mở file ở chế độ append

                if (file.is_open()) {
                // Lưu thông tin sinh viên vào file theo định dạng
                    file << sv.GetMSV() << ","
                    << sv.GetHovaten() << ","
                    << sv.GetNgaysinh() << ","
                    << sv.GetGioitinh() << ","
                    << sv.GetDiachi() << ","
                    << sv.GetSodienthoai() << ","
                    << sv.GetEmail() << ","
                    << sv.GetGPA() << endl;

                    file.close(); // Đóng file sau khi ghi xong
                    cout << "Thong tin sinh vien da duoc luu vao file." << endl;
                } 
                else {
                    cerr << "Khong the mo file de luu du lieu." << endl;
                }
            }
            void SavetoFileLoad(){
                ofstream file;
                file.open("E:/Code/Cpp/BTL_CTDL_GT/Bai1/SinhVienData.txt", ios::app); // Mở file ở chế độ append

                if (file.is_open()) {
                    for(auto sv : listsv){
                // Lưu thông tin sinh viên vào file theo định dạng
                        file << sv.GetMSV() << ","
                        << sv.GetHovaten() << ","
                        << sv.GetNgaysinh() << ","
                        << sv.GetGioitinh() << ","
                        << sv.GetDiachi() << ","
                        << sv.GetSodienthoai() << ","
                        << sv.GetEmail() << ","
                        << sv.GetGPA() << endl;

                        file.close(); // Đóng file sau khi ghi xong
                    }
                    cout << "Thong tin sinh vien da duoc luu vao file." << endl;
                } 
                else {
                    cerr << "Khong the mo file de luu du lieu." << endl;
                }
            }
            //tim kiem
            void FindName(){
                cout <<"------------------------------------------------------\n";
                cout << "Nhap ten Sinh Vien muon tim:";
                string name;cin.ignore();
                getline(cin,name);
                if(!FindName(name)) cout << "Khong tim thay duoc sinh vien nao\n";
                else{
                    InKetQua();
                }
                cout <<"------------------------------------------------------\n";
            }
            void FindMSV(){
                cout <<"------------------------------------------------------\n";
                cout << "Nhap Ma Sinh Vien muon tim:";
                string msv;cin.ignore();cin >> msv;
                if(!FindMSV(msv)) cout << "Khong tim thay duoc sinh vien nao\n";
                else{
                    InKetQua();
                }
                cout <<"------------------------------------------------------\n";
            }
            void FindGPA(){
                cout <<"------------------------------------------------------\n";
                cout << "Nhap GPA muon tim : ";
                float gpa ;cin >> gpa;
                cout << "Tim kiem :\n 0.Bang\n 1.Nho\n 2.Hon\n";
                int i;
                do{
                    cin >> i;
                }while(i < 0 || i>2);
                if(!FindGPA(gpa,i)) cout << "Khong tim thay duoc sinh vien nao\n";
                else{
                    InKetQua();
                }
                cout <<"------------------------------------------------------\n";
            }
            bool FindName(string ten);
            bool FindMSV(string msv);
            bool FindGPA(float gpa,int i);
            bool GPAMax(){
                SinhVien svGPA = *listsv.begin();
                for (auto sv : listsv) {
                    if(svGPA.GetGPA() < sv.GetGPA()) svGPA=sv;
                }
                for (auto sv : listsv) {
                    if(svGPA.GetGPA() == sv.GetGPA()) kq.push_back(sv);
                }
                return kq.size()!=0;
            };
            bool GPAMin(){
                SinhVien svGPA = *listsv.begin();
                for (auto sv : listsv) {
                    if(svGPA.GetGPA() > sv.GetGPA()) svGPA=sv;
                }
                for (auto sv : listsv) {
                    if(svGPA.GetGPA() == sv.GetGPA()) kq.push_back(sv);
                }
                return kq.size()!=0;
            };
            // Thay doi thong tin sinh vien
            void Thaydoithongtin(SinhVien sv){
                cout << sv;
                cout <<"--------------------Muon thay doi----------------------------\n";
                this_thread::sleep_for(chrono::milliseconds(200));
                cout <<"1.MSV\n";
                this_thread::sleep_for(chrono::milliseconds(200));
                cout <<"2.Ho va ten\n";
                this_thread::sleep_for(chrono::milliseconds(200));
                cout <<"3.Ngay sinh\n";
                this_thread::sleep_for(chrono::milliseconds(200));
                cout <<"4.Gioi tinh\n";
                this_thread::sleep_for(chrono::milliseconds(200));
                cout <<"5.Dia chi\n";
                this_thread::sleep_for(chrono::milliseconds(200));
                cout <<"6.So dien thoai\n";
                this_thread::sleep_for(chrono::milliseconds(200));
                cout <<"7.Email\n";
                this_thread::sleep_for(chrono::milliseconds(200));
                cout <<"8.GPA\n";
                this_thread::sleep_for(chrono::milliseconds(200));
                cout <<"9.Khong thay doi nua\n";
                cout <<"-----------------------------------------------------------\n";
                int n;
                do{
                    cin >> n;
                    if(n<1||n>9) cout << "Nhap lai so muon chon:";
                }while(n<1||n>9);
                if(n==9) return;
                if(n==8){
                    cout << "Nhap GPA muon thay doi:";
                    float t;
                    cin >> t;
                    sv.SetGPA(t);
                }else{
                    string newValue,oldValue;
                    cout << "Nhap gia tri moi: ";
                    cin.ignore();
                    getline(cin, newValue);
                    switch (n) {
                    case 1:
                        oldValue = sv.GetMSV();
                        sv.SetMSV(newValue);
                        break;
                    case 2:
                        oldValue = sv.GetHovaten();
                        sv.SetHovaten(newValue);
                        break;
                    case 3:
                        oldValue = sv.GetNgaysinh();
                        sv.SetNgaysinh(newValue);
                        break;
                    case 4:
                        oldValue = sv.GetGioitinh();
                        sv.SetGioitinh(newValue);
                        break;
                    case 5:
                        oldValue = sv.GetDiachi();
                        sv.SetDiachi(newValue);
                        break;
                    case 6:
                        oldValue = sv.GetSodienthoai();
                        sv.SetSodienthoai(newValue);
                        break;
                    case 7:
                        oldValue = sv.GetEmail();
                        sv.SetEmail(newValue);
                        break;
                    }
                    cout << "da thay doi tu "  << oldValue << "->" << newValue << endl; 
                }
                cout << sv << endl;
                SavetoFileLoad();
                
            }
            //
            vector<SinhVien> GetKq(){return kq;}
            //in kqua tim kiem duoc
            void InKetQua(){
                if (kq.empty()) {
                    cout << "Khong co ket qua nao!!!!!" << endl;
                    return;
                }
                int i = 1;
                cout <<"---------------------------------------------------\n";
                for (auto x : kq) {
                this_thread::sleep_for(chrono::milliseconds(200));
                    cout << i++ << " : " << x << endl;
                }
                cout <<"----------------------------------------------------\n";
            }
    };
    bool ListSV::FindGPA(float gpa,int i){
        kq.clear();
        for (auto sv : listsv) {
            if (i == 1 && sv.GetGPA() -gpa < 0) {           // Tìm GPA bằng
                kq.push_back(sv);
            } else if (i == 0 && sv.GetGPA() - gpa < 0.001f) {      // Tìm GPA nhỏ hơn
                kq.push_back(sv);
            } else if (i == 2 && sv.GetGPA() > gpa) {      // Tìm GPA lớn hơn
                kq.push_back(sv);
            }
        }
        return kq.size()!=0;
    }
    bool ListSV::FindMSV(string msv){
        kq.clear();
        for (auto sv : listsv) {
            if (sv.GetMSV() == msv) {
                kq.push_back(sv);
            }
        }
        return kq.size()!=0;
    }
    bool ListSV::FindName(string ten){
        kq.clear();
        cout << ten;
        for (auto sv : listsv) {
            if (sv.GetHovaten().find(ten) != string::npos) {
                kq.push_back(sv);
            }
        }
        return kq.size()!=0;
    }
    #endif // LIST_SV_H
