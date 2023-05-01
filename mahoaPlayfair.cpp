#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// khởi tạo ma trận 5x5 từ key
void initKey(string key, char matrix[5][5]) 
{
    // xoá các ký tự trùng lặp trong key và đưa về chữ thường
    key.erase(remove(key.begin(), key.end(), ' '), key.end());
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    // đưa key vào ma trận 5x5, bỏ qua ký tự 'j'
    string alphabet = "abcdefghiklmnopqrstuvwxyz";
    int i = 0, j = 0;
    for (char c : key + alphabet) {
        if (c == 'j') continue;
        if (find(*matrix, *matrix + 25, c) == *matrix + 25)
            matrix[i][j++] = c;
        if (j == 5) i++, j = 0;
    }
}
string encrypt_playfair(string S, char key[5][5])
{
  // Làm sạch dữ liệu
  string clean_S;
  int i;
  for(i = 0; i < S.length(); i++){
    if(isalpha(S[i])){
      clean_S += toupper(S[i]);
    }
  }
  // Thêm phụ âm 'X' nếu cần
  for(i = 0; i < clean_S.length(); i += 2){
    if(i == clean_S.length() - 1){
      clean_S += 'X';
    } else if(clean_S[i] == clean_S[i+1]){
      clean_S.insert(i+1, "X");
    }
}
 //tìm vị trí của ký tự trong ma trận
void findPosition(char c, int &row, int &col, char matrix[5][5]) 
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matrix[i][j] == c) 
			{
                row = i;
                col = j;
            }
    	}
	}
}
// hàm mã hóa
string encryptPlayfair(string plain, string key) {
    char matrix[5][5];
    initKey(key, matrix);
    string cipher = "";
    int len = plain.length();
    // thêm 'x' vào cuối nếu độ dài là số lẻ
    if (len % 2 != 0) plain += 'x';
    for (int i = 0; i < len; i += 2) {
        int r1, c1, r2, c2;
        findPosition(plain[i], r1, c1, matrix);
        findPosition(plain[i+1], r2, c2, matrix);
        // nếu nằm trên cùng một hàng
        if (r1 == r2) {
            cipher += matrix[r1][(c1+1)%5];
            cipher += matrix[r2][(c2+1)%5];
        }
        // nếu nằm trên cùng một cột
        else if (c1 == c2) {
            cipher += matrix[(r1+1)%5][c1];
            cipher += matrix[(r2+1)%5][c2];
        }
        // nếu nằm trên các hàng và cột khác nhau
        else {
            cipher += matrix[r1][c2];
            cipher += matrix[r2][c1];
        }
    }
    return cipher;
}
string decrypt_playfair(string S, char key[5][5])
{
  // Loại bỏ các ký tự không phải chữ cái và chuyển đổi chữ hoa thành chữ thường
  string clean_S;
  for(int i = 0; i < S.length(); i++)
  {
    if(isalpha(S[i]))
	{
      clean_S += tolower(S[i]);
    }
  }
  // Giải mã
  string decrypted_S;
	for(int i = 0; i < clean_S.length(); i += 2){
    int h1, c1, h2, c2;
    tinh(clean_S[i], h1, c1, key);
    tinh(clean_S[i+1], h2, c2, key);
    	if(h1 == h2){ // Cùng hàng
      		decrypted_S += key[h1][(c1+4)%5];
      		decrypted_S += key[h2][(c2+4)%5];
    	} else if(c1 == c2){ // Cùng cột
      		decrypted_S += key[(h1+5-1)%5][c1];
      		decrypted_S += key[(h2+5-1)%5][c2];
		} else {//Khong cung hang cung cot
	  		decrypted_S += key[h1][h2];
	  		decrypted_s += KEY[h2][c1];
		}
	}
	return decrypted_S;
}
void tinh(char c, int &h, int &c, char key[5][5]){
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      if(key[i][j] == c){
        h = i;
        c = j;
        return;
      }
    }
  }
}
int main(){
  char key[5][5];
  string S, decrypted_S;
  cout << "Nhap vao khoa: ";
  for(int i = 0; i < MAXN; i++){
    for(int j = 0; j < MAXN; j++){
      cin >> key[i][j];
    }
  }
  cout << "Nhap vao chuoi can giai ma: ";
  cin >> S;
  encryptPlayfair_S = encryptPlayfair(S, key);
  cout << "Chuoi duoc giai ma la: " << encryptPlayfair_S << endl;
//  cout << "Nhap vao chuoi can giai ma: ";
//  cin >> S;
//  decrypted_S = decrypt_playfair(S, key);
//  cout << "Chuoi duoc giai ma la: " << decrypted_S << endl;
}