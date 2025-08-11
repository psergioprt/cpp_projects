#include "Form.hpp"

Form()

Form(const std::string name, int signGrade, int execGrade);

Form(const Form& other);

Form& operator=(const Form& other);

~Form();

const std::string& getName() const;

bool getIsSigned() const;

int getSignInGrade() const;

int getExecuteGrade() const;

class GradeTooHighException : public std::exception
{
	public:
		const char * what() const noexcept override;
};
class GradeTooLowException : public std::exception
{
	public:
		const char * what() const noexcept override;
};

void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& out, const Form& form);
