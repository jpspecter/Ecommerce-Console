#pragma once
#include"Inventory.h"
#include"LinkedList.h"
#include<string>

using namespace std; 

class Admin {
private: 
	string username = "admin"; 
	string password = "admin"; 
	LinkedList* list;

public: 
	string getUsername() {
		return username; 
	}

	string getPassword() {
		return password; 
	}

	Admin(LinkedList* obj) {
		list = obj; 
	}


	void setQuantity(int ProductProductNum, int quantity)
	{
		Inventory* nodePtr;
		nodePtr = list->getHead();

		while (nodePtr)
		{
			if (ProductProductNum == nodePtr->getProductNum())
			nodePtr->setQuantity(nodePtr, quantity); 
			nodePtr = nodePtr->next;
		} 
	}

	void setCost(int ProductProductNum, double cost)
	{
		Inventory* nodePtr;
		nodePtr = list->getHead();

		while (nodePtr)
		{
			if (ProductProductNum == nodePtr->getProductNum())
				nodePtr->setCost(nodePtr, cost);
			nodePtr = nodePtr->next;
		}
	}

	void AddItem(int ProductProductNum, int ProductItemNum, int ProductQuantity, double ProductCost) {
		Inventory* newNode = nullptr; 
		Inventory* nodePtr = nullptr; 
		Inventory* previousNode = nullptr;
		Inventory* nodeHead = list->getHead(); 

		int pos = 0;
			nodePtr = nodeHead;

			previousNode = nullptr;

			while (nodePtr != nullptr && pos < ProductProductNum)
			{
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
				pos++;
			}

		nodePtr->AddItem(ProductProductNum, ProductItemNum, ProductQuantity, ProductCost, previousNode, nodePtr, nodeHead); 
	}

	void DeleteItem(int ProductProductNum) {
		Inventory* nodePtr;
		Inventory* previousNode = nullptr;
		Inventory* nodeHead = list->getHead(); 

		int pos = 0;

		if (!nodeHead)
			return;

		if (ProductProductNum == 1)
		{
			nodePtr = nodeHead->next;
			delete nodeHead;
			nodeHead = nodePtr;
		}

		else
		{
			nodePtr = nodeHead;

			while (nodePtr != nullptr && pos < ProductProductNum)
			{
				pos++;
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
			}

			if (nodePtr)
			{
				previousNode->next = nodePtr->next;
				nodePtr->DeleteItem(nodePtr); 
			}
		}
	}
};
