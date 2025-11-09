#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// 简单的密码校验程序
class PasswordValidator {
private:
    string correctPassword;
    int maxAttempts;

public:
    // 构造函数，设置正确的密码和最大尝试次数
    PasswordValidator(const string& password, int attempts = 3) 
        : correctPassword(password), maxAttempts(attempts) {}
    
    // 验证单个密码
    bool validate(const string& input) {
        return input == correctPassword;
    }
    
    // 运行密码验证流程
    bool run() {
        int attempts = 0;
        string input;
        
        cout << "=== 密码验证系统 ===" << endl;
        cout << "您有 " << maxAttempts << " 次尝试机会" << endl << endl;
        
        while (attempts < maxAttempts) {
            cout << "请输入密码 (尝试 " << (attempts + 1) << "/" << maxAttempts << "): ";
            getline(cin, input);
            
            if (validate(input)) {
                cout << "\n✓ 密码正确！验证成功！" << endl;
                return true;
            } else {
                attempts++;
                if (attempts < maxAttempts) {
                    cout << "✗ 密码错误！还剩 " << (maxAttempts - attempts) << " 次机会" << endl << endl;
                }
            }
        }
        
        cout << "\n✗ 密码错误次数过多，验证失败！" << endl;
        return false;
    }
};

// 简单版本：使用函数实现
bool simplePasswordCheck() {
    const string correctPassword = "123456";
    string input;
    int attempts = 0;
    const int maxAttempts = 3;
    
    cout << "=== 简单密码校验 ===" << endl;
    
    while (attempts < maxAttempts) {
        cout << "请输入密码: ";
        getline(cin, input);
        
        if (input == correctPassword) {
            cout << "密码正确！" << endl;
            return true;
        } else {
            attempts++;
            cout << "密码错误！还剩 " << (maxAttempts - attempts) << " 次机会" << endl;
        }
    }
    
    cout << "验证失败！" << endl;
    return false;
}

// 更安全的版本：使用字符数组和简单加密
bool securePasswordCheck() {
    // 使用简单的异或加密存储密码（实际应用中应使用哈希）
    const char encryptedPassword[] = {0x50, 0x52, 0x53, 0x53, 0x56, 0x4F, 0x51, 0x55, 0x00}; // "password" 异或 0x3
    const char key = 0x3;
    
    char input[100];
    int attempts = 0;
    const int maxAttempts = 3;
    
    cout << "=== 安全密码校验 ===" << endl;
    cout << "提示：默认密码是 'password'" << endl;
    
    while (attempts < maxAttempts) {
        cout << "请输入密码: ";
        cin.getline(input, 100);
        
        // 解密并比较
        bool match = true;
        size_t len = strlen(input);
        
        if (len != strlen(encryptedPassword) - 1) {
            match = false;
        } else {
            for (size_t i = 0; i < len; i++) {
                if ((input[i] ^ key) != encryptedPassword[i]) {
                    match = false;
                    break;
                }
            }
        }
        
        if (match) {
            cout << "✓ 访问已授权！" << endl;
            return true;
        } else {
            attempts++;
            if (attempts < maxAttempts) {
                cout << "✗ 访问被拒绝！还剩 " << (maxAttempts - attempts) << " 次尝试" << endl;
            }
        }
    }
    
    cout << "✗ 账户已锁定！" << endl;
    return false;
}

int main() {
    int choice;
    
    cout << "===========================================" << endl;
    cout << "      密码校验系统演示程序" << endl;
    cout << "===========================================" << endl;
    cout << "\n请选择验证方式：" << endl;
    cout << "1. 面向对象版本 (密码: admin123)" << endl;
    cout << "2. 简单函数版本 (密码: 123456)" << endl;
    cout << "3. 安全加密版本 (密码: password)" << endl;
    cout << "0. 退出" << endl;
    cout << "\n请输入选择 (0-3): ";
    cin >> choice;
    cin.ignore(); // 清除换行符
    
    cout << "\n===========================================" << endl << endl;
    
    switch(choice) {
        case 1: {
            PasswordValidator validator("admin123", 3);
            validator.run();
            break;
        }
        case 2:
            simplePasswordCheck();
            break;
        case 3:
            securePasswordCheck();
            break;
        case 0:
            cout << "程序退出。再见！" << endl;
            break;
        default:
            cout << "无效的选择！" << endl;
    }
    
    return 0;
}

