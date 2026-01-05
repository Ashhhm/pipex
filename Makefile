NAME = pipex

SRC = \
	utils/check.c \
	utils/error.c \
	utils/cmd.c \
	src/main.c

HDRS = header/pipex.h

OBJS = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
AR = ar rcs
FLAGS = -Wall -Wextra -Werror -I./header -I$(LIBFT_DIR)

all : $(NAME)

$(LIBFT) :
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c $(HDRS)
	$(CC) $(FLAGS) -c -g $< -o $@

clean :
	/bin/rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean : clean
	/bin/rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY : all clean fclean re