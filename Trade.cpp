#include "Trade.hpp"

Trade::Trade(int money, int totalDay)
	: _money(money), _totalDay(totalDay), _currentDay(0)
{}

Trade::~Trade()
{}

void Trade::setMoney(int money)
{
	this->_money = money;
}

int Trade::getMoney() const
{
	return (this->_money);
}

void Trade::setTotalDay(int totalDay)
{
	this->_totalDay = totalDay;
}

int Trade::getTotalDay() const
{
	return (this->_totalDay);
}

void Trade::setCurrentDay(int currentDay)
{
	this->_currentDay = currentDay;
}

int Trade::getCurrentDay() const
{
	return (this->_currentDay);
}

void Trade::addValue(int value)
{
	this->_oldValues.push_front(value);
}

void Trade::delValue()
{
	this->_oldValues.pop_back();
}

void Trade::trade(int newValue)
{
	(void)newValue;
	std::cout << "wait" << std::endl;
	this->_currentDay++;
}
