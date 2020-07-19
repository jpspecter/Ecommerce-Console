#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "LinkedList.h"
#include"Inventory.h"
#include"Admin.h"
#include"Customer.h"
#include <iomanip>
#include <sstream>

using namespace std;


bool readFile(fstream&);
void admin(LinkedList*); 
void customer(LinkedList*); 

int main()
{
	fstream dataFile;
	string line;
	Inventory* obj; 
	LinkedList l1; 

	if (readFile(dataFile))
	{
		while (getline(dataFile, line))
		{
			string stritemNum, strproductNum, strcost, strquantity;
			stringstream linestream(line);

			getline(linestream, stritemNum, ',');
			getline(linestream, strproductNum, ',');
			getline(linestream, strcost, ',');
			getline(linestream, strquantity);

			int itemNum = stoi(stritemNum);

			//To convert a string like "Product 1" to an int (1) using character arrays 
			int n = strproductNum.length();
			int m = -1;
			for (int i = 0; i < n; i++)
			{
				if (strproductNum[i] == ' ')
				{
					m = i + 1;
				}
			}
			string t1 = strproductNum.substr(m);
			int productNum = stoi(t1);
			double cost = stof(strcost);
			int quantity = stoi(strquantity);

			obj = new Inventory(itemNum, cost, quantity, productNum);
			l1 += obj;

		}

		string role;

		while (true)
		{
			cout << "Are you an admin or a customer" << endl;
			cin >> role;

			if (role == "admin")
			{
				admin(&l1); 
			}

			if (role == "customer")
			{
				cout << l1.getLength() << endl; 
				customer(&l1); 
			}

			if (role != "customer" && role != "admin")
			{
				cout << "Please enter a valid role" << endl;
				continue;
			}
		}

	}

	system("pause"); 
}


//Reads input file and returns true if read was successful
bool readFile(fstream &dataFile)
{
	dataFile.open("ProductData.csv", ios::in);

	bool flag = false;

	if (!dataFile)
	{
		cout << "Error opening the file" << endl;
	}

	else
	{
		flag = true;

		dataFile.clear();
	}


	return flag;
}

void admin(LinkedList* l1) {

	string username, password;
	
	cout << "Enter username and password" << endl;
	cin >> username >> password;

	Admin admin1(l1);

	if (username == admin1.getUsername() && password == admin1.getPassword())
	{
		char choice;

		cout << "Do you want to add a new product into the list? Type Y or N" << endl;
		cin >> choice;

		while (choice == 'Y' || choice == 'y')
		{
			int itemNum, productNum, quantity;
			double cost;

			cout << "Enter product num of new product" << endl;
			cin >> productNum;
			cout << "Enter item number of new product" << endl;
			cin >> itemNum;
			cout << "Enter cost of new product" << endl;
			cin >> cost;
			cout << "Enter quantity of new product" << endl;
			cin >> quantity;


			admin1.AddItem(productNum, itemNum, quantity, cost);

			cout << "Do you want to add a new product at the end of the list? Type Y or N" << endl;
			cin >> choice;
		}

		cout << "Do you want to remove a product from the list? Type Y or N" << endl;
		cin >> choice;

		while (choice == 'Y' || choice == 'y')
		{
			int productNum;

			cout << "Enter Product Number of the product to be deleted";
			cin >> productNum;

			//Removes a product from the linked list
			admin1.DeleteItem(productNum);

			cout << "Do you want to remove a product from the list? Type Y or N" << endl;
			cin >> choice;
		}

		cout << "Do you want to change the quantity of a product" << endl;
		cin >> choice;

		while (choice == 'Y' || choice == 'y')
		{
			int quantity, productNum;

			cout << "Enter product number of the product whose quantity is to be changed" << endl;
			cin >> productNum;

			cout << "Enter new quantity" << endl;
			cin >> quantity;

			//Changes the quantity of a product
			admin1.setQuantity(productNum, quantity);

			cout << "Do you want to change the quantity of a product" << endl;
			cin >> choice;
		}

		cout << "Do you want to change the cost of a product" << endl;
		cin >> choice;

		while (choice == 'Y' || choice == 'y')
		{
			int productNum;
			double cost;

			cout << "Enter product number of the product whose cost is to be changed" << endl;
			cin >> productNum;

			cout << "Enter new cost" << endl;
			cin >> cost;

			//Changes the quantity of a product
			admin1.setCost(productNum, cost);

			cout << "Do you want to change the cost of a product" << endl;
			cin >> choice;
		}

		Inventory* ptr = l1->getHead();

		while (ptr != nullptr)
		{
			cout << ptr->getItemNum() << " " << ptr->getProductNum() << " " << ptr->getQuantity() << " " << ptr->getCost() << endl;
			ptr = ptr->next;
		}

	}
}

