#pragma once
#include <string>
#include <iostream>
#include "Ticket.hpp"
using namespace std;


class Person
{
public:
	Person(const string& id = "", const string& name = "", const string& phone_id = "", const string& password = "")
		:_id(id), 
		_name(name),
		_phone_id(phone_id),
		_password(password)
	{}
	~Person()
	{}
	//string& get_name()
	//{
	//	return _name;
	//}
	//string& get_id()
	//{
	//	return _id;
	//}
	//string& get_phone_id()
	//{
	//	return _phone_id;
	//}
	//string& get_password()
	//{
	//	return _password;
	//}
	string _id;
	string _name;
	string _phone_id;
	string _password;
};

