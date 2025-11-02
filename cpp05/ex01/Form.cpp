# include "Form.hpp"
# include "Bureaucrat.hpp"

Form::Form(): _name("default"), _signed(false), _sign_grade(150), _exec_grade(150)
{
    std::cout << "Default constructor: Form is created" << std::endl;
};

Form::Form(const std::string name, const int sign_grade, const int exec_grade):
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
    std::cout << "Parameterized constructor: Form is created" << std::endl;
};

Form::Form(const Form &other):
_name(other._name), _signed(other._signed), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade)
{
    std::cout << "Copy constructor: Form is copied" << std::endl;
};

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        _signed = other._signed; // Only assign the non-const field
        std::cout << "Assignment operator: Form is assigned" << std::endl;
    }
    return *this;
}

Form::~Form()
{};

std::string Form::getName() const
{
    return (_name);
};

bool        Form::getSigned() const
{
    return (_signed);
};

int         Form::getSignGrade() const
{
    return (_sign_grade);
};

int         Form::getExecGrade() const
{
    return (_exec_grade);
};

void Form::beSigned(const Bureaucrat &other)
{
    if (other.getGrade() > _sign_grade)
        throw GradeTooLowException();
    _signed = true;
};

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat's grade is too high!");
};

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat's grade is too low!");
};

std::ostream &operator<<(std::ostream &os, const Form &other)
{
    os << "This is Form " << other.getName() << std::endl
    << "sign status [ " << other.getSigned() << " ]" << std::endl 
    << "sign grade [ " << other.getSignGrade() << " ]" << std::endl 
    << "exec grade [ " << other.getExecGrade() << " ]" << std::endl;
    return os;
};
