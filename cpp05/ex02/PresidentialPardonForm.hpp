#ifndef PRESIDENTUALPARDONFORM_HPP
#define PRESIDENTAILPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm
{
    private:
        std::string _target;
        void execution() const;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
        ~PresidentialPardonForm();
};

#endif