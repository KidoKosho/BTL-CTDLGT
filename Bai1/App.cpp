#ifndef APP_H
#define APP_H
#include "Danhsachsv.cpp"
#include <iostream>
#include <random>
#include<cstdlib>
#include <ctime>

using namespace std;
class App{
    private:    
        ListSV listsv;
    public:
        void AppStart();
        void Menu();
        void Them();
        void Xoa();
        void Timkiem();
        void Sapxep();        
        void Indanhsach();
};
void App::AppStart(){
    srand(time(0)); 
    string start;
    cout << "<----------CHAO MUNG BAN DA DEN APP CUA CHUNG TOI---------->" << endl;
    cout << "Nhan Enter de tiep tuc chuong trinh:";
    getline(cin,start);
    cout << "<-----------Let's go--------------->\n";
    this_thread::sleep_for(chrono::milliseconds(1500));
    int startapp = 0;
    do{
        int random = (rand()%15+15)%15+1;
        startapp +=random;
        if(startapp >=100) startapp = 100;
        cout << "Loadingg................................" << startapp << "%"<< endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }while(startapp < 100);
    cout << "<------------------App da load xong----------------------->" << endl;
    cout << "Nhan Enter de tiep tuc chuong trinh:";
    getline(cin,start);
    cout << "-------------------------------------------------------------\n";
    App::Menu();
}
void App::Menu(){//done
    this_thread::sleep_for(chrono::milliseconds(500));
    cout <<"---------MENU--------\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    cout <<"|     1.Them         |\n";       
    this_thread::sleep_for(chrono::milliseconds(200));
    cout <<"|     2.Xoa          |\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    cout <<"|     3.tim kiem     |\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    cout <<"|     4.Sapxep       |\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    cout <<"|     5.Indanhsach   |\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    cout <<"|     6.Thoat        |\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    cout <<"---------------------\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "Nhap so muon chon:";
    int chon;
    do{
        cin >> chon;
        if(chon<1 ||chon>6) cout <<"Nhap lai gia tri tu 1->5:";
    }while(chon<1 ||chon>6);
    if(chon == 6) return;
    else if(chon == 1) Them();
    else if(chon == 2) Xoa();
    else if(chon == 3) Timkiem();
    else if(chon == 4) Sapxep();
    else if(chon ==5) Indanhsach();
}
void App::Them(){//done
    this_thread::sleep_for(chrono::milliseconds(500));
    cout <<"-----------------\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "1.Nhap sinh vien bang file\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "2.Nhap them sinh vien\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "3.Menu\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    cout <<"-----------------\n";
    int chon;
    do{    
        cin >> chon;
        if(chon< 1 ||chon > 3) cout <<"Nhap lai gia tri tu 1->3:";
    }while(chon < 1 || chon >3);
    if(chon == 1){
        listsv.AddSvFromFile();
        Them();
    }
    else if(chon==2){
        listsv.NhapDanhSachSV();
        Them();
    }
    else if(chon==3){
        Menu();
    }
}
void App::Xoa(){//done
    if(listsv.GetKq().size()==0){
        cout <<"------------------------------------------------------\n";
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "Hay tim kiem sinh vien theo ten hoac tat ca sinh vien\n";    
        this_thread::sleep_for(chrono::milliseconds(300));
        cout << "1.Tim kiem theo Ten:\n";
        this_thread::sleep_for(chrono::milliseconds(200));
        cout << "2.Tim kiem theo MSV:\n";
        this_thread::sleep_for(chrono::milliseconds(200));        
        cout << "3.Tim kiem theo GPA:\n";
        this_thread::sleep_for(chrono::milliseconds(200));
        cout << "4.Tat ca sinh vien\n";
        this_thread::sleep_for(chrono::milliseconds(200));
        cout << "5.Menu\n";
        cout <<"------------------------------------------------------\n";
        int chon;
        do{
            cin >> chon;
            if(chon < 1 || chon > 5) cout << "Hay chon lai\n";
        }while(chon < 1 || chon > 5);
        listsv.InKetQua();
        if(chon == 5){
            Menu();
            return;
        }
    }
    listsv.Remove();
    Xoa();
}
void App::Timkiem(){//done
    this_thread::sleep_for(chrono::milliseconds(500));
    cout <<"-------------------------TimKiem--------------------------\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "1.Tim kiem theo Ten:\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "2.Tim kiem theo MSV:\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "3.Tim kiem theo GPA:\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "4.Menu:\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    cout <<"------------------------------------------------------\n";
    int chon;
    cout << "Muon chon:";
    do{    
        cin >> chon;
        if(chon<1 ||chon>4) cout <<"Nhap lai gia tri tu 1->4:";
    }while(chon<1 ||chon>4);
    if(chon==4){
        Menu();
        return;
    }
    if(chon == 1) listsv.FindName();
    else if(chon == 2) listsv.FindMSV();
    else if(chon == 3) listsv.FindGPA();
    Timkiem();
}
void App::Sapxep(){//done
    cout <<"----------------------Sapxep------------------------------\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "1.Sapxep theo Ten:\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "2.Sapxep theo MSV:\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "3.Sapxep theo GPA:\n";
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "4.Menu:\n";
    cout <<"------------------------------------------------------\n";
    int chon;
    cout << "Muon chon:";
    do{    
        cin >> chon;
        if(chon<1 ||chon>4) cout <<"Nhap lai gia tri tu 1->4:";
    }while(chon<1 ||chon>4);
    cout <<"----------------------------------\n";
    if(chon == 1) listsv.SortName();
    else if(chon == 2) listsv.SortMSV();
    else if(chon == 3) listsv.SortGPA();
    else if(chon == 4){
        App::Menu();
        return;
    }
    Sapxep();
}
void App::Indanhsach(){//done
    listsv.HienThiDanhSach();
    string tieptuc;
    cin.ignore();
    cout <<"Nhan Enter de tiep tuc:";
    getline(cin,tieptuc);
    cout <<"-----------------\n";
    cout <<"1.Muon xem lai\n";
    cout << "2.Menu\n";
    cout <<"-----------------\n";
    int chon;
    cout << "chon thu tu:";
    do{
        cin >> chon;
        if(chon < 1 || chon >2) cout << "Chon lai du lieu!!!\n";
    }while(chon < 1|| chon > 2);
    cout <<"-----------------\n";
    if(chon == 1) App::Indanhsach();
    else if(chon == 2) App::Menu();
}

#endif