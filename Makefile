CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRC = 

OBJ = $(SRC:.c=.o)
OBJBONUS = $(SRCBONUS:.c=.o)
AR = ar rc

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(AR) -o $@ $^

clean : 
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus : $(OBJBONUS) $(OBJBONUS) 
	$(AR) -o $(NAME) $?