#include "pch.h"
#include "L_Tester.h"
#include "L_BlockChain.h"
#include "L_Data.h"
#include <chrono>
#include <ctime>  

void L_Tester::TestLedgerBlockCreation(int _numBlocks)
{
	L_BlockChain* ledger = new L_BlockChain();

	for (int i = 0; i < _numBlocks; i++)
	{
		std::string fname;
		std::string mname;
		std::string lname;
		GetRandomString(&fname, 5);
		GetRandomString(&mname, 3);
		GetRandomString(&lname, 7);
		
		system_clock::time_point start = std::chrono::system_clock::now(); 
		L_Data* ld = new L_Data(fname, lname, mname, 16263828471, system_clock::to_time_t(start),GetRandomGender());
		ledger->AddBlock(ld);
	}

	ledger->Print();

	delete ledger;
}

L_Data::Gender L_Tester::GetRandomGender()
{
	return (L_Data::Gender)(rand() % ((int)L_Data::Gender::NA));
}

void L_Tester::GetRandomString(std::string* _input, int _len)
{
	const std::string alpha =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < _len; i++)
		_input->push_back(alpha[rand() % alpha.length()]);
}

L_Tester::L_Tester()
{
}


L_Tester::~L_Tester()
{
}
