#pragma once
#include "IData.h"
#include <string>

class L_Data : public IData
{
public:
	enum class Gender {
		Male = 0,
		Female = 1,
		Custom = 2,
		NA
	};

private:
	std::string myFirst_name;
	std::string myLast_name;
	std::string myMiddle_name;
	size_t myPhone_number;
	time_t myBirthday;
	Gender myGender;

	void ZeroOutMemberVariables();

protected:

	inline void SetFirstName(std::string _fName) { myFirst_name = _fName; }
	inline void SetLastName(std::string _lName) { myLast_name = _lName; }
	inline void SetMiddleName(std::string _mName) { myMiddle_name = _mName; }
	inline void SetPhoneNumber(size_t _pNum) { myPhone_number = _pNum; }
	inline void SetBirthday(time_t _bDay) { myBirthday = _bDay; }
	inline void SetGender(Gender _gen) { myGender = _gen; }

public:
	size_t GenerateDataHash();
	inline std::string GetFirstName() const { return myFirst_name; }
	inline std::string GetLastName() const { return myLast_name; }
	inline std::string GetMiddleName() const { return myMiddle_name; }
	inline size_t GetPhoneNumber() const { return myPhone_number; }
	inline time_t GetBirthday() const { return myBirthday; }
	inline Gender GetGender() const { return myGender; }
	bool ShareLData(size_t _recieverKey);
	void Print();
	L_Data(std::string _fName, std::string _lName, std::string _mName,
		size_t _pNum, time_t _bDay, Gender _gen);
	~L_Data();
};

