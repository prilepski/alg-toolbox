#include <iostream>

long long get_change(long long n) {
  //write your code here
  long long n10 = 0, n5 = 0, n1 = 0;
  for (; n > 0; ){
    if ( (n - 10) >= 0){
      n10++;
      n -= 10;
    }
    else if ((n - 5) >= 0){
      n5++;
      n -= 5;
    }
    else if ((n - 1) >= 0){
      n1++;
      n -= 1;
    }
  }
  return n10 + n5 + n1;
}

int main() {
  long long n;
  std::cin >> n;
  std::cout << get_change(n) << '\n';
}
