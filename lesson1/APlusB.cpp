#include <iostream>
#include "APlusB.hpp"

int main(){
	APlusB ab;
	std::cout << "Application sums up 2 integer numbers\n";
	std::cout << "Numbers need to be between 0 and 9\n";
	std::cout << "Enter 1st integer: ";
	ab.setA(std::cin);
	std::cout << "Enter 2nd integer: ";
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
