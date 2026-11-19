CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
TARGET  = my_mastermind
OBJECTS = My_Mastermind.c

all : $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean:
	rm -f $(TARGET)

re: fclean all
.PHONY: all clean fclean re