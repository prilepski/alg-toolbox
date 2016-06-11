#include <iostream>

long long lcm(long long a, long long b) {
  //write your code here
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

  return (a * b) / nResult;
}

/*
  for (;;){
    if (a > b){
      long long tmpA = a;
      a %= b;
      if (!a)
        a = tmpA / b;
      if (!nResult){
        nResult = tmpA / a;
      }
      nResult *= a;
    }
    else if (b > a){
      long long tmpB = b;
      b %= a;
      if (!b)
        b = tmpB / a;
      if (!nResult)
        nResult = tmpB / b;
      nResult *= b;
    }

    if (b == 0 || b == 1 || a == 0 || a == 1)
      return nResult;
//    else
//      return 1;
  }
}*/



int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm(a, b) << std::endl;
  return 0;
}
