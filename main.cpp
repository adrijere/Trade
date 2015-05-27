#include "Trade.hpp"

int main()
{
	int money;
	int totalDay;
	std::string currentCours;

	std::cin >> money;
	std::cin >> totalDay;
	Trade trader(money, totalDay);

	std::cin >> currentCours;
	while (currentCours != "--END--")
	{
		trader.trade(atoi(currentCours.c_str()));
		currentCours = "";
		std::cin >> currentCours;
	}
}
