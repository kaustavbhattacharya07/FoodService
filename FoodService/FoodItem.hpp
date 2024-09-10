#pragma once
#include <string>

class FoodItem
{
public:
	std::string _id;
	std::string _name;
	std::string _description;
	std::string _image;
	double _price;
	int _quantity;

	FoodItem(std::string name,
		double price,
		int quantity);
};