#include <iostream>
using namespace std;
string a[10000];

bool mycompare(string* a, string* b) {  // 大于就换
    string l1 = *a, l2 = *b;
    int mylen = (l1.length() > l2.length()) ? l1.length() : l2.length();
    for (int i = 0; i < mylen; i++) {
        if (l1[i] > l2[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    string temp;
    cout << "请输入字符串个数n:";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "请输入第" << i + 1 << "个字符串" << endl;
        cin >> a[i];
    }

    for (int j = n - 1; j > 0; j--) {
        for (int i = 0; i < j; i++) {
            if (mycompare(&a[i], &a[i + 1])) {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
    cout << "从小到大排好顺序以后是：";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}