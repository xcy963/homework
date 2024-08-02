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