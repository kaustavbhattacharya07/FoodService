#pragma once

#include <string>

class RestaurantReview
{
public:
	std::string _userID;
	std::string _restaurantID;
	int _rating;
	std::string _comment;

	RestaurantReview(std::string userID,
		std::string restaurantID,
		int rating,
		std::string comment);
};