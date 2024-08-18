#include <cmath>
#include <iostream>
using namespace std;

void solveQuadratic(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "方程有两个实根: x1 = " << root1 << ", x2 = " << root2 << endl;
    }

    else if (discriminant == 0) {
        double root = -b / (2 * a);
        cout << "方程有一个实根: x = " << root << endl;
    }

    else {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        cout << "方程有两个虚根: x1 = " << realPart << " + " << imaginaryPart
             << "i, "
             << "x2 = " << realPart << " - " << imaginaryPart << "i" << endl;
    }
}

int main() {
    double a = 0, b = 0, c = 0;
    cout << "请输入abc用空格隔开:";
    if (!(cin >> a >> b >> c)) {
        cout << "输入有误" << endl;
        return 0;
    }
    solveQuadratic(a, b, c);
    return 0;
}