// My Mortgage Calculator
// A simple program which asks for user input on their mortgage data, and calculate what they select to know
// Sources: 
// http://homeguides.sfgate.com/average-cost-homeowners-insurance-3020.html
// http://www.nytimes.com/2007/04/10/business/11leonhardt-avgproptaxrates.html?_r=0
// http://www.hughcalc.org/formula.php

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <stdio.h>

using namespace std;

long int HOUSE_VALUE;
long int PRINCIPAL; 
float MONTHLY_INTEREST;
int TERMS;
float TAX_RATE; // number between 0 and 100

double MONTHLY_PAYMENT;

void getUserInput() {
	string user_input;
	
	// get HOUSE_VALUE
	cout << "To the nearest dollar, how much is the final house value? ";
	getline(cin, user_input);
	stringstream(user_input) >> HOUSE_VALUE;
	
	// get PRINCIPAL
	long int down;
	cout << "To the nearest dollar, how much is your down payment? ";
	getline(cin, user_input);
	stringstream(user_input) >> down;
	PRINCIPAL = HOUSE_VALUE - down;
	cout << endl << "Great! Your mortgage principal is : $" << PRINCIPAL << endl << endl;
	
	// get INTEREST_RATE
	float rate;
	cout << "What is the yearly interest rate? (Example: 4.5): ";
	getline(cin, user_input);
	stringstream(user_input) >> rate;
	MONTHLY_INTEREST = rate/(100*12);
	
	// get TERMS
	int years;
	cout << "How many years is your mortgage? ";
	getline(cin, user_input);
	stringstream(user_input) >> years;
	TERMS = years * 12;
	
	// get TAX_RATE
	cout << "What is the tax rate? Enter 'std' to use the U.S. standard tax rate of 1.38 ";
	getline(cin, user_input);
	if (user_input.compare("std") == 0)
		TAX_RATE = 1.38;
	else
		stringstream(user_input) >> TAX_RATE;
	
}

void calculateMonthlyPayment() {
	MONTHLY_PAYMENT = PRINCIPAL * ( MONTHLY_INTEREST / (1 - pow(1 + MONTHLY_INTEREST, -TERMS)));
}

double calculateTax() {
	return HOUSE_VALUE * TAX_RATE / 100 / 12;
}

double calculateInsurance() {
	return HOUSE_VALUE / 1000 * 3.5 / 12;
}

int main () {
	getUserInput();
	
	// monthly payment pre-tax
	cout << "Calculating..." << endl << endl;
	calculateMonthlyPayment();
	cout << "Your MONTHLY PAYMENT pre-tax is: $" << MONTHLY_PAYMENT << endl;
	 
	// with tax
	double tax_monthly = calculateTax();
	double insurance_monthly = calculateInsurance();
	cout << "Monthly, you should set aside for tax: $" << tax_monthly << endl;
	cout << "and this much for insurance: $" << insurance_monthly << endl;
	cout << "making it a total monthly payment of: $" << (MONTHLY_PAYMENT + tax_monthly + insurance_monthly) << endl;
	
	return 0;
}