#ifndef APP_H
#define APP_H
#include "Danhsachsv.cpp"
#include <iostream>
using namespace std;
class App{
    private:    
        ListSV listsv;
    public:
        void Menu(){//done
            cout <<"-----------------\n";
            cout <<"1.Them\n";
            cout <<"2.Xoa\n";
            cout <<"3.tim kiem\n";
            cout <<"4.Sapxep\n";
            cout <<"5.Indanhsach\n";
            cout <<"6.Thoat\n";
            cout <<"-----------------\n";
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
        void Them(){//done
            cout <<"-----------------\n";
            cout << "1.Nhap them sinh vien\n";
            cout << "2.Menu\n";
            cout <<"-----------------\n";
            int chon;
            do{    
                cin >> chon;
                if(chon< 1 ||chon > 2) cout <<"Nhap lai gia tri tu 1->2:";
            }while(chon < 1 && chon >2);
            if(chon==1){
                listsv.NhapDanhSachSV();
                Them();
            }
            else if(chon==2){
                Menu();
            }
        }
        void Xoa(){//done
            if(listsv.GetKq().size()==0){
                cout <<"------------------------------------------------------\n";
                cout << "Hay tim kiem sinh vien theo ten hoac tat ca sinh vien\n";
                cout << "1.Tim kiem theo Ten:\n";
                cout << "2.Tim kiem theo MSV:\n";
                cout << "3.Tim kiem theo GPA:\n";
                cout << "4.Tat ca sinh vien\n";
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
        void Timkiem(){//done
            cout <<"------------------------------------------------------\n";
            cout << "1.Tim kiem theo Ten:\n";
            cout << "2.Tim kiem theo MSV:\n";
            cout << "3.Tim kiem theo GPA:\n";
            cout << "4.Menu:\n";
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
        void Sapxep(){//done
            cout <<"------------------------------------------------------\n";
            cout << "1.Sapxep theo Ten:\n";
            cout << "2.Sapxep theo MSV:\n";
            cout << "3.Sapxep theo GPA:\n";
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
            Sapxep();
        }
        void Indanhsach(){//done
            listsv.HienThiDanhSach();
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
            if(chon == 1) Indanhsach();
            else if(chon == 2) Menu();
        }
};
#endif