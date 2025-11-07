#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _sign_grade;
        const int           _exec_grade;
        virtual void execution() = 0;
    public:
        AForm();
        AForm(const std::string name, const int sign_grade, const int exec_grade);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

        std::string getName() const;
        bool        getSigned() const;
        int         getSignGrade() const;
        int         getExecGrade() const;

        void beSigned(const Bureaucrat &other);

        void execute(Bureaucrat const &executor) const

        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class FormNotSignedException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        }
};

std::ostream &operator<<(std::ostream &os, const Form &other);

#endif