#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct SinhVien {
    string maSV;
    string hoTen;
    float diemTB;
};

void nhapSinhVien(SinhVien &sv);
void inSinhVien(const SinhVien &sv);
void hienThiDanhSach(const vector<SinhVien> &ds);
void timKiemSinhVien(const vector<SinhVien> &ds);
void sapxep(vector<SinhVien> &ds);
void suathongtin(vector<SinhVien> &ds);
void xoathongtin(vector<SinhVien> &ds);

int main() {
    vector<SinhVien> dsSinhVien;
    int luaChon;

    do {
        cout << "\n====================================\n";
        cout << "   CHUONG TRINH QUAN LY SINH VIEN   \n";
        cout << "====================================\n";
        cout << "1. Them sinh vien moi\n";
        cout << "2. Hien thi danh sach sinh vien\n";
        cout << "3. Tim kiem sinh vien\n";
        cout << "4. Sap xep sinh theo diem trung binh cao den thap\n";
        cout << "5. Sua thong tin sinh vien\n";
        cout << "6. Xoa thong tin sinh vien\n";
        cout << "0. Thoat\n";
        cout << "------------------------------------\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1: {
                SinhVien sv;
                nhapSinhVien(sv);
                dsSinhVien.push_back(sv);
                cout << "=> Them sinh vien thanh cong!\n";
                break;
            }
            case 2:
                hienThiDanhSach(dsSinhVien);
                break;
            case 3:
                timKiemSinhVien(dsSinhVien);
                break;
            case 4:
                sapxep(dsSinhVien);
                break;
            case 5:
                suathongtin(dsSinhVien);
                break;
            case 6:
                xoathongtin(dsSinhVien);
                break;
            case 0:
                cout << "Cam on ban da su dung chuong trinh!\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai!\n";
        }
    } while (luaChon != 0);

    return 0;
}

void nhapSinhVien(SinhVien &sv) {
    cout << "Nhap Ma Sinh Vien: ";
    cin.ignore();
    getline(cin, sv.maSV);
    cout << "Nhap Ho va Ten: ";
    getline(cin, sv.hoTen);
    cout << "Nhap Diem Trung Binh: ";
    cin >> sv.diemTB;
}

// Hàm in thông tin 1 sinh viên
void inSinhVien(const SinhVien &sv) {
    cout << left << setw(15) << sv.maSV
         << setw(25) << sv.hoTen
         << setw(10) << fixed << setprecision(2) << sv.diemTB << endl;
}

void hienThiDanhSach(const vector<SinhVien> &ds) {
    if (ds.empty()) {
        cout << "\nDanh sach hien tai dang rong!\n";
        return;
    }
    cout << "\n--- DANH SACH SINH VIEN ---\n";
    cout << left << setw(15) << "Ma SV"
         << setw(25) << "Ho Ten"
         << setw(10) << "Diem TB" << endl;
    cout << "--------------------------------------------------\n";
    for (const auto &sv : ds) {
        inSinhVien(sv);
    }
}

void timKiemSinhVien(const vector<SinhVien> &ds ){
    if(ds.empty()){
        cout<<"danh sach trong!\n";
        return;
    }
    string id;
    cout<<"Nhap ma sinh vien can tim: ";
    cin>>id;
    bool timthay= false;
    for(int i=0;i<ds.size();i++){
        if(id== ds[i].maSV){
            cout<<"thong tin sinh vien co ma "<<ds[i].maSV<<" la: "<<ds[i].hoTen<<" voi diem trung binh: "<<ds[i].diemTB<<endl;
            timthay=true;
            break;
        }
    }
    if(timthay!=true){
        cout<<"\n KHONG TIM THAY SINH VIEN TUONG UNG!\n";
    }
}

void sapxep(vector<SinhVien> &ds){
    if(ds.empty()){
        cout<<"danh sach trong!\n";
        return;
    }
    SinhVien temp;
    for(int i=0;i<ds.size()-1;i++){
        for(int j=i+1;j<ds.size();j++)
        if(ds[i].diemTB<ds[j].diemTB){
            temp=ds[i];
            ds[i]=ds[j];
            ds[j]=temp;
        }
    }
    hienThiDanhSach(ds);
}

void suathongtin(vector<SinhVien> &ds){
    if(ds.empty()){
        return;
    }
    bool timthay =false;
    string id;
    cout<<"Nhap ma so sinh vien can sua: ";
    cin>>id;
    for(int i=0;i<ds.size();i++){
        if(ds[i].maSV==id){
            cout<<"\n--- Nhap thong tin moi cho sinh vien "<<ds[i].maSV<<" ---\n";
            cout<<"Ho ten moi: ";
            cin.ignore();
            getline(cin,ds[i].hoTen);
            cout<<"Diem trung binh moi: ";
            cin>>ds[i].diemTB;
            timthay = true;
            break;
        }
    }
    if(timthay==false){
        cout<<"khong tim thay sinh vien hop le!\n";
    }
}

void xoathongtin(vector<SinhVien> &ds){
    if(ds.empty()){
        return;
    }
    bool timthay=false;
    string id;
    cout<<"Nhap sinh vien can xoa: ";
    cin>>id;
    int vitrixoa =-1;
    for(int i=0;i<ds.size();i++){
        if(id==ds[i].maSV){
            vitrixoa=i;
            break;
        }
    }
    if(vitrixoa!=-1){
        for(int i=vitrixoa; i<ds.size()-1;i++){
            ds[i]=ds[i+1];
        }
        ds.pop_back();
        cout<<"da xoa sinh vien "<< id<<endl;
    }
    else{
        cout<<"khong co thong tin sinh vien can xoa!\n";
    }

}
