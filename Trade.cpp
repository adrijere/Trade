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

int Trade::checkValue(int newValue)
{
  int i;
  int moyenne;
  int variance;
  int ecartType;

  i = 0;
  moyenne = 0;
  for (std::list<int>::iterator it = this->_oldValues.begin(); it != this->_oldValues.end(); ++it)
    {
      if (i < NBVAL)
	moyenne += (*it);
      else
	break ;
      i++;
    }
  moyenne /= i;
  i = 0;
  variance = 0;
  for (std::list<int>::iterator it = this->_oldValues.begin(); it != this->_oldValues.end(); ++it)
    {
      if (i < NBVAL)
	variance += pow(((*it) - moyenne), 2);
      else
	break ;
      i++;
    }
  variance /= i;
  ecartType = sqrt(variance);
  if (newValue > moyenne + ecartType)
    {
      i = 0;
      while (newValue > moyenne + ecartType)
	{
	  i++;
	  moyenne += ecartType * i;
	}
      if (newValue < ((this->_money / 2)))
	  return (1);
      return (i);
    }
  else if (newValue < moyenne - ecartType)
    {
      i = 0;
      while (newValue < moyenne + ecartType)
	{
	  i++;
	  moyenne -= ecartType * i;
	}
      if (newValue > ((this->_money / 100) * 10))
	return (-1);
      return (0 - i);
    }
  else
    return (0);
}

void Trade::trade(int newValue)
{
	int nb;

	if (this->_currentDay == this->_totalDay - 1)
		this->sell(newValue, this->_actions);
	else if (this->_oldValues.size() < NBVAL)
		this->wait();
	else 
	{
		nb = this->checkValue(newValue);
		if (nb > 0)
			this->buy(newValue, nb);
		else if (nb < 0)
			this->sell(newValue, 0 - nb);
		else
			this->wait();
	}

	this->addValue(newValue);
	this->_currentDay++;
}
