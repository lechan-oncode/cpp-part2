#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Alice", 1);
        std::cout << a << std::endl;

        // This should throw GradeTooHighException
        std::cout << "Trying to increase grade of Alice..." << std::endl;
        a.increaseGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-------------------------" << std::endl;

    try
    {
        Bureaucrat b("Bob", 150);
        std::cout << b << std::endl;

        // This should throw GradeTooLowException
        std::cout << "Trying to decrease grade of Bob..." << std::endl;
        b.decreaseGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-------------------------" << std::endl;

    try
    {
        // This should throw in constructor (invalid grade)
        Bureaucrat c("Charlie", 151);
        std::cout << c << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught while creating Charlie: " << e.what() << std::endl;
    }

    return 0;
}
