#include "pch.h"
#include "L_Block.h"
#include <cstring>
#include <iostream>
#include <functional>
#include <time.h>
#include "L_Data.h"
using namespace std;

/*
Creates L_Block which is the backbone of our blockchain.
This block is the specifically ours we will define what we use and save here or in L_Data
Other blocks will be defined by the return API from given companies
*/
L_Block::L_Block(size_t _index, std::time_t _timestamp, L_Data* _data, size_t _previoushash)
{
	index = _index;
	timestamp = _timestamp;
	previoushash = _previoushash;
	hashcode = CalculateHash();

	data = _data;
	data->SetSenderKey(hashcode);
	data->SetTimeStamp(_timestamp);
}


L_Block::~L_Block()
{
}

/*
calculates the hash for said block returns the hash value that should be said from this function
*/
size_t L_Block::CalculateHash()
{
	hash<size_t> hash;
	char str[26];
	ctime_s(str, sizeof str, &timestamp);
	size_t t = index + previoushash + std::atoi(str) + data->GenerateDataHash();
	return hash(t);
}
