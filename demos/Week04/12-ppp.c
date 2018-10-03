/*
 * Copyright (C) 2018 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV00 Wed Oct  3 19:59:08 WIB 2018
 * START Wed Oct  3 19:59:08 WIB 2018
 *
 */

#include <stdio.h>
/* Global Variables */
unsigned char    varchr='a';
unsigned char*   ptrchr=&varchr;
unsigned char**  ptrptr=&ptrchr;
unsigned char*** pptptr=&ptrptr;

void main(void) {
   printf("   varchr=%c,     ADDR=%p\n", varchr, &varchr);
   printf("  *ptrchr=%c,    VALUE=%p,    ADDR=%p\n",                      *ptrchr,   ptrchr, &ptrchr);
   printf(" **ptrptr=%c,  *ptrptr=%p,   VALUE=%p,  ADDR=%p\n",           **ptrptr,  *ptrptr,  ptrptr, &ptrptr);
   printf("***pptptr=%c, **pptptr=%p, *pptptr=%p, VALUE=%p, ADDR=%p\n", ***pptptr, **pptptr, *pptptr,  pptptr, &pptptr);
}

