#pragma once

#include <string>
#include <vector>
class RestaurantManager;
class UserManager;

class App
{
private:
	std::string _currentUser;
	RestaurantManager& rm;
	UserManager& um;
public:
	App();

	bool loginUser(std::string userID);

	bool logoutUser();

	bool placeOrder(std::string restaurantID, std::string foodName, int quantity);

	bool addReview(std::string restaurantID, int rating, std::string comment = "");

	bool updateUserLocation(int pincode);

	void showRestaurantList(std::string orderBy);

	bool registerRestaurant(std::string resturantName,
		std::vector<int> pincodes,
		std::string fooditem,
		double price,
		int quantity);

	bool registerUser(std::string name,
		std::string phone,
		int pincode);

	bool updateQuantity(std::string resturantName,
		std::string fooditem,
		int newQuantity);

	void orderHistory();
};