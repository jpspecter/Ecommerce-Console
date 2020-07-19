#pragma once
#include"Inventory.h"

class LinkedList{

private: 
	int size = 0; 
public:
	Inventory* head;
	LinkedList()
	{
		
		head = nullptr;
	}
	LinkedList(Inventory* ptr)
	{
		head = ptr;
	}

	void operator+=(Inventory* ptr)
	{
		size++; 
		if (head == nullptr)
		{
			head = ptr;
			head->next = nullptr;
		}
		else
		{
			Inventory* traverse = head;
			while (traverse->next != nullptr)
			{
				traverse = traverse->next;
			}

			traverse->next = ptr;
		}
	}

	Inventory* getHead() {
		return head; 
	}

	int getLength() {

		return size; 
	}
};