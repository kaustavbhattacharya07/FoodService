#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

#include "FoodItem.hpp"
#include "RestaurantReview.hpp"
#include "Order.hpp"

#include <unordered_set>

class Restaurant
{
public:
	std::string _name;
	std::string _id;
	std::unordered_map<std::string, FoodItem> _foodItems;
	double _rating;
	std::vector<RestaurantReview> _reviews;
	std::unordered_set<int> _serviceablePincodes;
	std::queue<Order> _currentOrders;

	Restaurant(std::string name);
};