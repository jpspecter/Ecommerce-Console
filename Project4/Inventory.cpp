#include"Inventory.h"

using namespace std; 

Inventory::Inventory() {
	itemNum = 0; 
	cost = 0.0; 
	quantity = 0; 
	productNum = 0; 
}

Inventory::Inventory(int ProductItemNum, double ProductCost, int ProductQuantity, int ProductProductNum) {
	itemNum = ProductItemNum;
	cost = ProductCost;
	quantity = ProductQuantity;
	productNum = ProductProductNum;
}

void Inventory::setQuantity(Inventory* nodePtr, int ProductQuantity) {
	
	nodePtr->quantity = ProductQuantity; 
}

void Inventory::setCost(Inventory* nodePtr, double ProductCost) {
	nodePtr->cost = ProductCost;
}

void Inventory::AddItem(int ProductProductNum, int ProductItemNum, int ProductQuantity, double ProductCost, Inventory* previousNode, Inventory* nodePtr, Inventory* nodeHead) {
	Inventory* newNode = new Inventory;
	newNode->itemNum = ProductItemNum;
	newNode->productNum = ProductProductNum;
	newNode->cost = ProductCost;
	newNode->quantity = ProductQuantity;

	if (nodeHead == nullptr)
	{
		nodeHead = newNode;
		newNode->next = nullptr;
	}
	else {
		if (previousNode == nodePtr)
		{
			nodeHead = newNode;
			newNode->next = nodePtr;
		}

		else
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}

	}

}

void Inventory::DeleteItem(Inventory* nodePtr) {
	delete nodePtr; 
	
}