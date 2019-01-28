/*
 * Copyright (C) 2019 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV00 Mon Jan 28 19:08:40 WIB 2019
 * START Mon Jan 28 10:03:57 WIB 2019
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define STRING      "This is a string"
#define LONG_STRING "Is this a long long long long string?"

char string_array[256];

void main(void) {
   sprintf(string_array, "%s\n", STRING);
   printf("%s", string_array);
   sprintf(string_array, "%s\n", LONG_STRING);
   printf("%s", string_array);
   string_array[7]=0;
   printf("%s\n", string_array);
}

