#include <iostream>
using namespace std;

struct houseType
{
	string style;
	int numOfBedrooms;
	int numOfBathrooms;
	int numOfCarsGarage;
	int yearBuilt;
	int finishedSquareFootage;
	double price;
	double tax;
}newHouse;

struct studentRecord
{
	string style;
	int numOfBedrooms;
	int numOfBathrooms;
	int numOfCarsGarage;
	int yearBuilt;
	int finishedSquareFootage;
	double price;
	double tax;
}student;


int main()
{

	student.style = "abc";
	newHouse.style = "black";
	cout << newHouse.style;
	
	
	/*
//	declaration of variables
	string fullName;
	int age;
	float marks;

	cout <<  "Enter Full Name: ";
	cin >> fullName;
	
	cout <<  "Enter Age: ";
	cin >>  age;
	
	cout <<  "Enter Marks: ";
	cin >> marks;

//output
	cout <<  "User Full Name: " 	<< fullName << endl;
	cout <<  "User Age: " 			<< age 		<< endl;
	cout <<  "User Marks: " 		<< marks	<< endl;
	
*/

	return 0;
}
