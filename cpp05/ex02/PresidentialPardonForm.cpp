# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("deafault")
{
    std::cout << "Default constructor: PresidentailPardonForm is created" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "Parameterized constructor: PresidentailPardonForm is created" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other), _target(other._target)
{
    std::cout << "Copy constructor: PresidentailPardonForm is copied" << std::endl;
};

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    std::cout << "Assignment operator: PresidentailPardonForm is assigned" << std::endl;
    return (*this);
};

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Destructor: PresidentailPardonForm is destroyed" << std::endl;
};

void PresidentialPardonForm::execution() const
{
    std::cout << _target << " has been pardoned by Zaphod Beebrox" << std::endl;
}
