#include "Order.hpp"

Order::Order(std::string userID,
	std::string restaurantID,
	std::string foodID,
	int quantity,
	int pincode,
	std::chrono::time_point<std::chrono::system_clock> orderTime)
	: _userID(userID)
	, _restaurantID(restaurantID)
	, _foodID(foodID)
	, _quantity(quantity)
	, _pincode(pincode)
	, _orderTime(orderTime)
{};