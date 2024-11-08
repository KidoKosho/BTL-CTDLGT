#ifndef LIST_SV_H
#define LIST_SV_H

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <fstream>
#include "SinhVien.cpp"
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
                cerr << "Khong the mo file: " << filename << endl;
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
        //tim kiem
        void FindName(){
            cout <<"------------------------------------------------------\n";
            cout << "Nhap ten Sinh Vien muon tim:";
            string name;cin >> name;
            if(FindName(name)) cout << "Khong tim thay duoc sinh vien nao";
            else{
                InKetQua();
            }
            cout <<"------------------------------------------------------\n";
        }
        void FindMSV(){
            cout <<"------------------------------------------------------\n";
            cout << "Nhap Ma Sinh Vien muon tim:";
            string msv;cin >> msv;
            if(FindName(msv)) cout << "Khong tim thay duoc sinh vien nao";
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
            if(FindGPA(gpa,i)) cout << "Khong tim thay duoc sinh vien nao";
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
    for (auto sv : listsv) {
        if (sv.GetHovaten().find(ten) != string::npos) {
            kq.push_back(sv);
        }
    }
    return kq.size()!=0;
}
#endif // LIST_SV_H
