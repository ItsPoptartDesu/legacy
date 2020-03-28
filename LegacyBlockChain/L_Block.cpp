#include "pch.h"
#include "L_Block.h"
#include <cstring>
#include <iostream>
#include <functional>
#include <time.h>
using namespace std;

L_Block::L_Block(size_t _index, std::time_t _timestamp, string _data, size_t _previoushash)
{
	index = _index;
	timestamp = _timestamp;
	data = _data;
	previoushash = _previoushash;
	hashcode = CalculateHash();
}


L_Block::~L_Block()
{
}

size_t L_Block::CalculateHash()
{
	hash<size_t> hash;
	char str[26];
	ctime_s(str, sizeof str, &timestamp);
	size_t t = index + previoushash + std::atoi(str) + std::atoi(data.c_str());
	return hash(t);
}
