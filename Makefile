NAME = libft.a

SRCS = ft_atoi.c \
	   ft_bzero.c \
	   ft_calloc.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_strchr.c \
	   ft_strdup.c \
	   ft_strlcat.c \
	   ft_strlcpy.c \
	   ft_strlen.c \
	   ft_strncmp.c \
	   ft_strrchr.c \
	   ft_strstr.c \
	   ft_substr.c \
	   ft_tolower.c \
	   ft_toupper.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_split.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c

BONUS_SRCS = ft_lstnew_bonus.c

# Concaténation des fichiers source de base et supplémentaires
ALL_SRCS = $(SRCS) $(BONUS_SRCS)

OBJS = $(SRCS:.c=.o)

ALL_OBJS = $(ALL_SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME) clean

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: all $(ALL_OBJS) clean_bonus

clean:
	rm -f $(OBJS)

clean_bonus:
	rm -f $(ALL_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean clean_bonus fclean re
