/*
 * Copyright (C) 2018-2019 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV02 Wed Feb 27 19:17:38 WIB 2019
 * REV01 Wed Oct  3 19:59:08 WIB 2018
 *
 * The "array"   starts  at 0x601040
 * The "pointer" address is 0x601050
 */

#include <stdio.h>

char  array[]="0123456789ABCDE";
char* pointer=array;
void  main(void) {
   printf("START\n");
   printf("%p\n", &pointer);
   printf("%p\n",  pointer);
   printf("%s\n",  pointer);
   printf("%d\n",  pointer[15]);
   printf("STOP\n");
}


