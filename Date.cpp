#include "Date.h"

Date::Date()
{
	_day = 1;
	_month = 1;
	_year = 1970;
}
Date::Date(int day, int month, int year)
{
	if(!(CheckMonth(day, month, year)))
		std::cout << "Can't set Date: Invalid Argument" << std::endl;
	else
	{
		_day = day;
		_month = month;
		_year = year;
	}
}
Date::Date(const Date &otherDate)
{
	_day = otherDate._day;
	_month = otherDate._month;
	_year = otherDate._year;
}
Date::~Date(){}
void Date::DisplayDate()
{
	std::cout << _day <<"." << _month << "." << _year << std::endl;
}
bool Date::setDate(int day, int month, int year)
{
	if(!(CheckMonth(day, month, year)))
	{
		std::cout << "Can't set Date: Invalid Argument" << std::endl;
		return false;
	}
	else
	{
		_day = day;
		_month = month;
		_year = year;
		return true;
	}
}
bool Date::checkDate(int day, int month, int year)
{
	if(!(CheckMonth(day, month, year)))
		{
			std::cout << "Day/Month is invalid"<< std::endl;
			return false;
		}

	else
		if(year > 9999)
			{
				std::cout << "Year Limit is reached (9999), reset year" << std::endl;
				return false;
			}

		else return true;
}
bool Date::isBefore(Date &otherDate)
{
	bool check = CheckMonth(otherDate._day, otherDate._month, otherDate._year);

	if(!check)
	{
		std::cout << "Error with Date. " << std::endl;
		return false;
	}
	else
		if(Date(_day, _month, _year) < otherDate)
			return true;

		else return false;
}
bool Date::CheckMonth(int day, int month, int year)
{
	int dayCountInAMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(month >0 && month <= 12)
	{
		if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
			dayCountInAMonth[1] = 29;
		if(day > 0 && day <= dayCountInAMonth[month-1])
			_dayCount = dayCountInAMonth[month -1];
		else
			return false;
		return true;
	}
	else
		return false;
}
Date Date::addDay()
{
	int iday = _day;
	int imonth = _month;
	int iyear = _year;
	bool check = CheckMonth(iday, imonth, iyear);

	if(!check){
		std::cout << "Day/Month is invalid!" << std::endl;
		return Date();
	}
	if(iday < _dayCount) _day += 1;
	if(iday == _dayCount && imonth < 12)
	{
		_month += 1;
		_day = 1;
	}
	if(iday == _dayCount && imonth == 12)
	{
		_month = 1;
		_day = 1;
		_year +=1;
	}
	return Date(_day, _month, _year);
}













