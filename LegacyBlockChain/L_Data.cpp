#include "pch.h"
#include <iostream>
#include "L_Data.h"

/*
Create L_Data which is used in the main block chain
This is going to be Legacy Specific stuff that we will hold and define
Other blocks are going to be defined by the api of given company we are using
*/
L_Data::L_Data(std::string _fName, std::string _lName, std::string _mName,
	size_t _pNum, time_t _bDay, Gender _gen)
{
	//lets have a clean start
	ZeroOutMemberVariables();

	//set child specific variables  
	SetFirstName(_fName);
	SetLastName(_lName);
	SetMiddleName(_mName);
	SetPhoneNumber(_pNum);
	SetBirthday(_bDay);
	SetGender(_gen);
}

void L_Data::Print()
{
	printf("First Name : %f", GetFirstName());
	printf("Last Name : %l", GetLastName());
	printf("Middle Name : %m", GetMiddleName());
	printf("Phone Number : %p", GetPhoneNumber());
	printf("Birthday : %b", GetBirthday());
	printf("Gender : %g", GetGender());
}

L_Data::~L_Data()
{
}

size_t L_Data::GenerateDataHash()
{
	return 0;
}

/*
NULL/Zero out the member data
we do this to make sure we have a clean start
*/
void L_Data::ZeroOutMemberVariables()
{
	myFirst_name = myLast_name = myMiddle_name = "";
	myPhone_number = 0;
	myBirthday = NULL;
	myGender = Gender::NA;
	SetTimeStamp(NULL);
	SetSenderKey(0);
	SetRecieverKey(0);
}

/*
used to share Legacy Specific Data with other blocks in the block chain
*/
bool L_Data::ShareLData(size_t _recieverKey)
{
	SetRecieverKey(_recieverKey);
	//give reciever this* data inside my class
	//TODO:event listeners
}