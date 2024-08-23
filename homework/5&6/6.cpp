#include <iostream>
using namespace std;
class vector2D {
   private:
    double x, y;

   public:
    vector2D(double a, double b) : x(a), y(b) {}

    vector2D operator+(const vector2D& other) const {
        return vector2D(x + other.x, y + other.y);
    }

    vector2D operator-(const vector2D& other) const {
        return vector2D(x - other.x, y - other.y);
    }

    // 数乘运算符重载（数乘）
    vector2D operator*(const double& scalar) const {
        return vector2D(x * scalar, y * scalar);
    }
    // 点乘运算符重载
    double operator*(const vector2D& other) const {
        return x * other.x + y * other.y;
    }

    friend std::ostream& operator<<(std::ostream& os, const vector2D& vec) {
        os << "(" << vec.x << ", " << vec.y << ")";
        return os;
    }
};

int main() {
    vector2D v1(3, 4);
    vector2D v2(1, 2);

    std::cout << "v1 + v2 = " << v1 + v2 << std::endl;

    std::cout << "v1 - v2 = " << v1 - v2 << std::endl;

    std::cout << "v1 * 2.5 = " << v1 * 2.5 << std::endl;

    std::cout << "v1 * v2 (dot product) = " << v1 * v2 << std::endl;
}
