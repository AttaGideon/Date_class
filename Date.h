#ifndef DATE_HPP
#define DATE_HPP
#include <iostream>
#include <sstream>
#include <string>

class Date
{
public:
	Date();  // Default constructor
	Date(int day, int month, int year); // main constructor
	Date(const Date &otherDate);  // copy constructor
	~Date(); //Detructor

	void DisplayDate(); // To display the date.
	bool CheckMonth(int day, int month, int year);  // To check if the entered day of the month is correct.
	bool setDate(int day, int month, int year);  // Check if the entered date is correct and set the  new date
	bool checkDate(int day, int month, int year);  // Check if the entered date is correct
	bool isBefore(Date &otherDate);  // defines which date comes first
	Date addDay();  // add a day to the correct date
	
	// Required (overloaded) operators
	operator const char *()
	{
		std::ostringstream formattedDate;
		formattedDate << _day << "." << _month << "." << _year;

		DateToString = formattedDate.str();
		return DateToString.c_str();
	}
	Date operator --()
	{
		--_day;
		return *this;
	}
	Date operator ++()
	{
		++_day;
		return *this;
	}
	Date operator = (const Date &otherDate)
	{
		// std::cout << "Creating Deep Copy" << std::endl;
		_day = otherDate._day;
		_month = otherDate._month;
		_year = otherDate._year;
		return *this;
	}
	bool operator == (const Date& otherDate) const
	{
		return ((_day == otherDate._day)
				&& (_month == otherDate._month)
				&& (_year == otherDate._year));
	}
	bool operator < (const Date &otherDate)
	{
		if(_year < otherDate._year)
			return true;

		else if((_year == otherDate._year) && (_month < otherDate._month))
			return true;

		else if((_day < otherDate._day) && (_month == otherDate._month) && (_year == otherDate._year))
			return true;

		else return false;

	}
	bool operator <= (const Date &otherDate)
	{
		if(this->operator ==(otherDate))
			return true;
		else
			return (this->operator < (otherDate));
	}
	bool operator > (const Date &otherDate)
	{
		return !(this->operator <= (otherDate));
	}
	
private:
	int _day;
	int _month;
	int _year;
	int _dayCount = 0;
	std::string DateToString;
  
};
#endif
