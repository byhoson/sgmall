CC = gcc
CFLAGS = -W -Wall
TARGET = main
OBJECTS = admin/admin.o login/login.o customer/customer.o signup/signup.o product/product.o main.o

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm -f $(OBJECTS) $(TARGET)
