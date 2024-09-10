#include "FoodItem.hpp"

FoodItem::FoodItem(std::string name,
	double price,
	int quantity)
	: _name(name)
	, _id(name)
	, _description("")
	, _image("")
	, _price(price)
	, _quantity(quantity)
{}