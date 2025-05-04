# Source files
SRC	=	lib/mem/my_free.c\
		lib/mem/my_exit.c\
		lib/mem/my_malloc.c\
		lib/mem/my_memory.c\
		lib/mem/my_calloc.c\
		lib/mem/my_realloc.c\

OBJ	=	$(SRC:.c=.o)
N_FILES	:=	$(words $(SRC))
CURRENT_FILE	:=	0
NAME	=	libmem.a

# Compilation flags
CFLAGS	=	-Wall -Wextra -W -g
MAKEFLAGS	=	-j$(shell nproc) --silent --no-print-directory

# Colors
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
PURPLE=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m
RESET=\033[0m

# Main rule
all:	$(NAME)

# Compilation of the library binary
$(NAME):
	@echo -ne "[$(YELLOW)$(NAME)$(RESET)] "
	@echo -ne "Compiling all objects files...\n"
	@echo ""
	@make $(OBJ)
	@echo -ne "\n"
	@echo ""
	@echo -ne "--------------------------------------------\n"
	@echo ""
	@echo -ne "[$(YELLOW)$(NAME)$(RESET)] "
	@echo -ne "Compiling the library binary...\n"
	@ar rc $(NAME) $(OBJ)
	@echo ""
	@echo -ne "[$(YELLOW)$(NAME)$(RESET)] "
	@echo -ne "Library binary successfully compiled !\n"

# Rule to compile objects files of the library
$(OBJ): %.o: %.c
	@echo -ne "[$(BLUE)COMPILATION$(RESET)] "
	@echo -ne "($(shell expr $(CURRENT_FILE) + 1)/$(N_FILES)) $@\r"
	@gcc -c $< -o $@
	@$(eval CURRENT_FILE := $(shell expr $(CURRENT_FILE) + 1))

# Rule to remove all object files
clean:
	@echo -ne "[$(RED)REMOVE$(RESET)] "
	@echo -ne "Removing all object files...\n"
	@rm -f $(OBJ)
	@echo -ne "[$(RED)REMOVE$(RESET)] "
	@echo -ne "All objects files successfully removed !\n"

# Rule to remove all binary files
fclean:
	@make clean
	@echo -ne "[$(RED)REMOVE$(RESET)] "
	@echo -ne "Removing main library binary...\n"
	@rm -f $(NAME)
	@echo -ne "[$(RED)REMOVE$(RESET)] "
	@echo -ne "Main library binary successfully removed !\n"
	@echo ""
	@echo -ne "[$(RED)REMOVE$(RESET)] "
	@echo -ne "Repository successfully cleaned !\n"

# Rule to fully recompile the prgram
re:
	@make fclean
	@echo ""
	@echo -ne "--------------------------------------------\n"
	@echo ""
	@echo -ne "[$(YELLOW)$(NAME)$(RESET)] "
	@echo -ne "Recompiling the library\n"
	@echo ""
	@echo -ne "--------------------------------------------\n"
	@echo ""
	@make
