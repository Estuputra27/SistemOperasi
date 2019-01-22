# REV05 Tue Jan 22 20:11:41 WIB 2019
# REV04 Wed Nov  1 13:30:30 WIB 2017
# START Mon Oct 24 09:18:34 WIB 2016
# DEMOFILES=\
# 	demo-file1.txt \
# 	demo-file2.txt \

CC=gcc
 
P00=00-show-pid
P01=01-fork
P02=02-fork
P03=03-fork
P04=04-sleep
P05a=05a-fork
P05b=05b-fork
P06a=06a-fork
P06b=06b-fork
P06c=06c-fork
P06d=06d-fork
P07=07-fork
P08=08-fork
P09=09-fork
P10=10-fork
P11=11-fork
P12=12-fork
P13=13-uas161
P14=14-uas162
P15=15-uas171
P16=16-uas172


EXECS= \
	$(P00)  \
	$(P01)  \
	$(P02)  \
	$(P03)  \
	$(P04)  \
	$(P05a) \
	$(P05b) \
	$(P06a) \
	$(P06b) \
	$(P06c) \
	$(P06d) \
	$(P07)  \
	$(P08)  \
	$(P09)  \
	$(P10)  \
	$(P11)  \
	$(P12)  \
	$(P14)  \
	$(P15)  \
	$(P16)  \


all:	$(EXECS)

$(P00): $(P00).c
	$(CC) $(P00).c -o $(P00)

$(P01): $(P01).c
	$(CC) $(P01).c -o $(P01)

$(P02): $(P02).c
	$(CC) $(P02).c -o $(P02)

$(P03): $(P03).c
	$(CC) $(P03).c -o $(P03)

$(P04): $(P04).c
	$(CC) $(P04).c -o $(P04)

$(P05a): $(P05a).c
	$(CC) $(P05a).c -o $(P05a)

$(P05b): $(P05b).c
	$(CC) $(P05b).c -o $(P05b)

$(P06a): $(P06a).c
	$(CC) $(P06a).c -o $(P06a)

$(P06b): $(P06b).c
	$(CC) $(P06b).c -o $(P06b)

$(P06c): $(P06c).c
	$(CC) $(P06c).c -o $(P06c)

$(P06d): $(P06d).c
	$(CC) $(P06d).c -o $(P06d)

$(P07): $(P07).c
	$(CC) $(P07).c -o $(P07)

$(P08): $(P08).c
	$(CC) $(P08).c -o $(P08)

$(P09): $(P09).c
	$(CC) $(P09).c -o $(P09)

$(P10): $(P10).c
	$(CC) $(P10).c -o $(P10)

$(P11): $(P11).c
	$(CC) $(P11).c -o $(P11)

$(P12): $(P12).c
	$(CC) $(P12).c -o $(P12)

$(P13): $(P13).c
	$(CC) $(P13).c -o $(P13)

$(P14): $(P14).c
	$(CC) $(P14).c -o $(P14)

$(P15): $(P15).c
	$(CC) $(P15).c -o $(P15)

$(P16): $(P16).c
	$(CC) $(P16).c -o $(P16)

clean:
	rm -f $(EXECS)

