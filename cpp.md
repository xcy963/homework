# 第一周C++作业

- Essential C++ 1.1节后附练习

---

- 编写一个大小写字母转换程序，实现如下要求：
  - 输入为小写字母时，输出字母表中该字母的下一个字母的大写
  - 当输入不是英文字母时，给出相应提示

    示例：

    ```bash
    input: 'a'
    output: 'B'
    
    input: 'z'
    output: 'A'
    
    input: '2'
    ouput: 'invalid input'
    ```

    ```c++
    #include <iostream>
    using namespace std;
    int main() {
        char ch;
        cin >> ch;
        if (ch >= 'a' && ch <= 'z') {
            cout << char(ch - 'a' + 'A');
        } else if (ch >= 'A' && ch <= 'Z') {
            cout << char(ch - 'A' + 'a');
        } else {
            cout << "invalid input";
        }
        return 0;
    }
    ```

---

- 编写一个数值转换程序，实现如下要求：
  - 输入 度 分 秒，最后以度的形式输出
  - 需要进行输入合法性检查

    示例：

    ```bash
    input: 37 51 19
    output: 37.8553

    input: -2 51 19
    output: 'invalid input'
    ```

    ```c++
    #include <iostream>
    using namespace std;
    int main() {
        double a, b, c;
        if (!(cin >> a >> b >> c)) {
            cout << "invalid input";
            return 0;
        } else if (a < 0 || b < 0 || c < 0 || b >= 60 || c >= 60) {
            cout << "invalid input";
        } else {
            cout << a + b / 60.0 + c / 3600.0;
        }
        return 0;
    }
    ```

---

- 编写一个阶乘程序，要求进行输入合法性判断

    示例：

    ```bash
    input: 5
    output: 120

    input: -5
    output: 'invalid input'

    input: 5.1
    output: 'invalid input'
    ```

    ```c++
    #include <iostream>

    using namespace std;
    int main() {
        int num;
        int res = 1;
        if (!(cin >> num)) {
            cout << "invalid input";
        } else if (num < 0) {
            cout << "invalid input";
        } else {
            for (int i = 1; i <= num; i++) {
                res = res * i;
            }
        }
        cout << res;
        return 0;
    }
    ```

---

- 水仙花：
  - 水仙花数是指一个三位数，每个位上的数字的三次幂之和等于它本身
  - 请找出所有的水仙花数并打印
  - 程序中应有判断过程，直接查表打印视作未完成

    ```c++
    #include <iostream>
    using namespace std;
    int main() {
        int a, b, c;
        for (int i = 100; i < 1000; i++) {
            a = i / 100;
            b = (i / 10) % 10;
            c = i % 10;
            if (i == a * a * a + b * b * b + c * c * c) {
                cout << i << " ";
            }
        }
        cout << endl;
        return 0;
    }
    ```

---

- 哥德巴赫猜想：
  - 输入一个不大于10000的偶数，将其分解为 $p+q$ 的形式，其中 $p$, $q$ 均为素数，且 $p<=q$

    示例：

    ```bash
    input: 4
    ouput:
    1: 2 2
    
    input: 24
    output:
    1: 5 19
    2: 7 17
    3: 11 13
    ```

    ```c++
    #include <iostream>
    using namespace std;

    bool isPrime(int num) {
        if (num <= 1) return false;
        if (num <= 3) return true;
        if (num % 2 == 0 || num % 3 == 0) return false;
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) return false;
        }
        return true;
    }

    int main() {
        int num;
        int times = 1;
        if (!(cin >> num)) {
            cout << "invalid input";
            return 0;
        } else if (0 <= num && num <= 10000 && num % 2 == 0) {
            for (int i = 1; i <= num / 2; i++) {
                if (isPrime(i) && isPrime(num - i)) {
                    cout << times << ": " << i << " " << num - i << endl;
                    times++;
                }
            }
        } else {
            cout << "invalid input";
        }
        return 0;
    }
    ```
