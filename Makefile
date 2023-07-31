NAME	=	so_long

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf

LIBDIR = ./libft
LIB = $(LIBDIR)/libft.a

MINILIBXDIR = ./minilibx-linux

INCLUDES = ./includes/
INCLUDES_LIB = ./libft/

HEADER += $(INCLUDES)so_long.h
HEADER += $(INCLUDES)get_next_line.h

vpath %.c src/

SRCS += main.c verifications.c

OBJ_DIR = ./obj/

OBJS = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))

all: $(LIB) $(NAME)

$(OBJS): $(OBJ_DIR)%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -I $(INCLUDES) -I $(INCLUDES_LIB) -o $@ -fPIE

$(NAME): $(OBJ_DIR) $(OBJS)
	@echo $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I$(INCLUDES) -I$(INCLUDES_LIB) $(LIB_TERMCAP) $(LIB) $(MINILIBXDIR)/libmlx_Linux.a $(MINILIBXDIR)/libmlx.a -lXext -lX11 -lm -lz -o $(NAME) -fPIE

$(OBJ_DIR):
	mkdir $@

$(LIB):
	$(MAKE) -C $(LIBDIR)
	$(MAKE) -C $(MINILIBXDIR)
	cp $(LIBDIR)/*.a .
	cp $(MINILIBXDIR)/*.a .

fclean : clean
	$(MAKE) fclean -C $(LIBDIR)
	$(RM) $(NAME)
	$(RM) -R $(OBJ_DIR)
	$(MAKE) clean -C $(MINILIBXDIR)
	$(RM) *.a

clean :
	$(MAKE) fclean -C $(LIBDIR)
	$(MAKE) clean -C $(MINILIBXDIR)
	$(RM) $(NAME)*

re : fclean
	$(MAKE)

.PHONY: all clean fclean re