#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _sign_grade;
        const int           _exec_grade;
    public:
        Form();
        Form(const std::string name, const int sign_grade, const int exec_grade);
        Form(const Form &other);
        Form &operator=(const Form &other);
        virtual ~Form();

        std::string getName() const;
        bool        getSigned() const;
        int         getSignGrade() const;
        int         getExecGrade() const;

        void beSigned(const Bureaucrat &other);

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
};

std::ostream &operator<<(std::ostream &os, const Form &other);

#endif