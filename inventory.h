/*
James Stockwell

Programming Assignment Chapter 13

October 2021
*/

#pragma once
#include <string>
using namespace std;

/************************************************************************************
class name:			inventory

attributes:		checkInNumber, workDescription, customerLast, custPhone, priceQuoted, estimatedHours
methods:		getCheckInNumber, getWorkDescription, getCustomerLast, getCustPhone, getPriceQuoted, getEstimatedHours,
				setCheckInNumber, setWorkDescription, setCustomerLast, setCustPhone, setPriceQuoted, setEstimatedHours

Stores infromation for repair jobs at the Washington Acoustic Guitar Repair Shop
************************************************************************************/

class inventory {
	private:
		int checkInNumber;
		string workDescription;
		string customerLast;
		string custPhone;
		float priceQuoted;
		float estimatedHours;

	public:
		//Constructor
		inventory();

		//Accsessors
		int getCheckInNumber() const;
		string getWorkDescription() const;
		string getCustomerLast() const;
		string getCustPhone() const;
		float getPriceQuoted() const;
		float getEstimatedHours() const;

		//Mutators
		void setCheckInNumber(int value);
		void setWorkDescription(string desc);
		void setCustomerLast(string name);
		void setCustPhone(string phone);
		void setPriceQuoted(float price);
		void setEstimatedHours(float hours);
};

