#include "User.hpp"

User::User(std::string name,
	std::string phone,
	int pincode)
	: _name(name)
	, _phone(phone)
	, _id(phone)
	, _pincode(pincode)
{}