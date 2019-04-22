// MatchingEngineSCP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <map>
#include <iostream>
#include <sstream>

using namespace std; 

typedef enum _OrderType
{
	BUY = 1, //buy an order of specified stock 
	SELL = 2, //sell an order of specific stock 
	CANCEL =3 , //Cancel an exisiting order if it exist in orderbook 
	MODIFY =4 , // modify an exisitng order if it exist in orderbook 
	PRINT =5, // Print Orderbook 
}OrderType;



typedef struct _Order
{	
	string OrderType; //GFD or IOC
	int64_t Price; //price for buy or sell or order 
	int64_t Quantity;
	string  OrderId; 
}Order;




class MatchingEngine
{
public : 
	MatchingEngine();
	void ProcessMessage(string const &message);

private:
	Order Order_Lo;

};

MatchingEngine::MatchingEngine():Order_Lo(0)
{

}
void MatchingEngine::ProcessMessage(string const &message)
{

}

int main()
{
	vector<string> messages; 
	messages.push_back("BUY GFD 11 100 order1");
	messages.push_back("BUY GFD 10 100 order2");
	messages.push_back("Modify order2 SELL 10 1000");
	messages.push_back("PRINT"); 


	for (auto const &m : messages)
		std::cout << m << endl; 

	for (auto const &message : messages)
		processMessage(message);

	getchar();
    return 0;
}

