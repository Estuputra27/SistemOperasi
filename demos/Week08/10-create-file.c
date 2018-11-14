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
#include <string.h>
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

#define MYFLAGS      O_CREAT|O_RDWR
#define MYPROTECTION PROT_READ|PROT_WRITE
#define MYVISIBILITY MAP_SHARED
char*  sfile="demo-file.bin";

void main(void) {
   printf("Create a Shared File\n");
   int ssize=sizeof(myshare);
   myshare* mymap=malloc(ssize);
   strcpy((char*) mymap,"AAAAAAAAAABBBBBBabcd\n");
   int fd=open(sfile,MYFLAGS,S_IRWXU);
   write(fd,mymap,ssize);
   close(fd);
   printf("Please check file %s\n", sfile);
}

