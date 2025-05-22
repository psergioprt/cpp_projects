#include <iostream>
using namespace std;

class	employees
{
	public:
		string	name;
		void	print(void)
		{
			cout << name << " has a salary of " << salary << endl;
		}
		void	define_salary(double ammount)
		{
			salary = ammount;
		}
	private:
		double	salary;
};

int	main(void)
{
	employees employee1;
	employee1.name = "John";
	employee1.define_salary(2000);
	employee1.print();
	return (0);
}
