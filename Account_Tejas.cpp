//Name:- Tejas Rajput

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#include "Account.h"

double account::get_cbal()			//definition ogf getting cash balance
{
	return cash_bal;		
}

void account::set_cbal()		//definition of set balance function
{
	int flag=0;				
	ifstream myfile1;
	myfile1.open("cashbal.txt",ios_base::in);		//open cashbalance text file
	if (myfile1.is_open())							//check if any previous entry of cash balance is der or not
	{
		while (!myfile1.eof())
		{
			char ch = (char)myfile1.get();
			flag++;
			break;
		}
	}
	myfile1.close();

	if (flag==0) // if previous cash entry not found, create the file and put 10,000 cash balance into it.
	{
		double og_balance = 10000.00;

		ofstream myfile2;
		myfile2.open("cashbal.txt", ios_base::out);
		myfile2 << og_balance;
		myfile2.close();


		// read balance of 10,000 from file
		ifstream readfile("cashbal.txt", ios_base::in);
		readfile >> cash_bal;
		readfile.close();
	}
	else
	{
		//  set balance from existing cash balance file if previous cash entry found.
		ifstream readbalance("cashbal.txt", ios_base::in);
		readbalance >> cash_bal;
		readbalance.close();
	}
}


