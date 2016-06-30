#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<unsigned long> optimal_sequence(int n) {
  std::vector<unsigned long> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

struct point{
  long long steps;
  long long derivedFrom;
};

vector<unsigned long> min_sequence(unsigned long n){
  vector<unsigned long> sequence; // vector for resulting sequence

  vector<point> numbers(n+1); // vector to keep minimum number of steps
  point tmpPoint;
  // insert results for n = 1
  numbers[1].steps = 0;
  numbers[1].derivedFrom = 0;

  long long tmp_min_steps;
  long long tmp_derived_from;

  // filling in min step vector
  for (long long m = 2; m <= n; ++m){
    tmp_min_steps = n;
    tmp_derived_from = n;
    if (m % 2 == 0){
      // minimum number of steps and where we came to it if m is divisble by 2
      tmp_min_steps = numbers[m / 2].steps + 1;
      tmp_derived_from = m / 2;
    }
    if (m % 3 == 0){
      // minimum number of steps and where we came to it if m is divisble by 3
      // make sure number of steps lower than in the previous (%2) case
      if (tmp_min_steps > (numbers[m / 3].steps + 1)){
        tmp_min_steps = numbers[m / 3].steps + 1;
        tmp_derived_from = m / 3;
      }
    }

    // minimum number of steps and where we came to it if number of steps is better (lower_then in previous )
    if (tmp_min_steps > (numbers[m - 1].steps + 1)){
      tmp_min_steps = numbers[m - 1].steps + 1;
      tmp_derived_from = m - 1;
    }

    // saving results
    numbers[m].steps = tmp_min_steps;
    numbers[m].derivedFrom = tmp_derived_from;
  }

  // walk through min step vector to reconstruct which numbers have been used to calculate n 
  for (long long i = n; i >= 1;){
    sequence.push_back(i);
    i = numbers[i].derivedFrom;
  }

  return sequence;
}

int main() {
  unsigned long n;
  std::cin >> n;
  vector<unsigned long> sequence = min_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  // print sequence from the back
  for (size_t i = sequence.size(); i > 0; --i) {
    std::cout << sequence[i - 1] << " ";
  }
}
