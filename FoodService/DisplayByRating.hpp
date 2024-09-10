#pragma once

#include "RestaurantDisplayStrategy.hpp"

class DisplayByRating : public RestaurantDisplayStrategy
{
	void sort(std::vector<Restaurant>& restaurants);
};