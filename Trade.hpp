#ifndef _TRADE_HPP_
# define _TRADE_HPP_

# include <iostream>
# include <string>
# include <list>
# include <stdlib.h>



class Trade
{
private:
	int _money;
	int _totalDay;
	int _currentDay;
	int _actions;
	std::list<int> _oldValues;
public:
	Trade(int, int);
	~Trade();

	void setMoney(int);
	int getMoney() const;
	void setTotalDay(int);
	int getTotalDay() const;
	void setCurrentDay(int);
	int getCurrentDay() const;

	void addValue(int);
	void delValue();

	void buy(int, int);
	void sell(int, int);
	void wait();

	void trade(int);
};

#endif
