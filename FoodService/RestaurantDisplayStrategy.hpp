#pragma once

#include <vector>

class Restaurant;

class RestaurantDisplayStrategy
{
public:
	virtual void sort(std::vector<Restaurant>& restaurants) = 0;
};