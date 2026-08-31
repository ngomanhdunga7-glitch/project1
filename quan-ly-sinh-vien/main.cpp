#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// 1. Định nghĩa cấu trúc 1 Sinh Viên
struct SinhVien {
    string maSV;
    string hoTen;
    float diemTB;
};

// Khai báo các hàm xử lý
void nhapSinhVien(SinhVien &sv);
void inSinhVien(const SinhVien &sv);
void hienThiDanhSach(const vector<SinhVien> &ds);

int main() {
    vector<SinhVien> dsSinhVien; // Danh sách chứa các sinh viên
    int luaChon;

    do {
        cout << "\n====================================\n";
        cout << "   CHUONG TRINH QUAN LY SINH VIEN   \n";
        cout << "====================================\n";
        cout << "1. Them sinh vien moi\n";
        cout << "2. Hien thi danh sach sinh vien\n";
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
            case 0:
                cout << "Cam on ban da su dung chuong trinh!\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai!\n";
        }
    } while (luaChon != 0);

    return 0;
}

// Hàm nhập thông tin 1 sinh viên
void nhapSinhVien(SinhVien &sv) {
    cout << "Nhap Ma Sinh Vien: ";
    cin.ignore(); // Xóa bộ nhớ đệm
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

// Hàm hiển thị toàn bộ danh sách
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
