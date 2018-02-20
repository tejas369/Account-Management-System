//Name :-Tejas Rajput

#include <iostream>
#include <string>
#include<fstream>
#include<sstream>
#include<utility>
#include "Account.h"
#include "bank_account.h"
#include "stock_account.h"
#include "stock_node.h"
using namespace std;

int main()
{
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;

	bankaccount B;		//calling bankaccount object
	stockaccount A;		//calling stockaccount object
	stocknode *node = NULL;	//creatin stocknode pointer

	cout << " Welcome to the Account Management System! \n";

	while (choice1 != 3)// displaying main options while it exits
	{
		cout << "\n1. Stock Portfolio Account"
			<< "\n2. Bank Account"
			<< "\n3. Exit";
		cout << "\nPlease Select Account to Access : ";
		cin >> choice1;

		switch (choice1)
		{
		case 1:
			while (choice2 != 7)// Stock Account Options displaying till it returns to previous menu
			{
				cout << "\nStock Portfolio account";
				cout << "\n1. Display the price for a Stock Symbol"
					<< "\n2. Display Current Portfolio"
					<< "\n3. Buy Shares"
					<< "\n4. Sell Shares"
					<< "\n5. View a Graph for the Portfolio Value"
					<< "\n6. View Transaction History"
					<< "\n7. Return to the Previous Menu";
				cout << "\nEnter Your Choice : ";
				cin >> choice2;
				switch (choice2)
				{
				case 1:
					A.displaystock();
					break;
				case 2:
					A.disp_portfolio();
					break;
				case 3:
					A.buyingshares();
					break;
				case 4:
					A.sellingshares();
					break;
				case 5:
					A.view_graph();
					break;
				case 6:
					A.print_history();
					break;
				
				case 7:
					break;
				default:
					cout << "\nEnter Valid Option!";
				}
			}
			choice2 = 0;
			break;
		case 2:
			
			while (choice3 != 5)// Bank account options displaying till it returns to previous meni
			{
				cout << "\nBank Account";
				cout << "\n1. View Account Balance"
					<< "\n2. Deposit Money"
					<< "\n3. Withdraw Money"
					<< "\n4. Print History"
					<< "\n5. Return to Previous Menu";
				cout << "\nEnter Your Choice : ";
				cin >> choice3;
				switch (choice3)
				{
				case 1:
					B.view_balance();
					break;
				case 2:
					B.deposit();
					A.save_port_val();
					break;
				case 3:
					B.withdraw();
					A.save_port_val();
					break;
				case 4:
					B.print_history();
					break;
				case 5:
					break;
				default:
					cout << "\nEnter Valid Option!";
				}
			}
			choice3 = 0;
			break;

		case 3:
			A.save_port();    // saving portfolio before exiting			 
			break;
		default:
			cout << "\nEnter Valid Option!";
		}
	}
}