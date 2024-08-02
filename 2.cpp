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