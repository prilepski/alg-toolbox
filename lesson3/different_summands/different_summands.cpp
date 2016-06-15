#include <iostream>
#include <vector>

using std::vector;

vector<long long> optimal_summands(long long n) {
  vector<long long> summands;
  //write your code here
  long long l = 1;
  for (;;){
    if (n > 2 * l){
      summands.push_back(l);
      n -= l;
      l++;
    }
    else{
      summands.push_back(n);
      break;
    }
  }
  return summands;
}

int main() {
  long long n;
  std::cin >> n;
  vector<long long> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }

  std::cout << std::endl;
}
