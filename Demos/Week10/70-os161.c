/*
 * Copyright (C) 2015-2019 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV06 Tue Nov 26 11:39:10 WIB 2019
 * REV03 Tue May  7 19:53:23 WIB 2019
 * REV02 Fri May 18 13:56:21 WIB 2018
 * REV01 Xxx Jun 05 00:00:00 WIB 2016
 * START Xxx Xxx XX 00:00:00 WIB 2015
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FILE "70-os161-demo.txt"

char *string = "ABCD\n";
void main(void) {
   int fileDescriptor;
   printf("See also file %s\n", FILE);
   close(STDOUT_FILENO);
   fileDescriptor = open (FILE, O_RDWR|O_CREAT|O_TRUNC, 0644);
   printf ( "%s", string);
   write(fileDescriptor, string, strlen(string));
}
