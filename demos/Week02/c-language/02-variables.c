/*
 * Copyright (C) 2016-2018 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV02 Tue Aug 28 13:31:19 WIB 2018
 * START Thu Sep 15 11:47:10 WIB 2016
 */

#include <stdio.h>

void main (void) {
   int   ii=3;
   int   jj[]={1,2,3,4,5};
   char  cc='A';
   char  dd[]="This is a string";

   printf("Hello -- ");
   printf("This is a TEST\n");

   printf("The value of ii     is %d\n", ii);
   printf("The value of jj[0]  is %d\n", jj[0]);
   printf("The value of jj[4]  is %d\n", jj[4]);
   printf("The value of jj[%d]  is %d\n", ii, jj[ii]);
  
   printf("The value of cc     is %c\n", cc);
   printf("The value of dd[0]  is %c\n", dd[0]);
   printf("The value of dd[%d]  is %c\n", ii, dd[ii]);

   printf("The value of dd is  %s\n", dd);

}

/*
 * TAKE NOTE (AII)
 * This program defined int variable, int array,
 * char variable, and char array
 * The string literal assigned to a character array must be 
 * enclosed by double quotations
 *
 * When you run this program, line printf("") will 
 * print the string inside the parentheses to console
 *
 * String inside printf() may contain embedded format tags 
 * that are replaced by 
 * the values specified in subsequent additional arguments 
 * and formatted as requested
 * You can look up c format specifier at 
 * https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm
 */


