# include "AForm.hpp"
# include "Bureaucrat.hpp"

AForm::AForm(): _name("default"), _signed(false), _sign_grade(150), _exec_grade(150)
{
    std::cout << "Default constructor: AForm is created" << std::endl;
};

AForm::AForm(const std::string name, const int sign_grade, const int exec_grade):
_name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    if (sign_grade > 150)
        throw GradeTooLowException();
    else if (sign_grade < 0)
        throw GradeTooHighException();

    if (exec_grade > 150)
        throw GradeTooLowException();
    else if (exec_grade < 0)
        throw GradeTooHighException();
    std::cout << "Parameterized constructor: AForm is created" << std::endl;
};

AForm::AForm(const AForm &other):
_name(other._name), _signed(other._signed), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade)
{
    std::cout << "Copy constructor: AForm is copied" << std::endl;
};

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        _signed = other._signed; // Only assign the non-const field
        std::cout << "Assignment operator: AForm is assigned" << std::endl;
    }
    return *this;
}

AForm::~AForm()
{
    std::cout << "Denstructor: AForm is destroyed" << std::endl;
};

std::string AForm::getName() const
{
    return (_name);
};

bool        AForm::getSigned() const
{
    return (_signed);
};

int         AForm::getSignGrade() const
{
    return (_sign_grade);
};

int         AForm::getExecGrade() const
{
    return (_exec_grade);
};

void AForm::beSigned(const Bureaucrat &other)
{
    if (other.getGrade() > _sign_grade)
        throw GradeTooLowException();
    _signed = true;
};

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat's grade is too high!");
};

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat's grade is too low!");
};

void AForm::execute(Bureaucrat const &executor) const
{
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > _exec_grade)
        throw GradeTooLowException();
    execution();
};

const char *AForm::FormNotSignedException::what() const throw()
{
    return ("Form not singed!");
};

std::ostream &operator<<(std::ostream &os, const AForm &other)
{
    os << "This is Form " << other.getName() << std::endl
    << "sign status [ " << other.getSigned() << " ]" << std::endl 
    << "sign grade [ " << other.getSignGrade() << " ]" << std::endl 
    << "exec grade [ " << other.getExecGrade() << " ]" << std::endl;
    return os;
};
