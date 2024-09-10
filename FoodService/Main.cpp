#include "App.hpp"

int main()
{

	App a;
	a.registerUser("Pralove", "phoneNumber - 1", 560037);
	a.registerUser("Niket", "phoneNumber - 2", 560017);
	a.registerUser("Borun", "phoneNumber - 3", 560027);
	a.loginUser("phoneNumber - 1");

	a.registerRestaurant("Food Court - 1", { 560037 }, "NI Thali", 100, 5);
	a.registerRestaurant("Food Court - 2", { 560027 }, "NI Thali", 100, 5);

	a.showRestaurantList("rating");

	a.placeOrder("Food Court - 1", "NI Thali", 2);
	a.placeOrder("Food Court - 2", "NI Thali", 7);

	a.addReview("Food Court - 2", 5, "Good Food");
	a.addReview("Food Court - 1", 3, "Nice Food");

	a.showRestaurantList("rating");
	a.orderHistory();
}