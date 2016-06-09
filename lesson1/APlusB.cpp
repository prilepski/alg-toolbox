#include <iostream>
#include "APlusB.hpp"

int main(){
	APlusB ab;
//  string strInput;
//  std::cin >> strInput;
	ab.setA(std::cin);
	ab.setB(std::cin);

	int sum = ab.sumAB();
	if (sum != APlusB::ERR_NUM){
		std::cout << "The sum is: " << sum << "\n";
		return 0;
	}
	else{
		std::cout << "Oups... Looks like incorrect data was entered\n";
		std::cout << "Try again later!!!\n";
		return -1;
	}

	return -1;
}
