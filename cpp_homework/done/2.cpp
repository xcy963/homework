#include <cstring>  // 包含strcpy的头文件
#include <iostream>
#include <new>  // 包含定位new的头文件

using namespace std;

struct chaff {
    char dross[20];
    int slag;
};

int main() {
    char* buffer = new char[sizeof(chaff) * 2];
    chaff* chaffArray = new (buffer) chaff[2];

    // 给结构的成员赋值
    strcpy(chaffArray[0].dross, "Example1");
    chaffArray[0].slag = 1;

    strcpy(chaffArray[1].dross, "Example2");
    chaffArray[1].slag = 2;

    // 循环显示chaff结构内容
    for (int i = 0; i < 2; ++i) {
        cout << "chaff " << i + 1 << endl;
        cout << "dross: " << chaffArray[i].dross << endl;
        cout << "slag: " << chaffArray[i].slag << endl;
    }
    delete[] buffer;
    return 0;
}