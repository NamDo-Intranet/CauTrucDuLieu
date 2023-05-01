#include <iostream>
#include <cmath>

using namespace std;

// Kiểm tra tính nguyên tố của một số
bool isPrime(int n) {
    if (n <= 1)
        return false;

    int sqrtn = sqrt(n);
    for (int i = 2; i <= sqrtn; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

// Tìm số nguyên tố lớn nhất nhỏ hơn hoặc bằng n
int findLargestPrime(int n) {
    for (int i = n - 1; i >= 2; i--) {
        if (isPrime(i))
            return i;
    }

    return 2;
}

// Tìm ước số chung lớn nhất của a và b
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Tìm số e sao cho gcd(e,phi) = 1
int findE(int phi) {
    int e = 2;
    while (e < phi) {
        if (gcd(e, phi) == 1)
            break;
        e++;
    }
    return e;
}

// Tính d sao cho e.d % phi = 1
int findD(int e, int phi) {
    int k = 1;
    while (true) {
        int d = (k * phi + 1) / e;
        if (e * d == k * phi + 1)
            return d;
        k++;
    }
}
// Mã hóa một chuỗi sử dụng khóa công khai (n, e)
string encryptRSA(string s, int n, int e) {
    string encrypted;
    for (char c : s) {
        int m = c;
        int crypted = 1;
        for (int i = 0; i < e; i++) {
            crypted = (crypted * m) % n;
        }
        encrypted += to_string(crypted) + " ";
    }
    return encrypted;
}
// Giải mã một chuỗi đã được mã hóa sử dụng khóa bí mật (n, d)
string decryptRSA(string s, int n, int d) {
    string decrypted;
    int c = 0;
    while (c < s.length()) {
        // Tìm token tiếp theo
        string token;
        while (s[c] != ' ' && c < s.length()) {
            token += s[c];
            c++;
        }
        c++;
        // Chuyển đổi chuỗi số thành số nguyên
        int crypted = 0;
        for (int i = 0; i < token.length(); i++) {
            crypted = crypted * 10 + (token[i] - '0');
        }
        // Giải mã RSA
        int m = 1;
        for (int i = 0; i < d; i++) {
            m = (m * crypted) % n;
        }
        // Chuyển đổi số nguyên thành ký tự
        decrypted += char(m);
    }
    return decrypted;
}
int main() {
    int p, q;
    cout << "Nhap 2 so p va q: ";
    cin >> p >> q;

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    int e = findE(phi);
    int d = findD(e, phi);

    cout << "Public key: (" << n << ", " << e << ")" << endl;
    cout << "Private key: (" << n << ", " << d << ")" << endl;

    string message;
    cout << "Enter a message to encrypt: ";
    cin.ignore();
    getline(cin, message);

    string encrypted = encryptRSA(message, n, e);
    cout << "Chuoi ma hoa la: " << encrypted <<endl;
    string decryptRSA_S = decryptRSA(message, d, n);
    cout << "Giai ma chuoi la: " << decryptRSA_S<<endl;
    return 0;
}