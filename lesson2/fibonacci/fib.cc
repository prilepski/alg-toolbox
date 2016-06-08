#include <iostream>

int calc_fib(int n) {
    if (n <= 1)
        return n;
/*
    return calc_fib(n - 1) + calc_fib(n - 2);*/

    int minusOne = 1;
    int minusTwo = 0;
    int nTmp = 0;
    for (int i = 2; i <= n; ++i){
        nTmp = minusOne;
        minusOne += minusTwo;
        minusTwo = nTmp;
    }
    return minusOne;
}

int main() {
    int n = 0;
    std::cin >> n;

    std::cout << calc_fib(n) << '\n';
    return 0;
}
