//============================================================================
// Name        : TestDate.cpp
// Author      : Gideon Atta
// Description : Date class 
// License     : Free to use and Modify
//============================================================================
#include "Date.hpp"
#include <iostream>

using namespace std;

int main() {
	
	cout << "!!!Date, Looking Good!!!";
	cout << "\n\n";

	Date epoch_date = Date();
	cout << "Time-tracking in computing is done as a count since: " << epoch_date << endl;

	Date today(11,11,2022);
	cout << "\nToday is: \n\t\t" << today << endl;

	Date today1 = today;
	Date tomorrow = today1.addDay();
	cout << "\nTomorrow is: \n\t\t" << tomorrow <<endl << endl;

	if(today.isBefore(tomorrow))
		cout << today << " is before " << tomorrow << endl <<endl;
	else
		cout << tomorrow << " is after " << today << endl;

	Date setAnotherDate;
	setAnotherDate.setDate(31, 12, 2022);
	cout << "Another set Date: \n\t\t" << setAnotherDate << endl;

	Date lastDate22(31,12,2022);
	if((lastDate22.checkDate(31, 12, 2022)))
	{
		cout << "\n2022 last day checked. It's Saturday:\n";
		cout << "\t\t\t\t\t" << lastDate22 << endl;
	}
	else
		cout << "Invalid Date!!!" << endl;


	return 0;
}
