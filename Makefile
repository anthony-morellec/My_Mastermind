CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
TARGET  = my_mastermind
OBJECTS = My_Mastermind.c

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

clean:
	rm -f $(TARGET) $(OBJECTS)