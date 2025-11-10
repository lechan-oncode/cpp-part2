#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150)
{
    std::cout << "Default constructor: Bureaucrat is created" << std::endl; 
};

Bureaucrat::Bureaucrat(std::string name, int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
    _name = name;
    std::cout << "Parameterized constructor: Bureaucrat is created" << std::endl; 
};

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade)
{
    std::cout << "Copy constructor: Bureaucrat is copied" << std::endl; 
};

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (&other != this)
    {
        _grade = other._grade;
        _name = other._name;
        std::cout << "Assigned operator: Bureaucrat is assigned" << std::endl; 
    }
    return (*this);
};

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor: Bureaucrat is destroyed" << std::endl; 
};

std::string Bureaucrat::getName() const
{
    return (_name);
};

int         Bureaucrat::getGrade () const
{
    return (_grade);
};

void        Bureaucrat::increaseGrade ()
{
    if (_grade - 1 <= 0)
        throw GradeTooHighException();
    _grade--;
};

void        Bureaucrat::decreaseGrade ()
{
    if (_grade + 1 >= 150)
        throw GradeTooLowException();
    _grade++;
};

void        Bureaucrat::signForm(AForm &form)
{
        try
        {
            form.beSigned(*this);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Bureaucrat " << _name << " couldn't sign " 
            << form.getName() << " because " << e.what() << '\n';
            return ;
        }
        std::cout << "Bureaucrat " << _name << " signed form " 
        << form.getName() << '\n';
};

void        Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "Bureaucrat [ " << _name << " ] executed form [ " << form.getName() << std::endl; 
};

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat's grade is too high!");
};

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat's grade is too low!");
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &other)
{
    os << other.getName() << " , bureaucrat grade " << other.getGrade() ;
    return os;
};
