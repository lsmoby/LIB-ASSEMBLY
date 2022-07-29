# ********************************** NAME *************************************
NAME = libasm.a
# *****************************************************************************

# ********************************** SRCS *************************************
SRCS_DIR = ./
SRCS = 	ft_strlen.s	ft_strcpy.s	ft_strcmp.s ft_read.s ft_write.s ft_strdup.s

# *****************************************************************************

# ********************************** OBJS *************************************
OBJS_DIR 	= 	objs/
OBJ 		= 	$(SRCS:.s=.o)
OBJS 		= 	$(addprefix $(OBJS_DIR), $(OBJ))
# *****************************************************************************

# ****************************** SUBJECT RELATED ******************************

$(OBJS_DIR)%.o	:	$(SRCS_DIR)%.s
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling : $<"
	@nasm -fmacho64 $< -o $@

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

all: $(NAME)

clean:
	@echo "Cleaning: $(OBJS_DIR)"
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "Cleaning: $(NAME)"
	@rm -f $(NAME)

re: fclean all
