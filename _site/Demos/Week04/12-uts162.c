/* (c) 2016 Rahmat M. Samik-Ibrahim -- This is free software
 * Assume (&ptrchr is 0x7FFFEEDDCCBB, order of bytes: little-endian) */
#define LINES  3
#include <stdio.h>
void printeq(int lines) {
   while (lines-- > 0 ) printf("= = ");
   printf("\n");
}
void main(void) {
   int             ii;
   unsigned char   dummy  = 'a';
   unsigned char*  ptrchr = &dummy;

   printeq(LINES);
   printf(" dummy:  %c\n", dummy);
   printf("*ptrchr: %c\n", *ptrchr);
   printeq(LINES);
   printf("%p\n", &ptrchr);
   printeq(LINES);
   ptrchr = (char*) &ptrchr;
   for (ii=0; ii<6; ii++) {
      printf("%X ", *ptrchr);
      ptrchr++;
   }
   putchar('\n');
   printeq(LINES);
}

