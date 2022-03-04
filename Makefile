LIBFT_DIR	= ./libft

LIBFT		= libft.a

NAME		= push_swap

BNAME		= checker

SRC			= ft_push_swap.c ft_parse_num.c push_swap.c ft_stack_fun.c ft_rules.c ft_sort_3_5.c ft_parse_one_arg.c ft_sort.c ft_sort_pt2.c ft_full_b.c ft_sort_pt3.c

BSRC		= get_next_line.c get_next_line_utils.c checker.c checker_pt2.c checker_pt3.c ft_push_swap.c ft_parse_num.c ft_stack_fun.c ft_rules.c ft_sort_3_5.c ft_parse_one_arg.c ft_sort.c ft_sort_pt2.c ft_full_b.c ft_sort_pt3.c

OBJ			= $(SRC:.c=.o)

BOBJ		= $(BSRC:.c=.o)

FLAGS		= -g -Wall -Wextra -Werror

RM			= rm -f

%.o:		%.c push_swap.h
			gcc $(FLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

bonus:		$(BNAME)

$(NAME):	$(OBJ)
			$(MAKE) bonus -C $(LIBFT_DIR)
			cp $(LIBFT_DIR)/$(LIBFT) $(LIBFT)
			gcc $(FLAGS) -include push_swap.h -o $(NAME) $(OBJ) $(LIBFT)

$(BNAME):	$(BOBJ)
			$(MAKE) bonus -C $(LIBFT_DIR)
			cp $(LIBFT_DIR)/$(LIBFT) $(LIBFT)
			gcc $(FLAGS) -include push_swap.h -o $(BNAME) $(BOBJ) $(LIBFT)

clean:
			$(MAKE) clean -C $(LIBFT_DIR)
			$(RM) $(OBJ) $(BOBJ)

fclean:		clean
			$(MAKE) fclean -C $(LIBFT_DIR)
			$(RM) $(NAME) $(BNAME)

re:			fclean all

.PHONY:		all clean fclean re