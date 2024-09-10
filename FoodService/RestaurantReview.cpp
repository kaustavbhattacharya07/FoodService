#include "RestaurantReview.hpp"

RestaurantReview::RestaurantReview(std::string userID,
	std::string restaurantID,
	int rating,
	std::string comment)
	: _userID(userID)
	, _restaurantID(restaurantID)
	, _rating(rating)
	, _comment(comment)
{};