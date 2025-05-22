#include <iostream>
using namespace std;

class bankAccount
{
	public:
		string name;
		double balance;
		void withdraw(int ammount)
		{
			balance = balance - ammount;
		}
		void print(void)
		{
			cout << "account " << name << " has " << balance << " euros" << endl;
		}
};

int	main(void)
{
	bankAccount account1;
	account1.name = "Luka";
	account1.balance = 3000;
	account1.print();
	//cout << "The bank account of " << account1.name << " has " << account1.balance << " euros" << endl;
	
	bankAccount account2;
	account2.name = "Bruce";
	account2.balance = 5000;
	account2.print();
	//cout << "The bank account of " << account2.name << " has " << account2.balance << " euros" << endl;
	account2.withdraw(475);
	account2.print();
	//cout << "The bank account of " << account2.name << " has now " << account2.balance << " euros" << endl;
	return (0);
}
