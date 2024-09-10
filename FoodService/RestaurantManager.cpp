#include "RestaurantManager.hpp"

#include <iostream>

RestaurantManager& RestaurantManager::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new RestaurantManager();
	}
	return *_instance;
}

RestaurantManager* RestaurantManager::_instance = nullptr;

RestaurantManager::RestaurantManager()
{}

bool RestaurantManager::registerRestaurant(std::string name)
{
	std::lock_guard<std::mutex> lock(registration);
	if (!hasRestaurant(name))
	{
		_restaurants.emplace(name, *(new Restaurant(name)));
		std::cout << "Restaurant " << name << " registered.\n";
		return true;
	}
	return false;
}

bool RestaurantManager::addDeliveryPinCode(std::string restaurantID, int pincode)
{
	if (hasRestaurant(restaurantID))
	{
		_restaurants.find(restaurantID)->second._serviceablePincodes.insert(pincode);
		return true;
	}
	return false;
}

bool RestaurantManager::addDeliveryPinCodes(std::string restaurantID, std::vector<int> pincodes)
{
	for (auto pincode : pincodes)
	{
		addDeliveryPinCode(restaurantID, pincode);
	}
	return true;
}

bool RestaurantManager::addFoodItem(std::string restaurantID,
	std::string foodName,
	double price,
	int quantity)
{
	if (hasRestaurant(restaurantID))
	{
		_restaurants.find(restaurantID)->second._foodItems.emplace(foodName, *(new FoodItem(foodName, price, quantity)));
		return true;
	}
	return false;
}

bool RestaurantManager::updateFoodQuantity(std::string restaurantID,
	std::string foodName,
	int newQuantity)
{
	if (hasFoodItem(restaurantID, foodName))
	{
		_restaurants.find(restaurantID)->second._foodItems.find(foodName)->second._quantity = newQuantity;
		return true;
	}
	return false;
}

bool RestaurantManager::hasFoodItem(std::string restaurantID, std::string foodName)
{
	return (hasRestaurant(restaurantID)
		&& _restaurants.find(restaurantID)->second._foodItems.find(foodName)
		!= _restaurants.find(restaurantID)->second._foodItems.end());
}

bool RestaurantManager::hasFoodQuantity(std::string restaurantID,
	std::string foodName,
	int quantity)
{
	return (hasRestaurant(restaurantID)
		&& (_restaurants.find(restaurantID)->second._foodItems.find(foodName)
			!= _restaurants.find(restaurantID)->second._foodItems.end()))
		&& (_restaurants.find(restaurantID)->second._foodItems.find(foodName)->second._quantity >= quantity);
}

bool RestaurantManager::addReview(std::string restaurantID,
	RestaurantReview& review)
{
	if (hasRestaurant(restaurantID))
	{
		Restaurant& r = _restaurants.find(restaurantID)->second;
		int numReviews = static_cast<int>(r._reviews.size());
		r._rating = ((r._rating * numReviews) + review._rating) / (numReviews + 1.0);
		_restaurants.find(restaurantID)->second._reviews.push_back(review);
		return true;
	}
	return false;
}

bool RestaurantManager::hasRestaurant(std::string restaurantID)
{
	return _restaurants.find(restaurantID) != _restaurants.end();
}

bool RestaurantManager::placeOrder(Order& order)
{
	std::lock_guard<std::mutex> lock(ordering);
	if (hasFoodQuantity(order._restaurantID, order._foodID, order._quantity))
	{
		Restaurant& r = _restaurants.find(order._restaurantID)->second;
		if (r._serviceablePincodes.find(order._pincode)
			!= r._serviceablePincodes.end())
		{
			r._currentOrders.push(order);
			r._foodItems.find(order._foodID)->second._quantity -= order._quantity;
			return true;
		}		
	}
	return false;
}

std::vector<Restaurant> RestaurantManager::showRestaurants(
	RestaurantDisplayStrategy& displayStrategy)
{
	std::vector<Restaurant> allRestro;
	for (auto iter = _restaurants.begin(); iter != _restaurants.end(); iter++)
	{
		allRestro.push_back(iter->second);
	}
	displayStrategy.sort(allRestro);
	return allRestro;
}