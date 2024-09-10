#pragma once

#include "Order.hpp"

#include <mutex>

class OrderingService
{
private:
	static OrderingService* _instance;
	OrderingService();
public:
	static OrderingService& getInstance();

	bool placeOrder(std::string userID,
		std::string restaurantID,
		std::string foodName,
		int quantity);
};