# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("deafault")
{
    std::cout << "Default constructor: RobotomyRequestForm is created" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "Parameterized constructor: RobotomyRequestForm is created" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
{
    std::cout << "Default constructor: RobotomyRequestForm is created" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm &operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    std::cout << "Assignment operator: RobotomyRequestForm is assigned" << std::endl;
};

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Destructor: RobotomyRequestForm is destroyed" << std::endl;
};

const char *RobotomyRequestForm::CreationFailedException() const throw()
{
    return ("Robomotmy request form : failed to create");
};

void RobotomyRequestForm::execution() const
{
    int n = rand() % 2;
    std::cout << "Drilling sounds" << std::endl;
    if (n == 0)
        std::cout << _target << " has been robotomized suscessfully" << std::endl;
    else 
        throw CreationFailedException();
};