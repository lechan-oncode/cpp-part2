#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
        Bureaucrat boss("Alice", 1);
        Bureaucrat intern("Bob", 150);

        std::cout << "=== Initial Bureaucrats ===" << std::endl;
        std::cout << boss << std::endl;
        std::cout << intern << std::endl;

        std::cout << "\n=== Creating Forms ===" << std::endl;
        Form formA("Top Secret Form", 10, 5);
        Form formB("Intern Report", 150, 150);

        std::cout << formA << std::endl;
        std::cout << formB << std::endl;

        std::cout << "\n=== Signing Attempts ===" << std::endl;
        intern.signForm(formA);   // should fail (too low)
        boss.signForm(formA);     // should succeed

        std::cout << formA << std::endl;

        std::cout << "\n=== Invalid Form Creation ===" << std::endl;
        try
        {
            Form invalid("Impossible Form", 0, 151); // should throw
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }

    return 0;
}
