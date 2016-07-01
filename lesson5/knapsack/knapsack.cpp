#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

long optimal_weight(int W, const vector<int> &w) {
  // handle corner cases here
  if (W == 0 || w.size() == 0)
    return 0; // zero capacity or no weights defined

  vector< vector<long> > matrix(W + 1, vector<long>(w.size() + 1));
  for(size_t j = 0; j < w.size() + 1; ++j){
    for(size_t i = 0; i < matrix.size(); ++i){
      if (i == 0 || j == 0)
        matrix[i][j] = 0;
      else{
        if (i < w[j-1])
          // not enough capacity for current weight. Use previous weight
          matrix[i][j] = matrix[i][j-1];
        else{
          matrix[i][j] = std::max(matrix[i][j - 1], matrix[std::max(0, (int)(i - w[j - 1]))][j - 1] + w[j - 1]);
          if (matrix[i][j] > W){
            // too much weight. Do not add this element
            matrix[i][j] = std::max(matrix[i][j - 1], matrix[std::max(0, (int)(i - w[j - 1]))][j - 1]);
          }
        }
      }
    }
  }

  return matrix[W][w.size()];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
