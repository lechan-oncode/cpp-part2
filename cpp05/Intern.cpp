# include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Default constructor : Intern is created" << std::endl;
};
Intern::(const Intern& other)
{
    std::cout << "Parameterized constructor : Intern is created" << std::endl;
};

Intern &Intern::operator=(const Intern& other)
{
        std::cout << "Copy constructor : Intern is copied" << std::endl;
};

Intern &Intern::operator=(const Intern& other)
{
    if (this != &other)
    {
        std::cout << "Assignment operator : Intern is assigned" << std::endl;
    }
    return *this;
};

Intern::~Intern()
{
    std::cout << "Destructor : Intern is destroyed" << std::endl;
};

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    int i = 0;
    std::string formNames[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
    while (i < 3)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            break ;
        }
        i++;
    }
    switch (i)
    {
        case 0:
            return new PresidentialPardonForm(target);
        case 1:
            return new RobotomyRequestForm(target);
        case 2:
            return new ShrubberyCreationForm(target);
        default:
            std::cout << "Intern cannot create " << formName << " because it is unknown form" << std::endl;
            return NULL;
    }
}
