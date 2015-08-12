CC		:= gcc
CFLAGS		:= -O2 -Wall -lpthread -fomit-frame-pointer
INCLUDE_H 	:= -I../lib/
LIBA		:= -L../lib/ -lunp


PROGS = daytimetcpcli daytimetcpcliv6 daytimetcpsrv byteorder

all: ${PROGS}


daytimetcpcli : daytimetcpcli.c
	$(CC) $^ -o $@ $(CFLAGS) $(INCLUDE_H) $(LIBA) 

daytimetcpcliv6 : daytimetcpcliv6.c
	$(CC) $^ -o $@ $(CFLAGS) $(INCLUDE_H) $(LIBA)

daytimetcpsrv : daytimetcpsrv.c
	$(CC) $^ -o $@ $(CFLAGS) $(INCLUDE_H) $(LIBA)

byteorder : byteorder.c
	$(CC) $^ -o $@ $(CFLAGS) $(INCLUDE_H) $(LIBA)

.PHONY: clean

clean:
	rm -f ${PROGS} *.o	
