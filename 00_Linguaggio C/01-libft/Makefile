# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aviolini <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/13 16:48:27 by aviolini          #+#    #+#              #
#    Updated: 2021/01/20 09:50:02 by aviolini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libft.a

SRCS =			ft_atoi.c \
				ft_memccpy.c \
				ft_strlcat.c \
				ft_bzero.c \
				ft_memchr.c	\
				ft_strlcpy.c \
				ft_calloc.c	\
				ft_memcmp.c	\
				ft_strlen.c \
				ft_isalnum.c \
				ft_memcpy.c	\
				ft_strncmp.c \
				ft_isalpha.c \
				ft_memmove.c \
				ft_strnstr.c \
				ft_isascii.c \
				ft_memset.c	\
				ft_strrchr.c \
				ft_isdigit.c \
				ft_strchr.c	 \
				ft_tolower.c \
				ft_isprint.c \
				ft_strdup.c	\
				ft_toupper.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c

SRCS_BONUS	=	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \

OBJS		=	$(SRCS:.c=.o)

OBJS_BONUS 	=	$(SRCS_BONUS:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

.c.o		:
				$(CC) $(CFLAGS) -c $<

$(NAME)		:	$(OBJS)
				ar rc $(NAME) $(OBJS)

all			:	$(NAME)

bonus		:	$(OBJS) $(OBJS_BONUS)
				ar rc $(NAME) $(OBJS) $(OBJS_BONUS)

clean		:		
				$(RM) $(OBJS) $(OBJS_BONUS)
		
fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
