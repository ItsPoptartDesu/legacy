#pragma once
#include <string>

class L_Data;

class L_Tester
{
public:
	void TestLedgerBlockCreation(int _numBlocks);
	void GetRandomString(std::string* _input, int _len = 10);
	L_Data::Gender GetRandomGender();
	L_Tester();
	~L_Tester();
};

