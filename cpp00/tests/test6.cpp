#include <iostream>
using namespace std;

class employees
{
	public:
		string name;
		void	set_salary(double potential_salary)
		{
			salary = potential_salary;
		}
		double	get_salary(void)
		{
			return (salary);
		}
		void	print_bonus(void)
		{
			cout << name << " bonus: " << calculate_bonus() << endl;
		}
	private:

		double	salary;
		double calculate_bonus(void)
		{
			return (salary * 0.10);
		}
		
};

int	main()
{
	employees employee1;
	employee1.name = "James";
	employee1.set_salary(2000);
	cout << employee1.name << " has " << employee1.get_salary();
	employee1.print_bonus();
	return (0);
}
