NAME	=	minishell
CFLAGS	=	-Wall -Wextra -Werror
FSAN	=	-g3 -fsanitize=address
OBJS	=	minishell.o \
			ft_exec_cmd.o \
			ft_read_ops.o \
			ft_exit.o \
			utils_basic.o \
			ft_get_env.o \
			ft_print_sort.o	\
			ft_buf_to_list.o \
			ft_arrow.o \
			ft_execve.o \
			ft_redir.o \
			ft_split.o \
			utils_basic2.o \
			ft_env_line.o \
			utils_read_ops.o \
			utils_t_char.o \
			ft_check_quotes.o \
			ft_pipes.o \
			ft_check_exportline.o \
			utils_exportline.o \
			utils_quotes.o \
			utils_random.o \
			utils_flagredir.o
			
all		:	$(NAME)

$(NAME)	:	$(OBJS)
	gcc $(CFLAGS) $^ -lncurses -o $@

%.o		:	%.c
	gcc -c $(CFLAGS) $^ 

clean	:
	rm -rf $(OBJS)

fclean	:	clean
	rm -rf $(NAME)

re		:	fclean all

PHONY	:	all clean fclean re
