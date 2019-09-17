/*
 * Copyright (C) 2016-2019 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV05 Tue Sep 17 18:13:22 WIB 2019
 * REV04 Tue Feb 26 09:34:37 WIB 2019
 * REV02 Tue Aug 28 13:31:19 WIB 2018
 * START Thu Sep 15 11:47:10 WIB 2016
 */

#include <stdio.h>

void main (void) {
   int   ii   = 74;             // Integer

   printf("(%%d)    ii = (%d)\n",    ii);
   printf("(%%5d)   ii = (%5d)\n",   ii);
   printf("(%%1d)   ii = (%1d)\n",   ii);
   printf("(%%-5d)  ii = (%-5d)\n",  ii);
   printf("(%%5.5d) ii = (%5.5d)\n", ii);
   printf("(%%5.3d) ii = (%5.3d)\n", ii);
   printf("(%%c)    ii = %c\n",      ii);
   printf("(%%x)    ii = %x\n",      ii);
   printf("(%%#x)   ii = %#x\n",     ii);
   printf("(%%X)    ii = %X\n",      ii);
   printf("(%%#X)   ii = %#X\n",     ii);
   printf("(%%o)    ii = %o\n",      ii);
   printf("(%%#o)   ii = %#o\n",     ii);
}

