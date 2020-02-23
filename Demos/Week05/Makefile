# REV01 Sun Feb 23 18:32:26 WIB 2020
# START Mon Oct  3 09:21:51 WIB 2016

# INFO: With this "Makefile", just run:
# INFO:                     make

CC=gcc

EXECS= \
	06-memory


all:  $(EXECS)


06-memory: 06-memory.c
	$(CC) 06-memory.c -o 06-memory -Xlinker  \
		-Map=06-memory.map

clean:
	rm -f ${EXECS} 
	rm -f *.map
 
