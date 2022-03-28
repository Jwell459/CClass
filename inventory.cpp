/*
James Stockwell

Programming Assignment Chapter 13

October 2021
*/

#include <iostream>
#include "inventory.h"

/*----------------------------------------------------------------------------------------------------------------
class name:			inventory

attributes:		checkInNumber, workDescription, customerLast, custPhone, priceQuoted, estimatedHours 
methods:		getCheckInNumber, getWorkDescription, getCustomerLast, getCustPhone, getPriceQuoted, getEstimatedHours,
				setCheckInNumber, setWorkDescription, setCustomerLast, setCustPhone, setPriceQuoted, setEstimatedHours

Stores infromation for repair jobs at the Washington Acoustic Guitar Repair Shop
----------------------------------------------------------------------------------------------------------------*/


/************************************************************************************
name:		inventory
called by:	main
passed:		none
returns:	none
calls:		none

Default constructor
************************************************************************************/
inventory::inventory() {
	checkInNumber = 0;
	workDescription = "";
	customerLast = "";
	custPhone = "";
	priceQuoted = 0;
	estimatedHours = 0;
}


//Accessor methods
/************************************************************************************
name:		getCheckInNumber
called by:	displayInventories in main.ccp
passed:		none
returns:	checkInNumber
calls:		none

Accessor for checkInNumber
************************************************************************************/
int inventory::getCheckInNumber() const{
	return checkInNumber;
}

/************************************************************************************
name:		getWorkDescription
called by:	displayInventories in main.ccp
passed:		none
returns:	workDescription
calls:		none

Accessor for workDescription
************************************************************************************/
string inventory::getWorkDescription() const {
	return workDescription;
}

/************************************************************************************
name:		getCustomerLast
called by:	displayInventories in main.ccp
passed:		none
returns:	customerLast
calls:		none

Accessor for customerLast
************************************************************************************/
string inventory::getCustomerLast() const {	
	return customerLast;
}

/************************************************************************************
name:		getCustPhone
called by:	displayInventories in main.ccp
passed:		none
returns:	custPhone
calls:		none

Accessor for custPhone
************************************************************************************/
string inventory::getCustPhone() const { 
	return custPhone;
}

/************************************************************************************
name:		getPricedQuoted
called by:	displayInventories in main.ccp
passed:		none
returns:	priceQuoted
calls:		none

Accessor for priceQuoted
************************************************************************************/
float inventory::getPriceQuoted() const {
	return priceQuoted;
}

/************************************************************************************
name:		getEstimatedHours
called by:	displayInventories in main.ccp
passed:		none
returns:	estimatedHours
calls:		none

Accessor for estimatedHours
************************************************************************************/
float inventory::getEstimatedHours() const {
	return estimatedHours;
}



//Mutator methods
//Each mutator validates the parameter before assigneing the given value to attributes
/************************************************************************************
name:		setCheckInNumber
called by:	inputCheck in main.ccp
passed:		int value
returns:	none
calls:		none

Mutator for checkInNumber with input validation
************************************************************************************/
void inventory::setCheckInNumber(int value) {
	if (value <= 0) {			//Input validation, will give an exit failure if invalid
		cout << "Invalid input! Must be a postive integer.";
		exit(EXIT_FAILURE);
	}
	else
		checkInNumber = value;
}

/************************************************************************************
name:		setWorkDescription
called by:	inputDesc in main.ccp
passed:		string desc
returns:	none
calls:		none

Mutator for workDescription with input validation
************************************************************************************/
void inventory::setWorkDescription(string desc) {
	if (desc.length() >= 30) {			//Input validation, will give an exit failure if invalid
		cout << "Invalid input! Must be less than 30 characters.";
		exit(EXIT_FAILURE);
	}
	else
		workDescription = desc;
}

/************************************************************************************
name:		setCustomerLast
called by:	inputCust in main.ccp
passed:		string name
returns:	none
calls:		none

Mutator for customerLast with input validation
************************************************************************************/
void inventory::setCustomerLast(string name) {
	if (name.length() >= 30) {			//Input validation, will give an exit failure if invalid
		cout << "Invalid input! Must be less than 30 characters.";
		exit(EXIT_FAILURE);
	}
	else
		customerLast = name;
}

/************************************************************************************
name:		setCustPhone
called by:	inputPhone in main.ccp
passed:		phone desc
returns:	none
calls:		none

Mutator for custPhone with input validation
************************************************************************************/
void inventory::setCustPhone(string phone) {
	if (phone.length() >= 11) {			//Input validation, will give an exit failure if invalid
		cout << "Invalid input! Must be less than 11 characters.";
		exit(EXIT_FAILURE);
	}
	else
		custPhone = phone;
}

/************************************************************************************
name:		setPriceQuoted
called by:	inputPrice in main.ccp
passed:		float price
returns:	none
calls:		none

Mutator for priceQuoted with input validation
************************************************************************************/
void inventory::setPriceQuoted(float price) {
	if (price < 0) {			//Input validation, will give an exit failure if invalid
		cout << "Invalid input! Price cannot be negative.";
		exit(EXIT_FAILURE);
	}
	else
		priceQuoted = price;
}

/************************************************************************************
name:		setEstimatedHours
called by:	inputHours in main.ccp
passed:		float hours
returns:	none
calls:		none

Mutator for estimatedHours with input validation
************************************************************************************/
void inventory::setEstimatedHours(float hours) {
	if (hours < 0) {			//Input validation, will give an exit failure if invalid
		cout << "Invalid input! Hours cannot be negative.";
		exit(EXIT_FAILURE);
	}
	else
		estimatedHours = hours;
}