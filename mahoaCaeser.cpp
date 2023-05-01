#include <iostream>
#include <string>
using namespace std;

string caesarCipher(string M, int k) {
    string result = "";

    for (int i = 0; i < M.length(); i++) {
        // Kiểm tra xem ký tự đang xử lý có phải là chữ cái không
        //Hàm isalpha() được sử dụng để kiểm tra một ký tự có phải là một ký tự trong bảng chữ cái alphabet hay không.
        if (isalpha(M[i])) {
            // Chuyển đổi ký tự thành số nguyên trong khoảng từ 0 đến 25
            int charNum = toupper(M[i]) - 'A';
            // Thực hiện phép tính mã hóa Caesar
            charNum = (charNum + k) % 26;
            // Chuyển đổi số nguyên thành ký tự mới
            char newChar = charNum + 'A';
            // Thêm ký tự mới vào chuỗi kết quả
            result += newChar;
        } else {
            // Nếu ký tự không phải là chữ cái thì thêm ký tự đó vào chuỗi kết quả
            result += M[i];
        }
    }
    return result;
}
string caesardecryption(string S, int k) {
    string result = "";

    for (int i = 0; i < S.length(); i++) {
        // Kiểm tra xem ký tự đang xử lý có phải là chữ cái không
        //Hàm isalpha() được sử dụng để kiểm tra một ký tự có phải là một ký tự trong bảng chữ cái alphabet hay không.
        if (isalpha(S[i])) {
            // Chuyển đổi ký tự thành số nguyên trong khoảng từ 0 đến 25
            int charNum = toupper(S[i]) + 'A';
            // Thực hiện phép tính mã hóa Caesar
            charNum = (charNum - k) % 26;
            // Chuyển đổi số nguyên thành ký tự mới
            char newChar = charNum + 'A';
            // Thêm ký tự mới vào chuỗi kết quả
            result += newChar;
        } else {
            // Nếu ký tự không phải là chữ cái thì thêm ký tự đó vào chuỗi kết quả
            result += S[i];
        }
    }
    return result;
}
int main() {
    // Nhập thông điệp và số k
    string M, S;
    int k;
    cout << "Nhap vao thong diep can ma hoa: ";
    getline(cin, M);
    cout << "Nhap vao thong diep can giai ma: ";
    getline(cin, S);
    cout << "Nhap vao so k: ";
    cin >> k;

	// Mã hóa thông điệp bằng hệ mã Caesar
    string encryptedMessage1 = caesarCipher(M, k);

    // In ra thông điệp đã mã hóa
    cout << "Thong diep ma hoa: " << encryptedMessage1 << endl;

    // Giải mã thông điệp bằng hệ mã Caesar
    string encryptedMessage2 = caesardecryption(S, k);

    // In ra thông điệp đã giải mã
    cout << "Thong diep giai ma: " << encryptedMessage2 << endl;
    
    return 0;
}