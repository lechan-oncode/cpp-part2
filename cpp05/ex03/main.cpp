#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try {
        Bureaucrat boss("Boss", 1);       // Highest grade
        Bureaucrat intern("Intern", 150); // Lowest grade

        ShrubberyCreationForm shrub("Home");
        RobotomyRequestForm robo("Bender");
        PresidentialPardonForm pardon("Marvin");

        std::cout << "\n--- Attempting to sign forms ---\n";

        // Intern tries to sign all forms (should fail)
        try { intern.signForm(shrub); } catch (std::exception &e) { std::cerr << e.what() << std::endl; }
        try { intern.signForm(robo); } catch (std::exception &e) { std::cerr << e.what() << std::endl; }
        try { intern.signForm(pardon); } catch (std::exception &e) { std::cerr << e.what() << std::endl; }

        // Boss signs all forms (should succeed)
        boss.signForm(shrub);
        boss.signForm(robo);
        boss.signForm(pardon);

        std::cout << "\n--- Attempting to execute forms ---\n";

        // Intern tries to execute all forms (should fail)
        try { intern.executeForm(shrub); } catch (std::exception &e) { std::cerr << e.what() << std::endl; }
        try { intern.executeForm(robo); } catch (std::exception &e) { std::cerr << e.what() << std::endl; }
        try { intern.executeForm(pardon); } catch (std::exception &e) { std::cerr << e.what() << std::endl; }

        // Boss executes all forms (should succeed)
        boss.executeForm(shrub);
        boss.executeForm(robo);
        boss.executeForm(pardon);

    } catch (std::exception &e) {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }

    return 0;
}
