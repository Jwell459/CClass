/*
James Stockwell

Programming Assignment Chapter 13

October 2021
*/

#include <iostream>
#include <iomanip>
#include "inventory.h"

using namespace std;

//Constant for repairList's array size, also used for loops that go through it
const int ARRAY_SIZE = 5;

//Protoypes for functions
void inputCheck(inventory list[ARRAY_SIZE], int index);
void inputDesc(inventory list[ARRAY_SIZE], int index);
void inputCust(inventory list[ARRAY_SIZE], int index);
void inputPhone(inventory list[ARRAY_SIZE], int index);
void inputPrice(inventory list[ARRAY_SIZE], int index);
void inputHours(inventory list[ARRAY_SIZE], int index);
void displayInventories(inventory list[ARRAY_SIZE]);
void totalQuotes(inventory list[ARRAY_SIZE]);


/************************************************************************************
name:		main
called by:	none
passed:		none
returns:	none
calls:		inputCheck, inputDesc, inputCust, inputPrice, inputHours, displayInventories, totalQuotes

Starts the program. Intialzies repairList to a list of blank inventory objects, 
calls functions to have the user fill out the attributes of each object, then calls other
functions to display each object and the total of the quotes
************************************************************************************/
int main() {

	inventory repairList[ARRAY_SIZE];		//Declaration of the object list

	for (int i = 0; i < ARRAY_SIZE; i++)	//Creates a blank invetory object for each index in repairList
		repairList[i] = inventory();



	for (int i = 0; i < ARRAY_SIZE; i++) {	//Goes through each repairList object and calls the functions that ask the user to fill them out

		cout << "Input data for customer " << i+1 <<"\n";

		inputCheck(repairList, i);
		inputDesc(repairList, i);
		inputCust(repairList, i);
		inputPhone(repairList, i);
		inputPrice(repairList, i);
		inputHours(repairList, i);
	}

	//These last 2 lines display the attributes and quote total in an orderly fashion
	displayInventories(repairList);
	totalQuotes(repairList);
};


/************************************************************************************
name:		inputCheck
called by:	main
passed:		inventory list[ARRAY_SIZE], int index
returns:	none
calls:		list[index].setCheckInNumber

Asks for user input, validates it, then calls the designated inventory object's mutator 
function for the checkInNumber attribute
************************************************************************************/
void inputCheck(inventory list[ARRAY_SIZE], int index) {
	int inputCheck;
	cout << "Set the check in number: ";
	while (!(cin >> inputCheck) || inputCheck <= 0) {	//Takes user input and validates it
		cin.clear();
		cin.ignore();
		cout << "Invalid input, please try again: ";	//Asks for input again if previous input was invalid
	}
	list[index].setCheckInNumber(inputCheck);			//Assigns the validated user input to the object's checkinNumber attribute via the mutator
	cin.ignore();										//Clears the cin buffer
}

/************************************************************************************
name:		inputDesc
called by:	main
passed:		inventory list[ARRAY_SIZE], int index
returns:	none
calls:		list[index].setWorkDescription

Asks for user input, validates it, then calls the designated inventory object's mutator
function for the workDescription attribute
************************************************************************************/
void inputDesc(inventory list[ARRAY_SIZE], int index) {
	string inputDesc;
	cout << "Set the description: ";
	getline(cin, inputDesc);							//Takes user input
	while (!(inputDesc.length() < 30)) {				//Valdates input
		cout << "Invalid input, please try again: ";
		getline(cin, inputDesc, '\n');					//Asks for input again if previous input was invalid
	}
	list[index].setWorkDescription(inputDesc);			//Assigns the validated user input to the object's workDescription attribute via the mutator
}

/************************************************************************************
name:		inputCust
called by:	main
passed:		inventory list[ARRAY_SIZE], int index
returns:	none
calls:		list[index].setCustomerLast

Asks for user input, validates it, then calls the designated inventory object's mutator
function for the customerLast attribute
************************************************************************************/
void inputCust(inventory list[ARRAY_SIZE], int index) {
	string inputCust;
	cout << "Set the last customer: ";
	getline(cin, inputCust, '\n');						//Takes user input
	while (!(inputCust.length() < 30)) {				//Valdates input
		cout << "Invalid input, please try again: ";
		getline(cin, inputCust, '\n');					//Asks for input again if previous input was invalid
	}
	list[index].setCustomerLast(inputCust);				//Assigns the validated user input to the object's customerLast attribute via the mutator
}

