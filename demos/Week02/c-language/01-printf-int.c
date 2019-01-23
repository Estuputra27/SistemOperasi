/*
 * Copyright (C) 2016-2019 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV03 Wed Jan 23 17:47:41 WIB 2019
 * REV02 Tue Aug 28 13:31:19 WIB 2018
 * START Thu Sep 15 11:47:10 WIB 2016
 */

#include <stdio.h>

void main (void) {
   int   ii   = 74;             // Integer

   printf("ii = %d\n", ii);
   printf("ii = %5d\n", ii);
   printf("ii = %2d\n", ii);
   printf("ii = %-5d\n", ii);
   printf("ii = %5.5d\n", ii);
   printf("ii = %5.3d\n", ii);
   printf("ii = %c\n", ii);
   printf("ii = %x\n", ii);
   printf("ii = %#x\n", ii);
   printf("ii = %X\n", ii);
   printf("ii = %#X\n", ii);
   printf("ii = %o\n", ii);
   printf("ii = %#o\n", ii);
}

