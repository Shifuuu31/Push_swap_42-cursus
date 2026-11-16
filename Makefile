SRCS			=	src/main.c \
					src/parsing/parsing.c \
					src/parsing/validation.c \
					src/parsing/convert_utils.c \
					src/stack/stack_init.c \
					src/operations/operations_a.c \
					src/operations/operations_b.c \
					src/operations/operations_both.c \
					src/sorting/small_sort.c \
					src/sorting/large_sort.c \
					src/sorting/sort_utils.c \
					src/utils/string_utils.c \
					src/utils/split_utils.c

OBJS			= $(SRCS:.c=.o)
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.
NAME			= push_swap

all:			shifuuu $(NAME)
				@echo "\033[1m\033[32mCompilation has completed"

$(NAME):		$(OBJS) push_swap.h
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o:			%.c push_swap.h
				@$(CC) $(CFLAGS) -c $< -o $@

clean:
				@$(RM) $(OBJS) 
				@echo "\033[1m\033[31mObject files removed"

fclean:			
				@$(RM) $(OBJS)
				@$(RM) $(NAME)
				@echo "\033[1m\033[31mThe executable file and object files have been successfully removed"

re:				fclean all

shifuuu:
			-@clear 2>/dev/null || true
			@echo "	\033[37m░██████╗██╗░░██╗██╗███████╗██╗░░░██╗██╗░░░██╗██╗░░░██╗"
			@echo "	\033[37m██╔════╝██║░░██║██║██╔════╝██║░░░██║██║░░░██║██║░░░██║"
			@echo "	\033[37m╚█████╗░███████║██║█████╗░░██║░░░██║██║░░░██║██║░░░██║"
			@echo "	\033[37m░╚═══██╗██╔══██║██║██╔══╝░░██║░░░██║██║░░░██║██║░░░██║"
			@echo "	\033[37m██████╔╝██║░░██║██║██║░░░░░╚██████╔╝╚██████╔╝╚██████╔╝"
			@echo "	\033[37m╚═════╝░╚═╝░░╚═╝╚═╝╚═╝░░░░░░╚═════╝░░╚═════╝░░╚═════╝░"
			@echo "	\033[37m														 "
			@echo "	\033[37m███╗░░░███╗░█████╗░░██████╗████████╗███████╗██████╗░"
			@echo "	\033[37m████╗░████║██╔══██╗██╔════╝╚══██╔══╝██╔════╝██╔══██╗"
			@echo "	\033[37m██╔████╔██║███████║╚█████╗░░░░██║░░░█████╗░░██████╔╝"
			@echo "	\033[37m██║╚██╔╝██║██╔══██║░╚═══██╗░░░██║░░░██╔══╝░░██╔══██╗"
			@echo "	\033[37m██║░╚═╝░██║██║░░██║██████╔╝░░░██║░░░███████╗██║░░██║"
			@echo "	\033[37m╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═════╝░░░░╚═╝░░░╚══════╝╚═╝░░╚═╝"
			@echo "															 "
