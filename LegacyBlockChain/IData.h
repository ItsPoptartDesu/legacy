#pragma once
#include <string>
#include <ctime>

class IData
{
private:
	std::string senderKey;
	std::string recieverKey;
	time_t timestamp;

protected:
	//mutators
	inline void SetSenderKey(std::string _key) { senderKey = _key; }
	inline void SetRecieverKey(std::string _key) { recieverKey = _key; }
	inline void SetTimeStamp(time_t _time) { timestamp = _time; }

public:
	virtual	~IData();
	
	//accessors 
	const inline std::string GetSenderKey() const { return senderKey; }
	const inline std::string GetRecieverKey() const { return recieverKey; }
	const inline time_t GetTimeStamp() const { return timestamp; }
};

