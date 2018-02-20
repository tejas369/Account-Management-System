#ifndef STOCK_NODE_H
#define STOCK_NODE_H

#include<iostream>
#include<string>
#include "Account.h"
using namespace std;

class stocknode
{
	friend class stockaccount;

public:
	stocknode(string& s, int n) :symbol(s), nos(n)
	{
		this->next = NULL;
		this->prev = NULL;
	}

private:
	stocknode *next;
	stocknode *prev;
	string symbol;
	int nos;


};
#endif

