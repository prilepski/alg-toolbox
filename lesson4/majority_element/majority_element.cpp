#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long get_majority_element(vector<long long> &a, long long left, long long right) {
//  if (left == right) return -1;
//  if (left + 1 == right) return a[left];

  //write your code here
  long long count = 0, majorityElement = -1;
  for (size_t i = 0; i < a.size(); ++i){
    if (count == 0)
      majorityElement = a[i];
    if (a[i] == majorityElement)
      count++;
    else
      count--;
  }

  count = 0;
  for (size_t i = 0; i < a.size(); ++i){
    if (a[i] == majorityElement)
      count++;
  }

  return (count > (long long) a.size() / 2) ? 1:-1;
}

int main() {
  long long n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
