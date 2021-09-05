CC = gcc
CFLAGS   = -g -c -Wall
LDFLAGS = -lws2_32
OBJFILES = main.o server.o windowsNetworking.o
TARGET = app

#builds the project
all: $(OBJFILES)
	$(CC) -g $(OBJFILES) -o $(TARGET) $(LDFLAGS)

#builds the object file from the c files
main.o: main.c
	$(CC) $(CFLAGS) main.c

server.o: server.c
	$(CC) $(CFLAGS) server.c

windowsNetworking.o: windowsNetworking.c
	$(CC) $(CFLAGS) windowsNetworking.c

#cleans the build directory
clean:
	del $(OBJFILES)