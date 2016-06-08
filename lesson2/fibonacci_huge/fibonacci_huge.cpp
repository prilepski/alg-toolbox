#include <iostream>

long long get_fibonaccihuge(long long n, long long m) {
  if (n < 0 || m < 0)
    return 0;

  if (n == 0)
    return 0;
  if (n == 1)
    return 1;

    long long minusOne = 1;
    long long minusTwo = 0;
    long long nTmp = 0;
    long long nLength = -1;
    for (long long i = 2; i <= n; ++i){
        nTmp = minusOne;
        minusOne += minusTwo;
        if (m > 0)
          minusOne %= m;
        minusTwo = nTmp;
        if (minusTwo == 0 && minusOne == 1){
          // got into a cycle
//          std::cout << "Length: " << (i - 1) << "\n";
          nLength = i - 1;
          break;
        }
//        std::cout << "Current index: " << i << "\n";
//        std::cout << "Current NUm: " << minusOne << "\n";
    }

    if (nLength == -1)
      // we got to n-th number before we ran into a loop
      return minusOne;

    // otherwise we need to calculate n-th number
    nTmp = n % nLength;
//    std::cout << "Get the number: " << nTmp << "\n";
    if (nTmp != 0)
      return get_fibonaccihuge(nTmp, m);
    else
      return get_fibonaccihuge(0, m);

  }

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonaccihuge(n, m) << '\n';
}
