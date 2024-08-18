#include <iostream>

using namespace std;

int main() {
    double income;
    double tax;

    cout << "请输入您的收入（输入负数或非数字退出）：";

    while (cin >> income && income >= 0) {
        tax = 0.0;

        if (income > 35000) {
            tax += (income - 35000) * 0.20;
            income = 35000;
        }
        if (income > 15000) {
            tax += (income - 15000) * 0.15;
            income = 15000;
        }
        if (income > 5000) {
            tax += (income - 5000) * 0.10;
            income = 5000;
        }

        cout << "应缴税额为：" << tax << " tvarps" << endl;
        cout << "请输入您的收入（输入负数或非数字退出）：";
    }

    cout << "程序结束。" << endl;
    return 0;
}