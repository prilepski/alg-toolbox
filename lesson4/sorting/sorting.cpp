#include <iostream>
#include <vector>
#include <stdlib.h>

using std::vector;
using std::swap;

long long partition2(vector<long long> &a, long long l, long long r);

long long partition3(vector<long long> &a, long long l, long long r, long long &m1, long long &m2){
//  return partition2(a, l, r);

  long long x = a[l];
  m1 = l;
  m2 = l;

  for (long long i = l + 1; i <= r; i++){
    if (a[i] < x){
      // moving m1:m2 to the right
      a[m1] = a[i];
      if ((m2 + 1) != i){
//        a[m1] = a[i];
        a[i] = a[m2 + 1];
      }
      a[m2 + 1] = x;
      m1++;
      m2++;
    }
    else if (a[i] == x){
      if ((m2 + 1) != i)
        swap(a[m2 + 1], a[i]);
      m2++;
    }
  }
}

long long partition2(vector<long long> &a, long long l, long long r) {
  long long x = a[l];
  long long j = l;
  for (long long i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<long long> &a, long long l, long long r) {
  if (l >= r) {
    return;
  }

  long long k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);

  long long m1 = l, m2 = l;
  long long m = partition3(a, l, r, m1, m2);

  randomized_quick_sort(a, l, m1 - 1);
  randomized_quick_sort(a, m2 + 1, r);
}

int main() {
  long long n;
  std::cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
