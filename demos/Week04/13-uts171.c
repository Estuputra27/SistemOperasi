/*
 * Copyright (C) 2017-2019 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV01 Thu Jan 17 16:12:18 WIB 2019
 * START Thu Mar 30 18:27:30 WIB 2017
 * INT is 32 bit little endian
 * 41H='A'; 42H='B'; 43H='C"; 44H='D'
 */

#include <stdio.h>
char chrary[]="ZZZZ ZZZZ ";
void main(void) {
   char  chrvar = 'M';
   int   intvar = 0x41424344;
   int*  intptr = (int*) chrary;
   printf("YY.     chrary=%p\n",  chrary);
   printf("ZZ.     intprt=%p\n",  intptr);
   printf("01.     chrvar=%c\n",  chrvar);
   printf("02.    *chrary=%c\n", *chrary);
   printf("03. str chrary=%s\n",  chrary);
   *intptr      =  intvar;
   printf("04. str chrary=%s\n",  chrary);
}


