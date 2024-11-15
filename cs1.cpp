#include <iostream>
using namespace std;

string SoTiengViet(int n) {
    if (n == 10) return "mười";
    if (n == 11) return "mười một";
    if (n == 12) return "mười hai";
    if (n == 13) return "mười ba";
    if (n == 14) return "mười bốn";
    if (n == 15) return "mười lăm";
    if (n == 16) return "mười sáu";
    if (n == 17) return "mười bảy";
    if (n == 18) return "mười tám";
    if (n == 19) return "mười chín";

    int donvi = n % 10;
    int chuc = n / 10;

    string result = "";
    switch (chuc) {
        case 2: result = "hai mươi"; break;
        case 3: result = "ba mươi"; break;
        case 4: result = "bốn mươi"; break;
        case 5: result = "năm mươi"; break;
        case 6: result = "sáu mươi"; break;
        case 7: result = "bảy mươi"; break;
        case 8: result = "tám mươi"; break;
        case 9: result = "chín mươi"; break;
    }

    switch (donvi) {
        case 1: result += " một"; break;
        case 2: result += " hai"; break;
        case 3: result += " ba"; break;
        case 4: result += " bốn"; break;
        case 5: result += " năm"; break;
        case 6: result += " sáu"; break;
        case 7: result += " bảy"; break;
        case 8: result += " tám"; break;
        case 9: result += " chín"; break;
    }

    return result;
}

int main() {
    int A;
    cout << "Nhập vào một số từ 10 đến 99: ";
    cin >> A;

    if (A < 10 || A > 99) {
        cout << "Số không hợp lệ. Vui lòng nhập lại số từ 10 đến 99.";
    } else {
        cout << "Giá trị của số " << A << " là: " << SoTiengViet(A);
    }

    return 0;
}
