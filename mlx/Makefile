NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2 -Wno-deprecated

CFLAGS+= -DSTRINGPUTX11
all: start $(NOM)

start:
		@${START}

end:	
		@${END}

%.o: %.c
		@cc ${CFLAGS} -c $< -o $@
		@${OK}

%.o: %.m
		@cc ${CFLAGS} -c $< -o $@
		@${OK}

$(NOM):	$(OBJ)
	@ar -r $(NOM) $(OBJ)
	@ranlib $(NOM)
	@$(END)

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all
