#include "Trade.hpp"

Trade::Trade(int money, int totalDay)
	: _money(money), _totalDay(totalDay), _currentDay(0), _actions(0)
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

void Trade::buy(int newValue, int nb)
{
	while ((nb * newValue) + (0.0015 * nb * newValue) > this->_money)
		nb--;
	if (nb != 0)
	{
		this->_actions += nb;
		this->_money -= ((nb * newValue) + (0.0015 * nb * newValue));
		std::cout << "buy " << nb << std::endl;
	}
	else
		this->wait();
}

void Trade::sell(int newValue, int nb)
{
	if (nb > this->_actions)
		nb = this->_actions;
	if (nb != 0)
	{
		this->_actions -= nb;
		this->_money += ((nb * newValue) - (0.0015 * nb * newValue));
		std::cout << "sell " << nb << std::endl;
	}
	else
		this->wait();
}

void Trade::wait()
{
	std::cout << "wait" << std::endl;
}

void Trade::trade(int newValue)
{
	if (this->_currentDay == this->_totalDay - 1)
		this->sell(newValue, this->_actions);
	else if (this->_oldValues.size() > 0 && newValue > this->_oldValues.front())
		this->buy(newValue, 1);
	else if (this->_oldValues.size() > 0 && newValue < this->_oldValues.front())
		this->sell(newValue, 1);
	else
		this->wait();

	this->addValue(newValue);
	this->_currentDay++;
}
