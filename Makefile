CC      = gcc
TARGET  = my_mastermind
OBJECTS = My_Mastermind.c

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

clean:
	rm -f $(TARGET) $(OBJECTS)