NAME		=	Intern
SRCS		=	main Bureaucrat AForm PresidentialPardonForm ShrubberyCreationForm  RobotomyRequestForm Intern
SRC			=	${addsuffix .cpp, ${SRCS}}
OBJ			=	${SRC:.cpp=.o}

CC			=	c++
RM			=	rm -rf
FLAGS		=	-Wall -Wextra -Werror -std=c++98 -pedantic

all:		$(NAME)

${NAME}:	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:		
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re