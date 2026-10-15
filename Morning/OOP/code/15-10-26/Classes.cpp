#include <iostream>
using namespace std;

class personDetails
{
	public: 
		int age;
		string name;
};

int main()
{
	
//	object of the class
	personDetails person1;
	
	cout << "Enter your name & age: ";
	cin >> person1.name >> person1.age; 
	
	cout << "User name: " << person1.name << endl;
	cout << "User age: " << person1.age << endl;
}
