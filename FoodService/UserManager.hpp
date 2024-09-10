#pragma once

#include "User.hpp"

#include <unordered_map>
#include <mutex>

class UserManager
{
private:
	static UserManager* _instance;
	UserManager();
	mutable std::mutex registration;
public:
	std::unordered_map<std::string, User> _users;

	static UserManager& getInstance();

	bool registerUser(std::string name,
		std::string phone,
		int pincode);

	bool hasUser(std::string userID);

	bool addOrderToUserHistory(std::string userID,
		Order& order);

	bool updateUserLocation(std::string userID, int pincode);

	int getUserPinCode(std::string userID);

};