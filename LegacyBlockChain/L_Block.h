#pragma once

#include <string>
#include <ctime>

class L_Block
{
private:
	size_t index;
	size_t previoushash;
	std::time_t timestamp;
	std::string data;
	size_t hashcode;

public:

	size_t CalculateHash();
	//Accessors
	inline unsigned long GetIndex() const { return index; }
	inline size_t GetPreviousHash() const { return previoushash; }
	inline size_t GetSignatureHash() const { return hashcode; }
	inline std::string GetData() const { return data; }
	inline std::time_t GetTimeStamp() const { return timestamp; }

	L_Block(size_t _index, std::time_t _timestamp, std::string _data, size_t _previoushash);
	~L_Block();
};

