#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

typedef  struct {
   char  mystring[16];
   int   myint;
} myshare;

#define MYFLAGS      O_CREAT|O_RDWR
#define MYPROTECTION PROT_READ|PROT_WRITE
#define MYVISIBILITY MAP_SHARED
char*  sfile="demo-file.bin";

void main(void) {
   printf("TBA1:create mmap\n");
   int ssize=sizeof(myshare);
   int fd=open(sfile,MYFLAGS,S_IRWXU);
   myshare* mymap=mmap(NULL, ssize, MYPROTECTION, MYVISIBILITY, fd, 0);
   if (mymap == MAP_FAILED) exit(1);
   mymap->mystring[0]='X';
   mymap->mystring[1]='Y';
   mymap->mystring[2]='Z';
   mymap->mystring[3]='\0';
   mymap->myint=0x61626364;
   close(fd);
   printf("TBA6:create mmap\n");
}

