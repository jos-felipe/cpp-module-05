# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 11:35:20 by josfelip          #+#    #+#              #
#    Updated: 2025/02/06 12:28:58 by josfelip         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name and compilation flags
NAME        = bureaucrat.out
CC          = c++
CFLAGS      = -Wall -Wextra -Werror -std=c++98

# Valgrind configuration
VALGRIND    = valgrind
VFLAGS      = --leak-check=full \
              --show-leak-kinds=all \
              --track-origins=yes \
              --quiet \
              --tool=memcheck \
              --trace-children=yes \
              --track-fds=yes

# Source files
SRCS        = main.cpp \
              Bureaucrat.cpp \
              AForm.cpp \
              ShrubberyCreationForm.cpp \
              RobotomyRequestForm.cpp \
              PresidentialPardonForm.cpp \
              Intern.cpp

# Object files (automatically generated from source files)
OBJS        = $(SRCS:.cpp=.o)

# Default target
all:        $(NAME)

# Linking the program
$(NAME):    $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Compiling source files into object files
%.o:        %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Memory leak check with valgrind
leaks:      $(NAME)
	@echo "\033[0;34m>>> Running valgrind memory leak check <<<\033[0m"
	@$(VALGRIND) $(VFLAGS) ./$(NAME)
	@echo "\033[0;34m>>> Memory leak check complete <<<\033[0m"

# Cleaning up object files
clean:
	rm -f $(OBJS)

# Full cleanup (objects and executable)
fclean:     clean
	rm -f $(NAME)
	rm -f *_shrubbery

# Rebuild everything
re:         fclean all

# Declare phony targets (targets that don't create files)
.PHONY:     all clean fclean re leaks
