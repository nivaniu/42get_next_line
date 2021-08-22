CC        := gcc
CFLAGS    := -Wall -Wextra -Werror

NAME      := test

SRC       := get_next_line.c \
             get_next_line_utils.c

SIZE      = 42

TARGET    := ../get_next_l*.c


all: out
	@cp $(TARGET) test.c test.sh ./out
	@cd ./out && $(CC) $(CFLAGS) $(SRC) test.c -o $(NAME) -D BUFFER_SIZE=$(SIZE)
	@chmod +x ./out/test.sh && ./out/test.sh

out:
	@mkdir -p ./out

clean:
	@rm -f ./out/$(NAME)

fclean: clean
	@rm -rf ./out

re: fclean all

.PHONY: all out clean fclean re
