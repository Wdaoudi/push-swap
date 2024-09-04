SRCS =	check.c \
		parsing.c \
		utils.c \
# mettre les differents noms de fichier de type ft_*\

NAME = push_swap
#nom executable

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
#transfo en .o executable , code machine economie du temps de transfo .c -> .o
OBJECTS_PREFIXED = $(addprefix  $(OBJS_DIR), $(OBJS))

CC = cc
CC_FLAGS = -Wall -Werror -Wextra -I./libft -I./printf
#ajout des chemin de compilation pour trouver les .h
# -I indique ou chercher les entete
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_DIR = printf
PRINTF = $(PRINTF_DIR)/printf.a

$(OBJS_DIR)%.o : %.c
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling : $<"
	@$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED) $(LIBFT) $(PRINTF)
	@$(CC) $(CC_FLAGS) $(OBJECTS_PREFIXED) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo "Push_swap Done!"

#ar r cree une bibliotheque statique .a et ajoute r
$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)

$(PRINTF):
	@$(MAKE) -sC $(PRINTF_DIR)

all: $(NAME)

clean:
		rm -rf $(OBJS_DIR)
		make clean -sC $(LIBFT_DIR)
		make clean -sC $(PRINTF_DIR)

fclean : clean
		rm -f $(NAME)
		rm -f $(LIBFT)
		rm -f $(PRINTF)

re: fclean all