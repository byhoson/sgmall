CC = gcc
CFLAGS = -W -Wall
TARGET = main
OBJECTS = login/login.o main.o

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm -f $(OBJECTS) $(TARGET)