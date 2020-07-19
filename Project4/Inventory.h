#pragma once
#include<iostream>
#include<string>

using namespace std; 

class Inventory{
private: 
	int itemNum; 
	int productNum; 
	double cost; 
	int quantity;
	Inventory* head; 

public: 
	Inventory(); 

	Inventory(int ProductItemNum, double ProductCost, int ProductQuantity, int productNum);

	Inventory* next;

	int getItemNum() const {
		return itemNum; 
	}; 

	double getCost() const {
		return cost; 
	}; 

	int getQuantity() const {
		return quantity; 
	}; 

	int getProductNum() const {
		return productNum; 
	}; 

	void setQuantity(Inventory*, int ProductQuantity); 

	void setCost(Inventory*, double ProductCost); 

	void AddItem(int ProductProductNum, int ProductItemNum, int ProductQuantity, double ProductCost, Inventory*, Inventory*, Inventory*); 

	void DeleteItem(Inventory*); 


}; 

