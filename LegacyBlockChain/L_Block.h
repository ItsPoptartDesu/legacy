#pragma once

#include <string>
#include <ctime>

class L_Data;

class L_Block
{
private:
	size_t index;
	size_t previoushash;
	std::time_t timestamp;
	L_Data* data;
	size_t hashcode;

public:

	size_t CalculateHash();
	//Accessors
	inline size_t GetIndex() const { return index; }
	inline size_t GetPreviousHash() const { return previoushash; }
	inline size_t GetSignatureHash() const { return hashcode; }
	inline L_Data* GetData() const { return data; }
	inline std::time_t GetTimeStamp() const { return timestamp; }

	L_Block(size_t _index, std::time_t _timestamp, L_Data* _data, size_t _previoushash);
	~L_Block();
};

