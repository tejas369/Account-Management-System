//Name :-Tejas Rajput

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <iostream>
#include <fstream>
#include <string>
#include<map>
#include<time.h>

#include "Account.h"

using namespace std;

class bankaccount :public account
{
public:
	bankaccount();
	~bankaccount();
	void view_balance();
	void deposit();
	void withdraw();
	virtual void print_history();
	void write_bal1();
private:
	double depo_cash;
	double with_cash;
	ofstream bank_his;
	ifstream read;

};

#endif

