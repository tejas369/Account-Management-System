//Name :-Tejas Rajput

#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <string>
#include <map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#include "Account.h"
#include "bank_account.h"

bankaccount::bankaccount()		//constructor
{	
	set_cbal();
	cash_bal = get_cbal();
	depo_cash = 0;
	with_cash = 0;
}

bankaccount::~bankaccount()	//destructor
{

}

void bankaccount::write_bal1()		//writebalance in text file
{
	ofstream myfile7;
	myfile7.open("cashbal.txt", std::ios_base::out);
	myfile7 << endl << cash_bal;
	myfile7.close();
}

void bankaccount::view_balance()	//function to view balance
{
	set_cbal();
	cash_bal = get_cbal();	//get recent cash balance
	cout << "\n You have $" << cash_bal << " in your bank account\n";
}

void bankaccount::deposit()		//deposit money 
{
	cout << "\n Please select the amount you want to deposit : ";
	cin >> depo_cash;
	set_cbal();
	cash_bal = get_cbal();
	cash_bal = cash_bal + depo_cash;
	write_bal1();
	cout << "\n Amount $" << depo_cash << " is deposited to your account\n";
	//current date and time
	time_t rawtime;
	struct tm timeinfo;
	char buffer[80];
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	strftime(buffer, 80, "%d-%m-%Y %I:%M:%S", &timeinfo);
	std::string str(buffer);
	//storing it in text file
	bank_his.open("bank_transaction_history.txt", ios::app);
	bank_his << left << setw(20) << " Deposit ";
	bank_his << left << setw(15) << depo_cash;
	bank_his << left << setw(25) << str;
	bank_his << left << setw(5) <<  cash_bal << endl;
	bank_his.close();

}

void bankaccount::withdraw()	//function to withdraw money
{
	cout << "\n Please select the amount you want to withdraw : ";
	cin >> with_cash;
	set_cbal();
	cash_bal = get_cbal();
	if (cash_bal > 0)
	{
		if (with_cash <= cash_bal)
		{

			cash_bal = cash_bal - with_cash;	//update cash balance
			write_bal1();	//store 
			cout << "\n Amount $" << with_cash << " is withdrawn from your account\n";
			//current date and time
			time_t rawtime;
			struct tm timeinfo;
			char buffer[80];
			time(&rawtime);
			localtime_s(&timeinfo, &rawtime);
			strftime(buffer, 80, "%d-%m-%Y %I:%M:%S", &timeinfo);
			std::string str(buffer);
			//store transaction
			bank_his.open("bank_transaction_history.txt", ios::app);
			bank_his << left << setw(20) << " Withdraw ";
			bank_his << left << setw(15) << with_cash;
			bank_his << left << setw(25) << str;
			bank_his << left << setw(10) << cash_bal << endl;
			bank_his.close();
		}
		else
		{
			cout << "\n Error! Balance insufficient!\n";
			return;
		}
	}
	else
	{
		cout << "\n Balance is zero\n";
	}
}

void bankaccount::print_history()	//print history
{
	string line;
	read.open("bank_transaction_history.txt", ios::app);
	cout << left << setw(20) <<" Event ";
	cout << left << setw(15) << "Amount $";
	cout << left << setw(25) << "Date & Time";
	cout << left << setw(10) << "Balance $" << endl;
	if (read.is_open())
	{
		while (!read.eof())	//till end of the file print all lines
		{
			while (getline(read, line))
				cout << line << "\n";
		}
	}
	read.close();
}