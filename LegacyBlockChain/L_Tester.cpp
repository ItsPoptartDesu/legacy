#include "pch.h"
#include "L_Tester.h"
#include "L_BlockChain.h"

void L_Tester::TestLedgerBlockCreation(int _numBlocks)
{
	L_BlockChain* ledger = new L_BlockChain();

	for (int i = 0; i < _numBlocks; i++)
	{
		std::string temp;
		GetRandomString(&temp);
		ledger->AddBlock(temp);
	}

	ledger->Print();

	delete ledger;
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
