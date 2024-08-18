#include <cctype>
#include <iostream>

using namespace std;

int main() {
    char ch;
    cout << "请输入字符，输入@符号结束输入：" << endl;

    while (cin >> ch && ch != '@') {
        if (isdigit(ch)) {
            continue;
        }

        // 如果是大写字母，转换为小写
        if (isupper(ch)) {
            ch = tolower(ch);
        }
        // 如果是小写字母，转换为大写
        else if (islower(ch)) {
            ch = toupper(ch);
        }

        // 输出转换后的字符
        cout << ch << endl;
    }

    cout << "程序结束" << endl;
    return 0;
}