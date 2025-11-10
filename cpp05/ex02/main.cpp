#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat boss("Boss", 1);                // Highest grade
        Bureaucrat intern("Intern", 150);          // Lowest grade

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robo("Bender");
        PresidentialPardonForm pardon("Marvin");

        std::cout << "\n--- Trying to execute unsigned forms ---\n";
        try {
            boss.executeForm(shrub);
        } catch (std::exception &e) {
            std::cout << "❌ " << e.what() << "\n";
        }

        std::cout << "\n--- Signing forms ---\n";
        intern.signForm(shrub);   // should fail
        boss.signForm(shrub);     // should succeed
        boss.signForm(robo);
        boss.signForm(pardon);

        std::cout << "\n--- Executing forms ---\n";
        boss.executeForm(shrub);
        boss.executeForm(robo);
        boss.executeForm(pardon);

        std::cout << "\n--- Trying execution with low grade ---\n";
        intern.executeForm(shrub); // should fail
    }
    catch (std::exception &e) {
        std::cerr << "Fatal Error: " << e.what() << "\n";
    }

    return 0;
}
