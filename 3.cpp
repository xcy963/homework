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