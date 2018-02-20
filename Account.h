//Name :- Tejas Rajput

#ifndef ACCOUNT_H
#define ACCOUNT_H

class account
{
public:
	
	double get_cbal();   
	void set_cbal();		//to set the cash balance

	virtual void print_history() = 0;  //Design pattern template
	

protected:
	double cash_bal;		//store the value of cash and can be accessed from both stock and bank account

};



#endif
