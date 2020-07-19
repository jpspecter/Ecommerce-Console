#include"Customer.h"

Customer::Customer() {
	firstName = " "; 
	lastName = " "; 
	address = " "; 
	city = " "; 
	state = " "; 
	zipCode = 0; 
}; 

Customer::Customer(string Cfirstname, string Clastname, string Caddress, string Ccity, string Cstate, int Czip) {
	firstName = Cfirstname;
	lastName = Clastname;
	address = Caddress;
	city = Ccity;
	state = Cstate;
	zipCode = Czip;
}