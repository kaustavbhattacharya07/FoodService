#include "UserManager.hpp"

#include <iostream>

UserManager& UserManager::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new UserManager();
	}
	return *_instance;
}

UserManager::UserManager()
{}

bool UserManager::registerUser(std::string name,
	std::string phone,
	int pincode)
{
	std::lock_guard<std::mutex> mtx(registration);
	if (!hasUser(phone))
	{
		_users.emplace(phone, *(new User(name, phone, pincode)));
		std::cout << "User " << name << " registered.\n";
		return true;
	}
	return false;
}

UserManager* UserManager::_instance = nullptr;

bool UserManager::hasUser(std::string userID)
{
	return (_users.find(userID) != _users.end());
}

int UserManager::getUserPinCode(std::string userID)
{
	if (hasUser(userID))
	{
		return _users.find(userID)->second._pincode;
	}
	return 0;
}

bool UserManager::addOrderToUserHistory(std::string userID,
	Order& order)
{
	if (hasUser(userID))
	{
		_users.find(userID)->second._orderHistory.push_back(order);
		return true;
	}
	return false;
}

bool UserManager::updateUserLocation(std::string userID, int pincode)
{
	if (hasUser(userID))
	{
		_users.find(userID)->second._pincode = pincode;
		return true;
	}
	return false;
}