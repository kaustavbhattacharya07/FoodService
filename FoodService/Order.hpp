#pragma once

#include <string>
#include <chrono>

class Order
{
public:
	std::string _userID;
	std::string _restaurantID;
	std::string _foodID;
	int _quantity;
	int _pincode;
	std::chrono::time_point<std::chrono::system_clock> _orderTime;

	Order(std::string _userID,
		std::string _restaurantID,
		std::string _foodID,
		int _quantity,
		int pincode,
		std::chrono::time_point<std::chrono::system_clock> orderTime);
};