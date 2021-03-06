CC				 = gcc
NAME 				 = fdf

CFLAGS			 	 = -Wall -Werror -Wextra
IFLAGS				 = $(INCLUDES_LIBS) $(INCLUDES_SRCS)

INCLUDES_SRCS	 		 = -I includes
INCLUDES_LIBS			 = $(addprefix -I , $(LIBS_LST))

SRCS_DIR			 = srcs
SRCS				+= $(SRCS_DIR)/lines.c
SRCS				+= $(SRCS_DIR)/commands.c
SRCS				+= $(SRCS_DIR)/hooks.c
SRCS				+= $(SRCS_DIR)/init.c
SRCS				+= $(SRCS_DIR)/main.c
SRCS				+= $(SRCS_DIR)/map.c
SRCS				+= $(SRCS_DIR)/parse.c
SRCS				+= $(SRCS_DIR)/process.c
SRCS				+= $(SRCS_DIR)/pixels.c
SRCS				+= $(SRCS_DIR)/planes.c
SRCS				+= $(SRCS_DIR)/program.c
SRCS				+= $(SRCS_DIR)/vectors.c

OBJS_DIR			 = objs
OBJS				 = $(patsubst $(SRCS_DIR)/%, $(OBJS_DIR)/%, $(SRCS:.c=.o))

LIBS_DIR			 = libs
LIBS				+= libft
LIBS_LST			 = $(addprefix $(LIBS_DIR)/, $(LIBS))
LIBS_AR				 = $(addprefix $(LIBS_DIR)/, $(LIBS)/$(LIBS).a)
LIBS_SPEC			 = -L libs/libmlx -lmlx -framework OpenGL -framework AppKit

COLUMNS 			?= $(shell tput cols)
NUMBER				 = $(words $(SRCS))

PRINT_INLINE	 		 = @printf
PRINT	 			 = @echo

COLOR_DEFAULT	 		 = \033[0m
COLOR_BG		 	 = \033[42m
COLOR_GREEN		 	 = \033[32m
COLOR_RED		 	 = \033[31m

PROGRESS_CHAR	 		 = "$(COLOR_BG)$(shell python -c "print '\x20' * ($(COLUMNS) / $(NUMBER) + 1)")$(COLOR_DEFAULT)"

DONE_FILES		 	 = $(SRCS)
DONE_FILES			:= "$(patsubst $(SRCS_DIR)/%, $(COLOR_GREEN)✓$(COLOR_DEFAULT) $(SRCS_DIR)/%\n,$(DONE_FILES))"
DONE_STRING		 	 = "$(COLOR_GREEN)✓$(COLOR_DEFAULT) Compilation $(COLOR_GREEN)success$(COLOR_DEFAULT)\n"

CLEAN_FILES		 	 = $(OBJS)
CLEAN_FILES			:= "$(patsubst $(OBJS_DIR)/%, $(COLOR_RED)❌$(COLOR_DEFAULT) $(OBJS_DIR)/%\n,$(CLEAN_FILES))"
CLEAN_STRING	 		 = "$(COLOR_GREEN)✓$(COLOR_DEFAULT) Cleaning $(COLOR_GREEN)success$(COLOR_DEFAULT)\n"

FCLEAN_FILES			:= "$(COLOR_RED)❌$(COLOR_DEFAULT) $(NAME)\n"
FCLEAN_STRING	 		 = "$(COLOR_GREEN)✓$(COLOR_DEFAULT) Deep cleaning $(COLOR_GREEN)success$(COLOR_DEFAULT)\n"

all: libs $(NAME)

clean:
	@rm -rf $(OBJS_DIR)
	$(PRINT)
	$(PRINT) $(CLEAN_STRING) $(CLEAN_FILES)

fclean: clean
	@rm -rf $(NAME)
	$(PRINT)
	$(PRINT) $(FCLEAN_STRING) $(FCLEAN_FILES)

re: clean fclean all

libs: $(LIBS_LST)
	@make -C $<
	$(PRINT) "\n"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ $(LIBS_AR) $(LIBS_SPEC) -o $@
	$(PRINT) "\n"
	$(PRINT) $(DONE_STRING) $(DONE_FILES)
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p objs
	$(PRINT_INLINE) $(PROGRESS_CHAR)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

.PHONY: all clean fclean re libs
