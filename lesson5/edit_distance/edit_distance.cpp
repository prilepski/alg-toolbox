#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  vector< vector<char> > matrix(str1.length() + 1, vector<char>(str2.length() + 1));

  for (size_t j = 0; j <= str2.length(); ++j){
    for (size_t i = 0; i <= str1.length(); ++i){
      if (i == 0){
        matrix[i][j] = j;
        continue;
      }

      if (j == 0) {
        matrix[i][j] = i;
        continue;
      }

      matrix[i][j] = std::min((int)matrix[i][j-1] + 1, (int)matrix[i-1][j] + 1);
      if (str1[i] != str2[j]){
        // symbols in 2 strings mismatch
        matrix[i][j] = std::min((int)matrix[i][j], matrix[i-1][j-1] + 1);
      }
      else{
        // symbols in 2 strings match
        matrix[i][j] = std::min((int)matrix[i][j], (int)matrix[i-1][j-1]);        
      }
    }
  }
  return matrix[str1.length()][str2.length()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
