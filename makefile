Name = minishell
CC = cc 
CFLAGS = -Wall -Wextra -Werror -lreadline
OBJ = main.o ./libft/ft_strlen.o ./libft/ft_strchr.o src/error_checker/error_checker.o

all : $(Name)

$(Name) : $(OBJ)
	$(CC) $(CFLAGS) $^  -o $(Name)


%.o : %.c libft/libft.h includes/error_checker.h includes/minishell
	$(CC) $(CFLAGS) -c $< -o $@


clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(Name)

re : fclean all 