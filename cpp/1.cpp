#include <iostream>
using namespace std;
int a[100] = {0};

int main() {
    int n, temp;
    cout << "请输入整数个数n:";
    cin >> n;
    cout << "请输入这些数:";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int j = n - 1; j > 0; j--) {
        for (int i = 0; i < j; i++) {
            if (a[i] < a[i + 1]) {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}