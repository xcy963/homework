#include <iostream>
using namespace std;
float a[3][3] = {0};

int main() {
    float temp, sum;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "请输入第" << i + 1 << "行第" << j + 1 << "列的数字";
            cin >> a[i][j];
        }
    }

    cout << "现在的数组" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    // 交换
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
    cout << "交换后的数组:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << "交换后的两条主对角线元素之和：" << endl;
    for (int i = 0; i < 3; i++) {
        sum += a[i][i];
        sum += a[i][2 - i];
    }
    cout << sum << endl;
    return 0;
}