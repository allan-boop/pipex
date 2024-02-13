#########################################
## ARGUMENTS
#########################################
NAME	=	pipex

INCLUDES_PATH=	includes
CC=				gcc
CFLAGS=			-Wall -Wextra -Werror

LIBS_DIR=	./libs

all: $(NAME)

########################################
## SOURCES
########################################
SRC_FILES = pipex.c \
			utils.c

SRC_FILES_BONUS = pipex_bonus.c \
				  utils.c


SRC_FILES_BONUS := $(addprefix src/, $(SRC_FILES_BONUS))
SRC_FILES := $(addprefix src/, $(SRC_FILES))
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_FILES_BONUS = $(SRC_FILES_BONUS:.c=.o)

########################################
## RULES
########################################

all: $(NAME)

DO_LIBS:
	@echo DOING LIBS
	@make -C $(LIBS_DIR) all

bonus: $(OBJ_FILES_BONUS) | DO_LIBS
	@echo LINKING
	$(CC) $^ -L$(LIBS_DIR) -lft $(CFLAGS) -o $(NAME)_bonus -lm

$(NAME): $(OBJ_FILES) | DO_LIBS
	@echo LINKING
	$(CC) $^ -L$(LIBS_DIR) -lft $(CFLAGS) -o $@ -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_FILES)
	@rm -f $(OBJ_FILES_BONUS)
	@make -C $(LIBS_DIR) clean

fclean: clean
	@make -C $(LIBS_DIR) fclean
	@rm -f $(NAME)_bonus
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re all
