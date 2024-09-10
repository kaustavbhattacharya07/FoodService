#pragma once

#include <string>
#include <vector>

#include "Order.hpp"

class User
{
public:
	std::string _name;
	std::string _phone;
	std::string _id;
	int _pincode;
	std::vector<Order> _orderHistory;

	User(std::string name,
		std::string phone,
		int pincode);
};