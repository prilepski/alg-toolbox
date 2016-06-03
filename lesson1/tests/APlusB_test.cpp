/*
 * APlusB_test.cpp
 *
 *  Created on: May 31, 2016
 *      Author: dmitrip
 */
#include "gtest/gtest.h"
#include <string>
#include <iostream>
#include <sstream>
#include <climits>
#include "../APlusB.hpp"

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

class APlusBTest: public :: testing::Test{
protected:
	APlusBTest(){

	}

	virtual ~APlusBTest(){

	}

	virtual void SetUp(){

	}

	virtual void TearDown(){

	}
};

TEST_F(APlusBTest, CornerCases){
	APlusB ab;

	EXPECT_EQ(ab.setA(-1), -1) << "Expecting error for -1";
	EXPECT_EQ(ab.setA(0), 0) << "Expecting 0 for 0";
	EXPECT_EQ(ab.setA(9), 9) << "Expecting 9 for 9";
	EXPECT_EQ(ab.setA(INT_MAX), -1) << "Expecting error";

	EXPECT_EQ(ab.setB(-1), -1) << "Expecting error for -1";
	EXPECT_EQ(ab.setB(0), 0) << "Expecting 0 for 0";
	EXPECT_EQ(ab.setB(9), 9) << "Expecting 9 for 9";
	EXPECT_EQ(ab.setB(INT_MAX), -1) << "Expecting error";

	std::istringstream str("");
	EXPECT_EQ(ab.setA(str), -1) << "Expecting error for empty string";
	str.clear();
	str.str("");
	EXPECT_EQ(ab.setB(str), -1) << "Expecting error for empty string";

	str.clear();
	str.str("-1");
	EXPECT_EQ(ab.setA(str), -1) << "Expecting error for empty string";
	str.clear();
	str.str("-1");
	EXPECT_EQ(ab.setB(str), -1) << "Expecting error for empty string";

	str.clear();
	str.str("0");
	EXPECT_EQ(ab.setA(str), 0) << "Expecting error for empty string";
	str.clear();
	str.str("0");
	EXPECT_EQ(ab.setB(str), 0) << "Expecting error for empty string";

	str.clear();
	str.str("9");
	EXPECT_EQ(ab.setA(str), 9) << "Expecting 9";

	str.clear();
	str.str("9");
	EXPECT_EQ(ab.setB(str), 9) << "Expecting 9";

	str.clear();
	str.str("sdfsfsdfsdf");
	EXPECT_EQ(ab.setA(str), -1) << "Expecting error for text string string";
	str.clear();
	str.str("sdfsfsdfsdf");
	EXPECT_EQ(ab.setB(str), -1) << "Expecting error for text string string";

}

TEST_F(APlusBTest, TestInput){
	APlusB ab;

	ab.setA(0);
	EXPECT_EQ(0, ab.getA()) << "setA and getA do not match";
	ab.setB(0);
	EXPECT_EQ(0, ab.getB()) << "setB and getB do not match";


	std::istringstream str("5");
	ab.setA(str);
	EXPECT_EQ(ab.getA(), 5) << "getA do not match";

	str.clear();
	str.str("4");
	ab.setB(str);
	EXPECT_EQ(ab.getB(), 4) << "getB do not match to 4";

}

TEST_F(APlusBTest, TestSum){
	APlusB ab;

	ab.setA(1);
	ab.setB(5);
	EXPECT_EQ(ab.sumAB(), 6) << "um does not match expectations";


	ab.setA(-1);
	ab.setB(5);
	EXPECT_EQ(ab.sumAB(), -1) << "sum does not match expectations";

	ab.setA(-1);
	ab.setB(-1);
	EXPECT_EQ(ab.sumAB(), -1) << "sum does not match expectations";
}
