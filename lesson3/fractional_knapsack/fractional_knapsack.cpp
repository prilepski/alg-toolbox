#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

struct Product{
  long long value;
  long long weight;
};

bool productSort (Product product1, Product product2){
  return (( (double) product1.value / product1.weight) > ( (double) product2.value / product2.weight));
};

double get_optimal_value(long long capacity, vector<Product> products) {
  double value = 0.0;
  // write your code here

  for (int i = 0; capacity > 0; ++i){
    if ((capacity - products[i].weight) >= 0){
      capacity -= products[i].weight;
      value += products[i].value;
    }
    else{
      value += (double) products[i].value / products[i].weight * capacity;
      capacity = 0;
    }
  }
  return value;
}

int main() {
  long long n;
  long long capacity;
  std::cin >> n >> capacity;
  vector<Product> products(n);
  for (int i = 0; i < n; i++) {
    std::cin >> products[i].value >> products[i].weight;
  }

  std::sort(products.begin(), products.end(), productSort);
  double optimal_value = get_optimal_value(capacity, products);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
