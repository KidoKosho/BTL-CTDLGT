#ifndef SINH_VIEN_H
#define SINH_VIEN_H
    #include <iostream>
    #include <string>
    #include <thread>
    #include <chrono>
using namespace std;

class SinhVien {
    private:
        string msv, hovaten, ngaysinh, gioitinh, diachi, sodienthoai, email;
        float GPA;

    public:
        // Constructo r mặc định
        SinhVien() : msv(""), hovaten(""), ngaysinh(""), gioitinh(""), diachi(""), sodienthoai(""), email(""), GPA(-1) {}

        // Constructor có tham số
        SinhVien(string msv, string hovaten, string ngaysinh, string gioitinh, string diachi, string sodienthoai, string email, float GPA)
            : msv(msv), hovaten(hovaten), ngaysinh(ngaysinh), gioitinh(gioitinh), diachi(diachi), sodienthoai(sodienthoai), email(email), GPA(GPA) {}

        // Getter
        string GetMSV() const{ return msv; }
        string GetHovaten() const { return hovaten; }
        string GetNgaysinh() const { return ngaysinh; }
        string GetGioitinh() const{ return gioitinh; }
        string GetDiachi() const{ return diachi; }
        string GetSodienthoai() const{ return sodienthoai; }
        string GetEmail() const{ return email; }
        float GetGPA() const{ return GPA; }

        // Setter
        void SetMSV(string msv) { this->msv = msv; }
        void SetHovaten(string hovaten) { this->hovaten = hovaten; }
        void SetNgaysinh(string ngaysinh) { this->ngaysinh = ngaysinh; }
        void SetGioitinh(string gioitinh) { this->gioitinh = gioitinh; }
        void SetDiachi(string diachi) { this->diachi = diachi; }
        void SetSodienthoai(string sodienthoai) { this->sodienthoai = sodienthoai; }
        void SetEmail(string email) { this->email = email; }
        void SetGPA(float value) { this->GPA = value; }

        // Hàm hiển thị thông tin sinh viên
        void HienThiThongTin();

        // Toán tử nhập và xuất
        friend ostream& operator<<(ostream& os, const SinhVien& sv);
        friend istream& operator>>(istream& is, SinhVien& sv);
        bool operator < (const SinhVien& other) const{
            return this->hovaten < other.hovaten;
        }
        bool operator==(const SinhVien& other) const {
            return (this->GetMSV() == other.GetMSV());
        }

};

void SinhVien::HienThiThongTin() {
    cout << "Thong tin sinh vien:" << endl;
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "MSV: " << msv << endl;
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "Ho va ten: " << hovaten << endl;
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "Ngay sinh: " << ngaysinh << endl;
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "Gioi tinh: " << gioitinh << endl;
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "Dia chi: " << diachi << endl;
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "So dien thoai: " << sodienthoai << endl;
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "Email: " << email << endl;
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "GPA: " << GPA << endl;
    this_thread::sleep_for(chrono::milliseconds(200));
}

// Toán tử nhập cho SinhVien
istream& operator>>(istream& is, SinhVien& sv) {
    cout << "Nhap ma sinh vien: ";
    is >> sv.msv;
    cout << "Nhap ho va ten: ";
    is.ignore(); 
    getline(is, sv.hovaten);
    cout << "Nhap ngay sinh: ";
    is >> sv.ngaysinh;
    cout << "Nhap gioi tinh: ";
    is >> sv.gioitinh;
    cout << "Nhap dia chi: ";
    is.ignore();
    getline(is, sv.diachi);
    cout << "Nhap so dien thoai: ";
    is >> sv.sodienthoai;
    cout << "Nhap email: ";
    is >> sv.email;
    cout << "Nhap GPA: ";
    is >> sv.GPA;
    return is;
}

// Toán tử xuất cho SinhVien
ostream& operator<<(ostream& os, const SinhVien& sv) {
    os << "MSV: " << sv.msv << endl;
    this_thread::sleep_for(chrono::milliseconds(200));
    os << "Ho va ten: " << sv.hovaten << endl;
    this_thread::sleep_for(chrono::milliseconds(200));
    os << "Ngay sinh: " << sv.ngaysinh << endl;
    this_thread::sleep_for(chrono::milliseconds(200));
    os << "Gioi tinh: " << sv.gioitinh << endl;
    this_thread::sleep_for(chrono::milliseconds(200));
    os << "Dia chi: " << sv.diachi << endl;
    this_thread::sleep_for(chrono::milliseconds(200));
    os << "So dien thoai: " << sv.sodienthoai << endl;
    this_thread::sleep_for(chrono::milliseconds(200));
    os << "Email: " << sv.email << endl;
    this_thread::sleep_for(chrono::milliseconds(200));
    os << "GPA: " << sv.GPA << endl;
    return os;
}
#endif // SINH_VIEN_H
