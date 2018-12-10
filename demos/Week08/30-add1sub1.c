/*
 * (C) 2018 Rahmat M. Samik-Ibrahim
 * You are free to SHARE and to ADAPT,
 * but WITHOUT ANY WARRANTY.
 * REV03 Mon Dec 10 15:37:09 WIB 2018
 * REV02 Wed Nov 21 20:48:39 WIB 2018
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

#define MYFLAGS     O_CREAT | O_RDWR
#define MYPROTECT PROT_READ | PROT_WRITE
#define MYVISIBILITY          MAP_SHARED

typedef  struct {
   sem_t  sync[3];
   int    share;
   int    loop;
} myshare;

myshare* mymap;
char*    sfile = "demo-file.bin";

void flushprintf(char* tag1, char* tag2) {
   printf("%s[%s] loop(%d) - PID(%d)\n", tag1,
      tag2, mymap->loop, getpid());
   fflush(NULL);
}

// 4567890123456789012345678901234567890
void main(void) {
   int fd  =open(sfile,MYFLAGS,S_IRWXU);
   int ssize=sizeof(myshare);
   truncate(sfile, ssize);
   mymap=mmap(NULL, ssize, MYPROTECT, 
              MYVISIBILITY, fd, 0);
   mymap->share = 0;
   mymap->loop  = 6;
   sem_init (&(mymap->sync[0]), 1, 0);
   sem_init (&(mymap->sync[1]), 1, 0);
   sem_init (&(mymap->sync[2]), 1, 0);
   flushprintf("30====", "EXEC");
   if (!fork()) execlp("./31-add1", " 31 ++", NULL);
   if (!fork()) execlp("./32-sub1", " 32 --", NULL);
   sleep(1);
   while (--mymap->loop) {
      flushprintf("30====", "LOOP");
      sleep(1);
   }
   flushprintf("30====", "WAIT");
   sem_wait (&(mymap->sync[0]));
   sem_wait (&(mymap->sync[0]));
   wait(NULL);
   wait(NULL);
   flushprintf("30====", "EXIT");
   close(fd);
}

//       1         2         3         4
// 4567890123456789012345678901234567890

