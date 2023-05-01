#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int main() {
    int p, q, n,phi,e,d;
    cout<<"Nhap p: "; cin>>p;
    cout<<"Nhap q: "; cin>>q;
    n = p * q;
    phi = (p - 1) * (q - 1);
    do {
        cout<<"Nhap e (1 < e < "<<phi<<", gcd(e,"<<phi<<") = 1): "; 
        cin>>e;
    } while (e <= 1 || e >= phi || gcd(e,phi) != 1);
    int k = 0;
    do {
        k++;
        d = (1 + k * phi) / e;
    } while ((1 + k * phi) % e != 0 || d >= phi || d <= 1);
    cout<<"Public key: ("<<e<<","<<n<<")"<<endl;
    cout<<"Private key: ("<<d<<","<<n<<")"<<endl;
    return 0;
}