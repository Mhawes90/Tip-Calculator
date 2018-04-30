// ch7pc6.cpp : Defines the entry point for the console application.
//
/* 
 * by Mark Hawes
 * Tip Calculator program demonstrates the use of classes in C++ to have a portable class that can
 * calculate and return tip amount for use in a more complete program
 * last updated 7/31/17
 */

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

double convertTipRate(double &tipRate);
void closeMessage();

// class Tips -- uses tax rate, tip rate, and total bill to calculate amount of tip to give
class Tips {
private:
	const double defTaxRate = .065;
	double taxRate, mealCost;

public:
	Tips() // default constructor
	{
		taxRate = defTaxRate;
	}

	Tips(double inTaxRate) // constructor with input
	{
		taxRate = inTaxRate;
	}

	double computeTip(double &billTotal, double &tipRate); // prototype
};

// implementation code
double Tips::computeTip(double &billTotal, double &tipRate) {
	mealCost = billTotal - (billTotal * taxRate); // get bill without tax factored in

	return mealCost * tipRate;
}

int main()
{
	// set precision output for decimals
	cout << fixed;
	cout << setprecision(2);
	// declarations
	Tips tipCalc;
	double bill, tipRate;
	char userIn;

	cout << "Welcome to the Tip Calculator!\n\n";

	while (true) {
		// request user input
		cout << "Enter bill total: \n";
		cin >> bill;

		cout << "\nEnter tip rate in decimal: \n";
		cin >> tipRate;

		// output values for user
		cout << "\nThe total cost of your bill: $" << bill;
		cout << "\nWith a tip rate of: " << convertTipRate(tipRate) << "%, you should give a tip of: "
			<< tipCalc.computeTip(bill, tipRate);

		// prompt user to continue or not
		cout << "\n\nWould you like to calculate another tip(y/n)?";
		cin >> userIn;

		if (tolower(userIn) == 'y') {
			system("cls");
		}
		else
			break;
	}

	cout << "\n\nThank you for using the Tip Calculator";

	closeMessage(); // stops program from auto closing
    return 0;
}

// converts tip rate into an easier output value
double convertTipRate(double &tipRate) {
	return tipRate * 100;
}

/********************************************
 *				closeMessage				*
 * final statement of program that stops it	*
 * from closing until user enters input		*
 ********************************************/
void closeMessage() {
	cout << "\nPress enter to exit program.\n";
	getchar();
	getchar();
}