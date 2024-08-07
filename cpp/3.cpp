#include <iostream>
using namespace std;
int a[100];
int main() {
    int n;
    int *max = &a[0];
    cout << "请输入n:";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "请输入第" << i + 1 << "个数:";
        cin >> a[i];
        if (a[i] > *max) {
            max = &a[i];
        }
    }
    cout << "他的地址为" << max << endl;
    cout << "他的值为" << *max << endl;
    return 0;
}