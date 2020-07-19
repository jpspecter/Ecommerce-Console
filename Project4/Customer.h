#pragma once
#include<string>
#include"LinkedList.h"
#include"Inventory.h"

using namespace std; 

class Customer{
private: 
	string firstName; 
	string lastName; 
	string address; 
	string city; 
	string state; 
	int zipCode; 
	int num = 0; 
	string invoiceFileName; 
	Inventory* ShoppingCartPtr; 
	LinkedList ShoppingCart; 


public: 
	Customer(); 
	Customer(string Cfirstname, string Clastname, string Caddress, string Cstate, string Ccity, int zipCode); 

	void add(int itemNum, double cost, int quantity) {
		num++; 
		ShoppingCartPtr = new Inventory(itemNum, cost, quantity, num);
		ShoppingCart += ShoppingCartPtr; 
	}

	void print() {
		Inventory* ptr = ShoppingCart.getHead();

		while (ptr != nullptr)
		{
			cout << ptr->getItemNum() << " " << ptr->getProductNum() << " " << ptr->getQuantity() << " " << ptr->getCost() << endl;
			ptr = ptr->next;
		}
	}

};
