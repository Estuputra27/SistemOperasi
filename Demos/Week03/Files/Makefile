# REV17 Sun Feb 23 16:57:39 WIB 2020
# REV16 Mon Jan 28 19:03:30 WIB 2019
# REV14 Mon Dec 10 15:17:15 WIB 2018
# REV03 Thu Mar  9 21:18:27 WIB 2017
# START Tue Sep 13 11:44:18 WIB 2016

# INFO: With this "Makefile", just run:
# INFO:                     make

CC            = gcc
CPP           = cpp
CFLAGS        = -std=gnu99
LDFLAGS       = 
CPPFLAGS      =
DEPFLAGS      = -MM -MT $(@:.d=.o) 
OUTPUT_OPTION = -o $@
COMPILE       = $(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c
SRCS          = $(wildcard *.c)
OBJ           = $(SRCS:.c=.o)
DEP           = $(OBJ:.o=.d)
PROGS         = $(SRCS:.c=  )

P01=01-open-close
P02=02-file-pointer
P03=03-fprintf
P04=04-dprintf
P05=05-sprintf
P06=06-printf


EXECS= \
        $(P01) \
        $(P02) \
        $(P03) \
        $(P04) \
        $(P05) \
        $(P06) \


DEMOFILES=\
	demo-file1.txt \
	demo-file2.txt \
	demo-file3.txt \
	demo-file4.txt \


MODE644=\
	demo-file4.txt \

all:  $(EXECS) demo-file4.txt

$(EXECS): %: %.c $(DEPS)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

.phony: clean demo
clean:
	rm -f ${EXECS} 
	rm -f ${DEMOFILES}
	rm -f *.map
 
demo: demo-file4.txt
demo-file4.txt:
	@echo "Line 1: Blah Blah Blah 1" >  demo-file4.txt
	@echo "Line 2: Blah Blah Blah 2" >> demo-file4.txt
	@echo "Line 3: Blah Blah Blah 3" >> demo-file4.txt
	@chmod 644 $(MODE644)

