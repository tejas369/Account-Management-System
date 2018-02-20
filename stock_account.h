//Name :-Tejas Rajput

#ifndef STOCK_ACCOUNT_H
#define STOCK_ACCOUNT_H

#include "Account.h"
#include "stock_node.h"

#include <iostream>
#include <fstream>
#include <string>
#include<map>

using namespace std;

typedef map<string, double>type;			//name STL map as type

class stockaccount : public account
{	
public:
	stockaccount();
	~stockaccount();
	type select(type , type );
	void displaystock();
	bool isEmpty() const;
	stocknode * search(string);
	void buy_update(string , int );
	void sell_update(stocknode*, int);
	void sort();
	void buyingshares();
	void disp_portfolio();
	void sellingshares();
	virtual void print_history();
	void save_port();
	void read_port();
	void write_bal();
	void save_port_val();
	void read_port_val();
	void view_graph();

private:
	int size;
	ofstream stock_his, bank_his;
	double s_price;
	double max_amt,min_amt, total_amt;
	int NOS;
	string stocksymb;
	double price1;
	string symbol1;
	
	type result1;
	type result2;
	type temp;
	type duplicate;
	stringstream A,B;
	string line, line1;
	ifstream r1, r2;
	stocknode *headptr;
	stocknode *tailptr;
	double array1[100];
	int d , g;
	string time1[100];
};

#endif
