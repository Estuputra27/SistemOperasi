/*
 * Copyright (C) 2018 Rahmat M. Samik-Ibrahim
 * You are free to SHARE (copy and redistribute the material in any medium or 
 * format) and to ADAPT (remix, transform, and build upon the material for any 
 * purpose, even commercially).  This program is distributed in the hope that 
 * it will be useful, but WITHOUT ANY WARRANTY; without even the implied 
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV00 Wed Nov 14 20:30:05 WIB 2018
 * START Wed Nov 14 20:30:05 WIB 2018
 */

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
   char  ends[2];
} myshare;

#define MYFLAGS      O_RDWR
#define MYPROTECTION PROT_READ|PROT_WRITE
#define MYVISIBILITY MAP_SHARED
char*  sfile="demo-file.bin";

void main(void) {
   printf("TBA1:create mmap\n");
   int ssize=sizeof(myshare);
   int fd=open(sfile,MYFLAGS,S_IRWXU);
   myshare* mymap=mmap(NULL, ssize, MYPROTECTION, MYVISIBILITY, fd, 0);
   printf("TBA2:create mmap\n");
   if (mymap == MAP_FAILED) exit(1);
   printf("TBA3:create mmap\n");
   mymap->mystring[0]='X';
   mymap->mystring[1]='Y';
   mymap->mystring[2]='Z';
   mymap->mystring[3]=' ';
   mymap->myint=0x61626364;
   close(fd);
   printf("TBA6:create mmap\n");
}

