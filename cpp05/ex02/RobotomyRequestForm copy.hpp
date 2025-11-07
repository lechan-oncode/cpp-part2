#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include "cstdlib"

class RobotomyRequestForm: public AForm
{
    private:
        std::string _target;
        void execution() const;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
        ~RobotomyRequestForm();

        class CreationFailedException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

#endif