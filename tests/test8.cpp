#include <iostream>
using namespace std;

class	employees
{
	public:
		string	name;
		void	define_salary(double ammount)
		{
			salary = ammount;
		}
		void	print(void)
		{
			cout << name << " has a salary of " << salary << " with bonus it is " << salary + calculate_bonus() <<endl;
		}
	private:
		double	salary;
		double	calculate_bonus(void)
		{
			return (salary * 0.10);
		}
};

int	main(void)
{
	employees employee1;

	employee1.name = "Kevin";
	employee1.define_salary(2000);
	employee1.print();
	return (0);
}
