#pragma once

#include "RestaurantDisplayStrategy.hpp"
#include "Restaurant.hpp"

#include <unordered_map>
#include <mutex>


class RestaurantManager
{
private:
	static RestaurantManager* _instance;
	RestaurantManager();
	mutable std::mutex registration, ordering;
public:
	std::unordered_map<std::string, Restaurant> _restaurants;

	static RestaurantManager& getInstance();

	bool registerRestaurant(std::string name);

	bool addDeliveryPinCode(std::string restaurantID, int pincode);

	bool addDeliveryPinCodes(std::string restaurantID, std::vector<int> pincodes);

	bool addFoodItem(std::string restaurantID,
		std::string foodName,
		double price,
		int quantity);

	bool updateFoodQuantity(std::string restaurantID,
		std::string foodName,
		int newQuantity);

	bool hasFoodItem(std::string restaurantID, std::string foodName);

	bool hasFoodQuantity(std::string restaurantID, std::string foodName, int quantity);

	bool addReview(std::string restaurantID,
		RestaurantReview& reiew);

	bool hasRestaurant(std::string restaurantID);

	bool placeOrder(Order& order);

	std::vector<Restaurant> showRestaurants(RestaurantDisplayStrategy& displayStrategy);
};