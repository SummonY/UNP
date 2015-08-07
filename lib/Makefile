CC	:= gcc
CFLAGS  := -O2 -Wall -lpthread -fomit-frame-pointer
LIB_A	:= libunp.a

SOURCES = $(wildcard *.c, *.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))

all : ${OBJECTS}

%.o : %.c
	$(CC) -c $^ -o $@ $(CFLAGS)


.PHONY: lib, clean
lib: *.o
	ar rv $(LIB_A) $^
	
clean:
	rm -f *.o *.a
