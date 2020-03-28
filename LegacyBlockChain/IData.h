#pragma once
#include <string>
#include <ctime>

class IData
{
private:
	size_t mySenderKey;
	size_t myRecieverKey;
	time_t myCreationTimeStamp;

protected:
	
public:
	virtual	~IData();
	virtual size_t GenerateDataHash() = 0;
	
	//accessors 
	inline size_t GetSenderKey() const { return mySenderKey; }
	inline size_t GetRecieverKey() const { return myRecieverKey; }
	inline time_t GetTimeStamp() const { return myCreationTimeStamp; }

	//mutators
	inline void SetSenderKey(size_t _key) { mySenderKey = _key; }
	inline void SetRecieverKey(size_t _key) { myRecieverKey = _key; }
	inline void SetTimeStamp(time_t _time) { myCreationTimeStamp = _time; }
};

