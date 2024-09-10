#include "OrderingService.hpp"
#include "RestaurantManager.hpp"
#include "UserManager.hpp"

#include <chrono>

OrderingService& OrderingService::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new OrderingService();
	}
	return *_instance;
}

OrderingService::OrderingService()
{}

OrderingService* OrderingService::_instance = nullptr;

bool OrderingService::placeOrder(std::string userID,
	std::string restaurantID,
	std::string foodName,
	int quantity)
{
	RestaurantManager& rm = RestaurantManager::getInstance();
	UserManager& um = UserManager::getInstance();
	if (um.hasUser(userID))
	{
		Order o = *(new Order(userID,
			restaurantID,
			foodName,
			quantity,
			um.getUserPinCode(userID),
			std::chrono::system_clock::now()
		));
		const bool orderPlaced = rm.placeOrder(o);
		if (orderPlaced)
		{
			um.addOrderToUserHistory(userID, o);
		}
		return orderPlaced;
	}
	return false;
}