void customer(LinkedList* l1)
{
	//variables to store the information of the user
	string firstName, lastName, address, city, state, stringZip; 
	int zip;

	cout << "Enter your first name" << endl;
	cin >> firstName; 

	cout << "Enter your last name" << endl; 
	cin >> lastName; 

	cout << "Enter your address" << endl;
	cin.ignore(); 
	getline(cin, address);

	cout << "Enter your city name" << endl;
	getline(cin, city);

	cout << "Enter your state name" << endl;
	getline(cin, state);

	cout << "Enter your zipcode" << endl;
	getline(cin, stringZip); 


	Customer customerObj("tzdhgfn", "aszfhxfh", "dfhxjf", "fggdh", "fgfa", 1232);  

	//variable to store the serial number entered by the user
	int snumber = -1;

	//keeps track of the number of products entered by the user
	int i = 0;

	//stores the quantity of each product needed by the user
	int quantity = 0;

	//to determine whether the serial number was found in the array
	bool found = false;
	while (snumber != 0 && i < 5 )
	{
		string s;

		cout << "Enter serial number of the product you want" << endl;
		cin >> s;

		//if user enters cart, it displays the current orders 
		//if (s == "cart")
			//output(Shoppinghead, i, dataFile, s);

		//else
		{
			stringstream input(s);

			int snumber = -1;

			input >> snumber;

			//program ends when customer enters 0
			if (snumber == 0)
				break;

			//searching for the serial number in the array
			for (int j = 0; j < l1->getLength(); j++)
			{
				Inventory* nodePtr = l1->getHead();
				
				bool flag = false;

				while (nodePtr)
				{
					if (nodePtr->getItemNum() == snumber)
					{
						flag = true;
						break;
					}
					nodePtr = nodePtr->next;
				}

				if (flag)
				{
					cout << nodePtr->getCost() << "    " << nodePtr->getQuantity() << endl;
					found = true;

					while (quantity >= 0)
					{
						cout << "Enter quantity of product. Input -1 to exit" << endl;
						cin >> quantity;

						if (quantity > nodePtr->getQuantity())
						{
							cout << "Sorry! We do not have enough of the product. Please reenter quantity" << endl;
							continue;
						}

						if (nodePtr->getQuantity() == 0)
						{
							cout << "Sorry! We are currently out of stock" << endl;
							break;
						}

						if (quantity < 0)
						{
							cout << "Invalid input. Please reenter quantity" << endl;
							continue;
						}

						else
						{
							int newQuantity = nodePtr->getQuantity() - quantity;
							nodePtr->setQuantity(nodePtr, newQuantity); 
							i++;
							//This checks whether a duplicate item was selected (ie an item that was already present in the shopping cart)
							//if (!duplicate(Shoppinghead, quantity, snumber))
							{
								//customerObj.add(nodePtr->getItemNum(), nodePtr->getCost(), quantity); 
								break;
							}
						}
					}
				}
				break;
			}

		
		}

		//customerObj.print(); 


		//if the serial number was not found in the array
		if (found == false)
			cout << "Product not found" << endl;
	}
}
