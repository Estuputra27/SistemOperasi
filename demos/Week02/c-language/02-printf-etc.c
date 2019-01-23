/*
 * Copyright (C) 2016-2019 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV03 Wed Jan 23 17:48:33 WIB 2019
 * REV02 Tue Aug 28 13:31:19 WIB 2018
 * START Thu Sep 15 11:47:10 WIB 2016
 */

#include <stdio.h>

#define STRING "This is a string!\n"

void main (void) {
   char  cc='A';                // Character
   char  dd[]="The string";     // The string

   printf(STRING);
   printf("cc=%c\n", cc);
   printf("dd[]= %c%c%c ... %c\n", dd[0], 
           dd[1], dd[2], dd[sizeof(dd)-2]);
}

