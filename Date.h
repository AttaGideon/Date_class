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
	
	// TODO: add operators if required for the test cases
	/* <, > ==, ...*/

private:
	int _day;
	int _month;
	int _year;
	int _dayCount = 0;
	std::string DateToString;
  
};
#endif
