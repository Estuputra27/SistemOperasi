/*
 * Copyright (C) 2017-2019 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV03 Wed Feb 27 19:10:33 WIB 2019
 * START Thu Mar 30 12:13:58 WIB 2017
 */

#include <stdio.h>

int tambah(int ii, int jj) {
	return ii + jj;
}

void main(void) {
   int ii = 4;
   printf("The return of tambah is %d\n", tambah(1,ii));
}

