/*
 * Copyright (C) 2019 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV00 Mon Jan 28 19:04:48 WIB 2019
 * START Mon Jan 28 10:03:57 WIB 2019
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define DEMO "demo-file4.txt"

void main(void) {
   int filed = open (DEMO, O_APPEND | O_RDWR , 0664);
   if (filed < 0) {
      printf("fopen error...\n");
      exit(1);
   }
   dprintf(filed, "[dprintf] file: %s; discriptor: %d\n", DEMO, filed);
   printf("See also file %s\n", DEMO);
   close(filed); 
}
