#include <iostream>
using namespace std;

int main(void)
{
	int	n1 = 0, n2 = 0;
	cout << "Please enter n1 and n2 values: ";
	if (cin >> n1 >> n2)
		cout << "You entered n1: " << n1 << " and n2: " << n2 << endl;
	else
	{
		cin.clear();
		cout << "You entered invalid values" << endl;
		return (1);
	}
	cin.ignore(1000, '\n');
	cout << "The product of " << n1 << " and " << n2 << " is " << n1 * n2 << endl;
	return (0);
}
