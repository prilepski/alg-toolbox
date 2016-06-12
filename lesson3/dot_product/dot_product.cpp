#include <algorithm>
#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

bool sortAsc(long long i, long long j){
  return (i < j);
};

bool sortDesc(long long i, long long j){
  return (i > j);
};


long long min_dot_product(vector<long long> a, vector<long long> b) {
  // write your code here
  std::sort(a.begin(), a.end(), sortDesc);
  std::sort(b.begin(), b.end(), sortAsc);

  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += a[i] * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<long long> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }

  std::cout << min_dot_product(a, b) << std::endl;
}
