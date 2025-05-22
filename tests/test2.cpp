#include <iostream>
using namespace std;

int main(void)
{
	string name;
	cout << "Please enter your name: ";
	//cin >> name; //only reads untill the first space character
	getline(cin, name); //reads all the string
	cout << "Your name is " << name << endl;
	return (0);
}
