#include "pch.h"
#include "L_BlockChain.h"
#include "L_Block.h"
#include <iostream>
#include <chrono>
#include <ctime>   

L_BlockChain::L_BlockChain()
{
	using namespace std::chrono;
	//chain = new std::list<L_Block>();
	system_clock::time_point start = std::chrono::system_clock::now();
	L_Block* newBlock = new L_Block(0, system_clock::to_time_t(start), "GENOSIS BLOCK", 0);
	chain.push_back(newBlock);
}


L_BlockChain::~L_BlockChain()
{
	for (const L_Block* block : chain)
	{
		delete block;
	}

}

void L_BlockChain::AddBlock(std::string _data)
{
	using namespace std::chrono;
	L_Block* newBlock = new L_Block(chain.size(), system_clock::to_time_t(std::chrono::system_clock::now()),
		_data, chain.back()->GetSignatureHash());

	if (IsValidBlock(newBlock, chain.back()))
	{
		chain.push_back(newBlock);
		lookupmap.insert(std::make_pair(newBlock->GetSignatureHash(), newBlock));
	}

}

bool L_BlockChain::IsValidBlock(L_Block* _newBlock, L_Block* _previousBlock)
{
	if (_previousBlock->GetIndex() + 1 != _newBlock->GetIndex() ||
		_previousBlock->GetSignatureHash() != _newBlock->GetPreviousHash() ||
		_previousBlock->GetSignatureHash() == _newBlock->CalculateHash())
		return false;
	else
		return true;
}

void L_BlockChain::Print()
{
	for (const L_Block* block : chain)
		std::cout << block->GetIndex() << " : "
		<< block->GetPreviousHash() << " : "
		<< block->GetSignatureHash() << " : "
		<< block->GetData() << " : "
		<< block->GetTimeStamp() << std::endl;
}