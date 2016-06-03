/*
 * APlusB.hpp
 *
 *  Created on: Jun 1, 2016
 *      Author: dmitrip
 */

#ifndef APLUSB_HPP_
#define APLUSB_HPP_
#include <string>
#include <iostream>
#include <sstream>
#include <limits>

class APlusB{
	int m_A = ERR_NUM;
	int m_B = ERR_NUM;

	int ConvertToInt(std::istream& in){
		int nValue = ERR_NUM;
		std::string strIn;
		in >> strIn;
		if (!(std::istringstream(strIn) >> nValue))
			return ERR_NUM;
		else
			return nValue;
	}

	int validateInt(int num){
		if (num < MIN_NUM || num > MAX_NUM)
			return ERR_NUM;
		else
			return num;
	}

public:
	static const short ERR_NUM = -1;
	static const short MIN_NUM = 0;
	static const short MAX_NUM = 9;

	int setA(int A){
		m_A = validateInt(A);
		return m_A;
	}

	int setA(std::istream& in){
		return setA(ConvertToInt(in));
	}

	int setB(int B){
		m_B = validateInt(B);
		return m_B;
	}

	int setB(std::istream& in){
		return setB(ConvertToInt(in));
	}

	int getA(){
		return m_A;
	}

	int getB(){
		return m_B;
	}

	int sumAB(){
		if (validateInt(m_A) != ERR_NUM && validateInt(m_B) != ERR_NUM)
			return m_A + m_B;
		else
			return ERR_NUM;
	}
};



#endif /* APLUSB_HPP_ */
