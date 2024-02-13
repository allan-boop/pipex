#########################################
## ARGUMENTS
#########################################

NAME=libs

#				LIBFT

LIBFT=libft.a
LIBFT_PATH=./libft

########################################
## RULES
########################################

all : $(NAME)

$(LIBFT):
	@echo DOING LIBFT.A
	@make -C $(LIBFT_PATH)
	@mv $(LIBFT_PATH)/$(LIBFT) .

$(NAME): $(LIBFT)

clean :
	@make -C $(LIBFT_PATH) clean

fclean : clean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(LIBFT)

re : fclean all

.PHONY: all clean fclean re
