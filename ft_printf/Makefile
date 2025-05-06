NAME := libftprintf.a

SRCS := ft_printf.c \

OBJECTS := $(SRCS:%.c=%.o)

CFLAGS := -Wall -Wextra -Werror

RM := rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re