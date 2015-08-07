CC		:= gcc
CFLAGS		:= -O2 -Wall -lpthread -fomit-frame-pointer
INCLUDE_H 	:= -I../lib/
LIBA		:= -L../lib/ -lunp


PROGS = daytimetcpcli

all: ${PROGS}


daytimetcpcli: daytimetcpcli.c
	$(CC) $^ -o $@ $(CFLAGS) $(INCLUDE_H) $(LIBA) 


clean:
	rm -f ${PROGS} *.o	
