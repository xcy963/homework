# 第二周C++作业

---

- 1.排序问题：键盘输入n个整数，要求对其进行排序并由大到小输出。

```c++
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
```

---
2.二维数组：从键盘输入3*3的二维数组，将该数组行列交换输出，并求交换后的二维数组的两条对角线元素之和，并输出。

```c++
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
```

---

- 3.用指针完成程序编写：从键盘输入n个整数（n<100），找出最大元素的位置，并输出。

```c++
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
```

---

- 4.观影统计：编写一个程序，可以用来收集有关大学生在一个月内所看过的电影数量的统计数据。程序应询问用户调查了多少个学生，并动态分配相应大小的数组。程序还应该允许用户输入每个学生所看过的电影数量，最后计算输入值的平均值、中值和众数。

```c++
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
```

- 5.字符串排序：输入n个字符串，按照其首字母字典顺序从小到大进行排序。

```c++
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
```

---

-6.学生信息管理：使用结构体录入并存储n个学生的姓名，学号，成绩信息，并可输出学生的相关信息。

```c++
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
```

---

- 7.学生信息管理：将第六题录入的学生信息以分数从高到低排序输出。

```c++
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
    student temp;
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

    for (int j = n - 1; j > 0; j--) {
        for (int i = 0; i < j; i++) {
            if (a[i].score < a[i + 1].score) {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
    cout << "下面的是按成绩排序过后的:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "第" << i + 1 << "个学生的姓名是:" << a[i].name << " ";
        cout << "第" << i + 1 << "个学生的学号是:" << a[i].id << " ";
        cout << "第" << i + 1 << "个学生的成绩是是:" << a[i].score << " ";
        cout << endl;
    }
    return 0;
}
```

---

- 8.复数四则运算：利用一个结构体定义复数（形如a+bi的数），并使用结构体实现两个复数的四则运算。
  
```c++
#include <iostream>
using namespace std;
struct mycomplex {
    double real;
    double imag;
    mycomplex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    mycomplex operator+(const mycomplex& other) const {
        return mycomplex(real + other.real, imag + other.imag);
    }
    mycomplex operator-(const mycomplex& other) const {
        return mycomplex(real - other.real, imag - other.imag);
    }
    mycomplex operator*(const mycomplex& other) const {
        return mycomplex(real * other.real - imag * other.imag,
                         real * other.imag + imag * other.real);
    }

    mycomplex operator/(const mycomplex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        if (denominator == 0) {
            throw std::runtime_error("zero");
        }
        return mycomplex((real * other.real + imag * other.imag) / denominator,
                         (imag * other.real - real * other.imag) / denominator);
    }
};

int main() {
    mycomplex a(1, 2), b(0, 0);
    mycomplex c;
    c = a / b;
    return 0;
}
```

---
