#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<long long> &a, long long x) {
  long long left = 0, right = (long long)a.size() - 1;
  long long probe = 0;
  for (;;){
    if (left > right)
      return -1; // left edge is passed right. nothing found
    probe = (long long) (right - left) / 2 + left;

    if (a[probe] == x)
      return probe; // found an element
    else if (a[probe] > x)
    { // keep serching in the left sector
      right = probe - 1;
    }
    else // a[probe] < x. searching in the right sector
      left = probe + 1;
  }
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  long long n;
  std::cin >> n;
  if (n < 0)
    n = 0;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  long long m;
  std::cin >> m;
  if (m < 0)
    m = 0;
  vector<long long> b(m);
  for (long long i = 0; i < m; ++i) {
    std::cin >> b[i];
  }

  if (!m){
    std::cout << "-1";
    return 0;
  }
  for (long long i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
