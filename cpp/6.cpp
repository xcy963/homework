#include <iostream>
using namespace std;

struct student {
    string name;
    int id;
    float score;
};
student a[1000];

int main() {
    int n;
    cout << "请输入学生个数n:";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "请输入第" << i + 1 << "个学生的姓名" << endl;
        cin >> a[i].name;
        cout << "请输入第" << i + 1 << "个学生的学号" << endl;
        cin >> a[i].id;
        cout << "请输入第" << i + 1 << "个学生的成绩信息" << endl;
        cin >> a[i].score;
    }
    for (int i = 0; i < n; i++) {
        cout << "第" << i + 1 << "个学生的姓名是:" << a[i].name << " ";
        cout << "第" << i + 1 << "个学生的学号是:" << a[i].id << " ";
        cout << "第" << i + 1 << "个学生的成绩是是:" << a[i].score << " ";
        cout << endl;
    }
    return 0;
}