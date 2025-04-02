#include <iostream>
#include <string>
// #include <bits/stdc++.h>
using namespace std;

int main()
{
	string text = "My name is Luka";
	string name = "paulo";
	cout << text << endl;
	cout << "size: " << text.size() << endl;
	cout << "name[0]: " << name[0] << endl;
	cout << "name: " << name << endl;
	cout << "name.at(3): "<< name.at(3) << endl;
	name[3] = 'L';
	cout << "name: " << name << endl;
	name = name + " sergio";
	cout << "name: " << name << endl;
	name += " dos";
	name.append(" santos");
	cout << "name: " << name << endl;
	cout << "length: " << name.length() << endl;
	string fullname;
	string surname = " silva";
	fullname  = name + surname;
	cout << "fullname: " << fullname << endl;
	if (surname.empty())
		cout << "surname is empty\n";
	else
		cout << "surname is not empty\n";
	surname.clear();
	if (surname.empty())
		cout << "surname is empty\n";
	else
		cout << "surname is not empty\n";
	string test4 = to_string(-10);
	cout << test4 << endl;
	double 	number = stod(test4);
	int	number2 = 12;
	cout << number + number2 << endl;
	string test5 = fullname.substr(6, 6);
	cout << test5 << endl;
	return (0);
}
