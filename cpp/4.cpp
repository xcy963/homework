#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, temp;
    float sum, middle;
    int max = 0, max_value;
    map<int, int> frequency;
    cout << "请输入调查了的学生数：";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cout << "请输入第" << i + 1 << "个学生看过的电影数量:" << endl;
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

    // 平均值

    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    cout << "平均值：" << sum / n << endl;
    // 中值
    if (n % 2 == 0) {
        middle = (a[n / 2 - 1] + a[n / 2]) / 2.0;
    } else {
        middle = a[n / 2];
    }
    cout << "中值为" << middle << endl;
    // 众数
    for (int i = 0; i < n; i++) {
        frequency[a[i]]++;
    }
    for (const auto& pair : frequency) {
        if (max < pair.second) {
            max = pair.second;
            max_value = pair.first;
        }
    }
    cout << "众数为：" << max_value << endl;
    return 0;
}