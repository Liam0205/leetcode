#include <iostream>

long long power(int x, unsigned n);

int main() {
    std::cout << power(6, 15) << std::endl;
    return 0;
}

long long power(int x, unsigned n) {
    if (0 == n) {
        return 1;
    } else {
        while (0 == (n & 0x01)) {  // trim following 0x00 in n
            n >>= 1;
            x *= x;
        }
    }
    long long res = 1;
    while (0 != n) {
        if (0 != (n & 0x01)) {     // multiply x^(2^i)
            res *= x;
        }
        x *= x;                    // x^(2^i)
        n >>= 1;
    }
    return res;
}
