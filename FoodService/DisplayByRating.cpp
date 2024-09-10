#include "DisplayByRating.hpp"
#include "Restaurant.hpp"

#include <algorithm>

bool compare(Restaurant& r1, Restaurant& r2)
{
	return r1._rating > r2._rating;
}

void DisplayByRating::sort(std::vector<Restaurant>& restaurants)
{
	std::sort(restaurants.begin(), restaurants.end(), compare);
}