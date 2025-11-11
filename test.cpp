#include <iostream>
#include <string>

using namespace std;

// 密码校验函数
bool checkPassword(const string& input, const string& correctPassword) {
    return input == correctPassword;
}

int main() {
    string correctPassword = "1234";
    string input;
    
    cout << "请输入密码: ";
    cin >> input;
    
    if (checkPassword(input, correctPassword)) {
        cout << "密码正确！" << endl;
    } else {
        cout << "密码错误！" << endl;
    }
    
    return 0;
}

