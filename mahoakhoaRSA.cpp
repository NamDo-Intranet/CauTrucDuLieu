#include<iostream>
#include<cmath>
#include<cstring>
#include<sstream>
using namespace std;

// Hàm tính ước số chung lớn nhất của 2 số
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main()
{
//    int p,q,n,e,d;
//    string message,ciphertext,plaintext;
//    cout<<"Nhap p: ";
//    cin>>p;
//    cout<<"Nhap q: ";
//    cin>>q;
//
//    // Tính n và Ẩn khóa công khai
//    n=p*q;
//    int phi=(p-1)*(q-1);
//    cout<<"Nhap e (1 < e < "<<phi<<", gcd(e,"<<phi<<") = 1): ";
//    cin>>e;
//
//    // Tính Ẩn khóa bí mật
//    int i=2;
//    while(i<phi)
//    {
//        if(gcd(i,phi)==1 and (e*i)%phi==1)
//        {
//            d=i;
//            break;
//        }
//        i++;
//    }

    int e, n;
    cout << "Nhap khoa cong khai cua ben nhan: ";
    cin >> e >> n;

    // Khóa riêng bên nhận
    int d;
    cout << "Nhap khoa rieng cua ben nhan: ";
    cin >> d;

    // Nhập thông điệp cần mã hóa
    int message;
    cout << "Nhap thong diep can ma hoa: ";
    cin >> message;

    // Mã hóa thông điệp
    int encrypted_message = 1;
    for (int i = 0; i < e; i++) {
        encrypted_message = (encrypted_message * message) % n;
    }
    cout << "Thong diep da duoc ma hoa: " << encrypted_message << endl;

    // Giải mã thông điệp
    int decrypted_message = 1;
    for (int i = 0; i < d; i++) {
        decrypted_message = (decrypted_message * encrypted_message) % n;
    }
    cout << "Thong diep da duoc giai ma: " << decrypted_message << endl;

    return 0;
}