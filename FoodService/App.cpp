#include "App.hpp"
#include "UserManager.hpp"
#include "OrderingService.hpp"
#include "RestaurantManager.hpp"
#include "RestaurantReview.hpp"
#include "DisplayByRating.hpp"

#include <iostream>


App::App()
	: _currentUser("")
	, rm(RestaurantManager::getInstance())
	, um(UserManager::getInstance())
{}

bool App::loginUser(std::string userID)
{
	if (_currentUser == "" && um.hasUser(userID))
	{
		_currentUser = userID;
		std::cout << "User " << _currentUser << " logged in.\n";
		return true;
	}
	return false;
}

bool App::logoutUser()
{
	if (_currentUser != "")
	{
		_currentUser = "";
		return true;
	}
	return false;
}

bool App::placeOrder(std::string restaurantID, std::string foodName, int quantity)
{
	if (_currentUser == "")
	{
		return false;
	}
	const bool flag =
		OrderingService::getInstance().placeOrder(_currentUser, restaurantID, foodName, quantity);
	if (flag)
	{
		std::cout << "Order Placed Successfully\n";
	}
	else
	{
		std::cout << "Cannot place order\n";
	}
	return flag;
}

bool App::addReview(std::string restaurantID, int rating, std::string comment)
{
	if (_currentUser == "")
	{
		return false;
	}
	return rm
		.addReview(restaurantID,
			*(new RestaurantReview(_currentUser, restaurantID, rating, comment)));
}

bool App::updateUserLocation(int pincode)
{
	if (_currentUser == "")
	{
		return false;
	}
	um._users.find(_currentUser)->second._pincode = pincode;
	return true;
}

void App::showRestaurantList(std::string orderBy)
{
	std::vector<Restaurant> r;
	if (orderBy == "rating")
	{
		r = rm.showRestaurants(*(new DisplayByRating()));
	}
	for (int i = 0; i < r.size(); i++)
	{
		std::cout << "Restaurant: " << r[i]._name << "\n";
	}
}

bool App::registerRestaurant(std::string resturantName,
	std::vector<int> pincodes,
	std::string fooditem,
	double price,
	int quantity)
{
	bool flag = rm.registerRestaurant(resturantName);
	if (flag)
	{
		rm.addFoodItem(resturantName, fooditem, price, quantity);
		rm.addDeliveryPinCodes(resturantName, pincodes);
	}
	return flag;
}

bool App::registerUser(std::string name,
	std::string phone,
	int pincode)
{
	return um.registerUser(name, phone, pincode);
}

bool App::updateQuantity(std::string resturantName,
	std::string fooditem,
	int newQuantity)
{
	return rm.updateFoodQuantity(resturantName, fooditem, newQuantity);
}

void App::orderHistory()
{
	if (_currentUser != "")
	{
		for (auto order : um._users.find(_currentUser)->second._orderHistory)
		{
			std::cout << "Ordered : " << order._foodID
				<< " from " << order._restaurantID
				<< " on " 
				<< std::chrono::system_clock::to_time_t(order._orderTime) 
				<< "\n";
		}
	}
}