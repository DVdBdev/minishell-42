# Name of the executable
NAME				= minishell

# Directories
LIBFT				= ./libft/libft.a 	# Path to the library
INC					= inc/				# Directory containing header files
SRC_DIR				= src/				# Directory containing source files
OBJ_DIR				= obj/				# Directory to store object files

# Compiler and flags
CC					= gcc				# Compiler command
CFLAGS 				= -Wall -Werror -Wextra -I $(INC)	# Compiler flags
LDFLAGS				= -lreadline		# Linker flags
RM					= rm -f				# Command to remove files

# Source Files
SRCS 				= 	$(SRC_DIR)init.c \
						$(SRC_DIR)main.c \

# Apply pattern substitution to generate list of object files in OBJ_DIR
OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules

# Target for starting the build process
start:				
					@make all

# Target to build the library
$(LIBFT):
					@make -C ./libft

# Target to build all
all: 				$(NAME)

# Target to build the executable
$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(OBJ) $(LIBFT) $(LDFLAGS) -o $(NAME)

# Target to compile source files into object files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) -c $< -o $@

# Target to clean object files
clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft

# Target to clean object files and executable
fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

# Target to clean everything and rebuild
re: 				fclean all

# Phony targets represent actions not files
.PHONY: 			start all clean fclean re