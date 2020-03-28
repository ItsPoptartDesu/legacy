#include "pch.h"
#include "L_BlockChain.h"
#include "L_Block.h"
#include <iostream>
#include <chrono>
#include <ctime>   
#include "L_Data.h"

/*
The block chain that holds everything

This will hold our Legacy Blocks and data.
This will also be the entry point for all the other blockchains that will be created and used on Legacy platform
*/
L_BlockChain::L_BlockChain()
{
	using namespace std::chrono;
	//chain = new std::list<L_Block>();
	system_clock::time_point start = std::chrono::system_clock::now();
	L_Data* lData = new L_Data("GENOSIS", "BLOCK", " ", 
		16263828471, system_clock::to_time_t(start), L_Data::Gender::NA);
	L_Block* newBlock = new L_Block(0, system_clock::to_time_t(start), lData, 0);
	chain.push_back(newBlock);
}

/*
destory new data
*/
L_BlockChain::~L_BlockChain()
{
	for (const L_Block* block : chain)
	{
		delete block;
	}

}

/*
adds a new block to the chain
*/
void L_BlockChain::AddBlock(L_Data* _data)
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

/*
Double checks to make sure the new block we want to add to the chain lines up with the previous block
and also has values we expect
*/
bool L_BlockChain::IsValidBlock(L_Block* _newBlock, L_Block* _previousBlock)
{
	if (_previousBlock->GetIndex() + 1 != _newBlock->GetIndex() ||
		_previousBlock->GetSignatureHash() != _newBlock->GetPreviousHash() ||
		_previousBlock->GetSignatureHash() == _newBlock->CalculateHash())
		return false;
	else
		return true;
}

/*
Used for debugging and unit tests. shouldn't be used in production env
*/
void L_BlockChain::Print()
{
	for (const L_Block* block : chain)
	{
		std::cout << block->GetIndex() << " : "
		<< block->GetPreviousHash() << " : "
		<< block->GetSignatureHash() << " : "
		<< block->GetData() << " : "
		<< block->GetTimeStamp() << std::endl;

		block->GetData()->Print();
	}

}