#include <exception>

#include "Trade.hpp"

int main()
{
	try
	{
		int money;
		int totalDay;
		std::string currentCours;

		std::cin >> money;
		std::cin >> totalDay;
		Trade trader(money, totalDay);

		std::cin >> currentCours;
		while (currentCours != "--END--" && trader.getCurrentDay() < trader.getTotalDay())
		{
			trader.trade(atoi(currentCours.c_str()));
			currentCours = "";
			std::cin >> currentCours;
		}
	}
	catch(const std::exception &e)
	{
		std::cerr << "Erreur lors du fonctionnement du programme (fichiers d'input invalide?)." << std::endl;
	}
}
