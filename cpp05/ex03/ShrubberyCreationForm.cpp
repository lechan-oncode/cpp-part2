# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 25, 5), _target("default")
{
    std::cout << "Default constructor: ShrubberyCreationForm is created" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 25, 5), _target(target)
{
    std::cout << "Parameterized constructor: ShrubberyCreationForm is created" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other)
{
    _target = other._target;
    std::cout << "Copy constructor: ShrubberyCreationForm is copied" << std::endl;
};

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
};

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Destructor: ShrubberyCreationForm is destroyed" << std::endl;
};

const char *ShrubberyCreationForm::CreationFailedException::what() const throw()
{
    return ("Shrubbery Creation Form : failed to create");
};

void ShrubberyCreationForm::execution() const
{
    std::ofstream outFile((_target + "_shrubbery").c_str());
    if (outFile)
    {
        outFile << ((_target + "_shrubbery").c_str());
        outFile << "\n\n";
        outFile << "  **  " << std::endl;
        outFile << " **** " << std::endl;
        outFile << " **** " << std::endl;
        outFile << "******" << std::endl;
        outFile << "  **  " << std::endl;
        outFile << " **** " << std::endl;
        outFile.close();
    }
    else
        throw CreationFailedException();
};
