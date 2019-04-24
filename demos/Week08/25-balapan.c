/*
 *** DRAFT *** DRAFT *** WORK IN PROGRESS ***
 *** DRAFT *** DRAFT *** WORK IN PROGRESS ***
 *** DRAFT *** DRAFT *** WORK IN PROGRESS ***
 Copyright 2019 Rahmat M. Samik-Ibrahim
 You are free to SHARE (copy and 
 redistribute the material in any medium
 or format) and to ADAPT (remix, 
 transform, and build upon the material 
 for any purpose, even commercially).
 This program is distributed in the hope 
 that it will be useful, but WITHOUT ANY
 WARRANTY; without even the implied 
 warranty of MERCHANTABILITY or FITNESS 
 FOR A PARTICULAR PURPOSE.

 * REV00 Wed Apr 24 18:02:10 WIB 2019
 * START Wed Apr 24 18:02:10 WIB 2019
 */

#include <semaphore.h>
#include <stdio.h>
#include <stdbool.h>

#define LAP     10
#define NAME    20
#define DRIVERS 2

typedef  struct {
   char  *name;
   int   laptime;
   int   carNumber;
   bool  lap[LAP];
} drivers;

typedef struct {
   sem_t    mutex;
   drivers  D[];
} shareInfo;

shareInfo  S={{},{
               {"Driver 21", 73210, 21, {}},
               {"Driver 22", 73220, 22, {}},
               {"Driver 23", 73230, 23, {}},
             }};

// DO NOT USE THE SAME SEMAPHORE NAME!!!!
// Replace "demo" with your own SSO name.
// WARNING: NO ERROR CHECK! ////////////
void main(void) {
   printf("Name:%s, laptime=%d, car=%d, laps=%d-%d\n",
      S.D[0].name, S.D[0].laptime, S.D[0].carNumber,
      S.D[0].lap[0], S.D[0].lap[LAP-1]);
   printf("Name:%s, laptime=%d, car=%d, laps=%d-%d\n",
      S.D[2].name, S.D[2].laptime, S.D[2].carNumber,
      S.D[2].lap[0], S.D[2].lap[LAP-1]);
}

//       1         2         3         4
// 4567890123456789012345678901234567890

/*
 * TAKE NOTE (RMS)
 */