/************************************************************************************
name:		inputPhone
called by:	main
passed:		inventory list[ARRAY_SIZE], int index
returns:	none
calls:		list[index].setCustPhone

Asks for user input, validates it, then calls the designated inventory object's mutator
function for the custPhone attribute
************************************************************************************/
void inputPhone(inventory list[ARRAY_SIZE], int index) {
	string inputPhone;
	cout << "Set the customer's phone number: ";
	while (!(cin >> inputPhone) || (!(inputPhone.length() < 11))) { //Takes user input and validates it
		cin.clear();
		cin.ignore();
		cout << "Invalid input, please try again: ";	//Asks for input again if previous input was invalid
	}
	list[index].setCustPhone(inputPhone);				//Assigns the validated user input to the object's custPhone attribute via the mutator
}

/************************************************************************************
name:		inputPrice
called by:	main
passed:		inventory list[ARRAY_SIZE], int index
returns:	none
calls:		list[index].setPriceQuoted

Asks for user input, validates it, then calls the designated inventory object's mutator
function for the priceQuoted attribute
************************************************************************************/
void inputPrice(inventory list[ARRAY_SIZE], int index) {
	float inputPrice;
	cout << "Set the quoted price: ";
	while (!(cin >> inputPrice) || !(inputPrice >= 0)) {	//Takes user input and validates it
		cin.clear();
		cin.ignore();
		cout << "Invalid input, please try again: ";		//Asks for input again if previous input was invalid
	}
	list[index].setPriceQuoted(inputPrice);				//Assigns the validated user input to the object's priceQuoted attribute via the mutator
}

/************************************************************************************
name:		inputHours
called by:	main
passed:		inventory list[ARRAY_SIZE], int index
returns:	none
calls:		list[index].setEstimatedHours

Asks for user input, validates it, then calls the designated inventory object's mutator
function for the estimatedHours attribute
************************************************************************************/
void inputHours(inventory list[ARRAY_SIZE], int index) {
	float inputHours;
	cout << "Set the estimated hours: ";
	while (!(cin >> inputHours) || !(inputHours >= 0)) {	//Takes user input and validates it
		cin.clear();
		cin.ignore();
		cout << "Invalid input, please try again: ";		//Asks for input again if previous input was invalid
	}
	list[index].setEstimatedHours(inputHours);		//Assigns the validated user input to the object's estimatedHours attribute via the mutator
	cout << "\n";
}

/************************************************************************************
name:		displayInventories
called by:	main
passed:		inventory list[ARRAY_SIZE]
returns:	none
calls:		list[i].getCheckInNumber(), list[i].getWorkDescription(), list[i].getCustomerLast(), list[i].getPriceQuoted(), list[i].getEstimatedHours()

Displays the attibutes of each inventory object in list in organized fashion by using the objects' accsessor functions
************************************************************************************/
void displayInventories(inventory list[ARRAY_SIZE]) {
	cout << "Washington Acoustic Guitar Repair Shop\n\n";		//Name of shop / title of list
	for (int i = 0; i < ARRAY_SIZE; i++) {

		cout << left << setw(30) << "Check In Number:" << list[i].getCheckInNumber() << "\n";		//Displays the object's checkInNumber attribute
		cout << left << setw(30) << "Work Description:" << list[i].getWorkDescription() << "\n";	//Displays the object's workDescription attribute
		cout << left << setw(30) << "Customer:" << list[i].getCustomerLast() << "\n";				//Displays the object's customerLast attribute
		cout << left << setw(30) << "Phone:" << list[i].getCustPhone() << "\n";						//Displays the object's custPhone attribute
		cout << left << setw(30) << "Price Quoted:" << '$' << setprecision(2) << fixed << list[i].getPriceQuoted() << "\n";			//Displays the object's priceQuoted attribute
		cout << left << setw(30) << "Estimated Hours:" << setprecision(1) << fixed << list[i].getEstimatedHours() << "\n";		//Displays the object's estimatedHours attribute
		cout << "\n";
	}
}

/************************************************************************************
name:		displayInventories
called by:	main
passed:		inventory list[ARRAY_SIZE]
returns:	none
calls:		list[i].getPriceQuoted

Calculates and displays the sum of every priceQuoted attribute from the inventory objects in list
************************************************************************************/
void totalQuotes(inventory list[ARRAY_SIZE]) {
	float totalQuotes = 0;
	for (int i = 0; i < ARRAY_SIZE; i++)			//Goes through each object in list and adds it value to the totalQuotes variable
		totalQuotes += list[i].getPriceQuoted();

	cout << "\n---------------------------------------------------\n";	
	cout << "Total Quotes: $" << setprecision(2) << fixed << totalQuotes;	//displays the totalQuotes variable
}