#include <iostream>
using namespace std;

int main(void)
{
	int	i = 1;
	while (i < 6)
	{
		cout << i << endl;
		if (i == 2)
		{
			i = i + 2;
			continue ;
		}

		i++;
	}

	int	value = 0, sum = 0;
	while (value != -1)
	{
		sum = sum + value;
		cin >> value;
	}
	cout << sum;
	return (0);
}
