#pragma once
#include <list>
#include <unordered_map>

class L_Block;
class L_Data;

class L_BlockChain
{

private:
	std::unordered_map<size_t, L_Block*> lookupmap;
	std::list<L_Block*> chain;
	bool IsValidBlock(L_Block* _new, L_Block* _previousBlock);

public:

	void AddBlock(L_Data* _data);
	void Print();

	L_BlockChain();
	~L_BlockChain();
};

