#include <iostream>
using namespace std;

struct nameType
{
	string first;
	string middle;
	string last;
};

struct addressType
{
	string address1;
	string address2;
	string city;
	string state;
	string zip;
};

struct dateType
{
	int month;
	int day;
	int year;
};

struct contactType
{
	string phone;
	string cellphone;
	string fax;
	string pager;
	string email;
};


struct employeeType
{
	nameType name;
	string empID;
	addressType address;
	dateType hireDate;
	dateType quitDate;
	contactType contact;
	string deptID;
	double salary;
};


int main()
{
	
	employeeType emp1;
	
	cout 	<< "Enter 1st Employee -> First Middle & Last Name: "		;
	cin 	>> emp1.name.first >> emp1.name.middle >> emp1.name.last;

	cout 	<< "Full Name: " << emp1.name.first	<< " " 
	<< emp1.name.middle << " " << emp1.name.last;

	return 0;
}
