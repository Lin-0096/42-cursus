NAME := libftprintf.a

SRCS := ft_printf.c write_char.c write_str.c \
		write_int.c write_uint_base.c write_pointer.c \

OBJECTS := $(SRCS:%.c=%.o)

CFLAGS := -Wall -Wextra -Werror

RM := rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	@ cc $(CFLAGS) -c $^ -o $@

test: test.c $(NAME)
	cc $(CFLAGS) $^ -o $@
	./$@
	
clean:
	@$(RM) $(OBJECTS) test

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re