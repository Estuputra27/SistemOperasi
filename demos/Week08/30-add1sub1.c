/*
 * Copyright (C) 2018 Rahmat M. Samik-Ibrahim
 * You are free to SHARE (copy and redistribute the material in any medium or 
 * format) and to ADAPT (remix, transform, and build upon the material for any 
 * purpose, even commercially).  This program is distributed in the hope that 
 * it will be useful, but WITHOUT ANY WARRANTY; without even the implied 
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV02 Wed Nov 21 20:48:39 WIB 2018
 * REV01 Thu Nov 15 12:27:16 WIB 2018
 * START Wed Nov 14 20:30:05 WIB 2018
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define MYFLAGS      O_CREAT | O_RDWR
#define MYPROTECTION PROT_READ|PROT_WRITE
#define MYVISIBILITY MAP_SHARED
char*  sfile="demo-file.bin";

typedef  struct {
   sem_t  sync1;
   sem_t  sync2;
   int    share;
   int    loop;
} myshare;

myshare* mymap;

void flushprintf(char* tag1, char* tag2) {
   printf("%s[%s] S/L(%4d/%d) - P/PPID(%5d/%d)\n", tag1,
      tag2, mymap->share, mymap->loop, getpid(), getppid());
   fflush(NULL);
}

void main(int argc, char* argv[]) {
   int     fd   =open(sfile,MYFLAGS,S_IRWXU);
   int     ssize=sizeof(myshare);
   truncate(sfile, ssize);
   mymap=mmap(NULL, ssize, MYPROTECTION, MYVISIBILITY, fd, 0);
   mymap->share = 0;
   mymap->loop  = 6;
   sem_init (&(mymap->sync1), 1, 0);
   sem_init (&(mymap->sync2), 1, 0);
   flushprintf("EXEC", "Parent");
   if (!fork()) execlp("./31-add1", "31ADD1", NULL);
   if (!fork()) execlp("./32-sub1", "32SUB1", NULL);
   sleep(1);
   sem_post (&(mymap->sync1));
   sem_post (&(mymap->sync1));
   while (--mymap->loop) {
      flushprintf("LOOP", "Parent");
      sleep(1);
   }
   flushprintf("WAIT", "Parent");
   sem_wait (&(mymap->sync2));
   sem_wait (&(mymap->sync2));
   wait(NULL);
   wait(NULL);
   flushprintf("EXIT", "Parent");
   close(fd);
}

