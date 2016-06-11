#include <iostream>

long long gcd(long long a, long long b) {
  //write your code here
  int current_gcd = 1;

  long long nResult = 1;

  long long tmpLow, tmpHigh, nCurrent;
  if (a > b){
    tmpHigh = a;
    tmpLow = b;
  }
  else {
    tmpHigh = b;
    tmpLow = a;
  }

  for (;;){

    nCurrent = tmpHigh % tmpLow;
    if (!nCurrent){
      nResult = tmpLow;
      break;
    }
    else{
      tmpHigh = tmpLow;
      tmpLow = nCurrent;
      nResult = tmpLow;
    }
  }

  return nResult;

}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << gcd(a, b) << std::endl;
  return 0;
}
