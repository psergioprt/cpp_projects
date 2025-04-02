#include <iostream>
using namespace std;

class employees
{
	public:
		string	name;
		void	add_salary(double value)
		{
			salary = value;
		}

		void 	print(void)
		{
			cout << name << " has a salary of " << salary << " Euros + " << bonus() << " Euros = " << salary + bonus() << "Euros" << endl;
		}
	private:
		double salary;
		double	bonus(void)
		{
			return (salary * 0.10);			
		}

};

int main()
{
	employees employee1;
	employee1.name = "John";
	employee1.add_salary(2000);
	employee1.print();
	return (0);
}
