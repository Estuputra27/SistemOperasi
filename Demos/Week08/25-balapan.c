/*
 *** DRAFT *** DRAFT *** WORK IN PROGRESS ***
 *** DRAFT *** DRAFT *** WORK IN PROGRESS ***
 *** DRAFT *** DRAFT *** WORK IN PROGRESS ***
// WARNING: NO ERROR CHECK! ////////////
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

 * REV07 Mon May  6 08:40:58 WIB 2019
 * REV06 Fri May  3 14:13:28 WIB 2019
 * REV05 Mon Apr 29 16:11:26 WIB 2019
 * REV03 Sun Apr 28 10:32:18 WIB 2019
 * REV02 Fri Apr 26 14:26:13 DST 2019
 * REV01 Thu Apr 25 09:25:10 WIB 2019
 * START Wed Apr 24 18:02:10 WIB 2019
 */

#define LAP          3
#define S1           0
#define S2           2
#define S3           2
#define LT           1000
#define DELAY1       10
#define DELAY2       20
#define SECTORTIME   300
#define MILISECOND   901
#define DRIFTLOOP    3
#define NAME         25
#define TMPSTRING    128
#define MYPROTECT    PROT_READ     | PROT_WRITE
#define MYVISIBILITY MAP_ANONYMOUS | MAP_SHARED

#include <fcntl.h>
#include <semaphore.h>
#include <stdbool.h>     
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

typedef  struct {
   char  name[NAME];
   int   speedAvg;
   int   lapCount;
   int   relTime;
} drivers;
drivers  D[]={
   //= (Car#) Driver Name, SpeedAvg,Lap,RelTime
    {"(77) Valtteri Bottas    ", 80177, 0, 0}
   ,{"(44) Lewis Hamilton     ", 80244, 0, 0}
   ,{"(33) Max Verstappen     ", 80333, 0, 0}
   ,{"(05) Sebastian Vettel   ", 80405, 0, 0}
/*
   ,{"(16) Charles Leclerc    ", 80516, 0, 0}
   ,{"(20) Kevin Magnussen    ", 80620, 0, 0}
   ,{"(27) Nico Huelkenberg   ", 80727, 0, 0}
   ,{"(07) Kimi Raeikkoenen   ", 80807, 0, 0}
   ,{"(18) Lance Stroll       ", 80918, 0, 0}
   ,{"(26) Daniil Kvyat       ", 81026, 0, 0}
   ,{"(10) Pierre Gasly       ", 81110, 0, 0}
   ,{"(04) Lando Norris       ", 81204, 0, 0}
   ,{"(11) Sergio Perez       ", 81311, 0, 0}
   ,{"(23) Alexander Albon    ", 81423, 0, 0}
   ,{"(99) Antonio Giovinazzi ", 81599, 0, 0}
   ,{"(63) George Russell     ", 81663, 0, 0}
   ,{"(88) Robert Kubica      ", 81788, 0, 0}
   ,{"(08) Romain Grosjean    ", 81808, 0, 0}
   ,{"(03) Daniel Ricciardo   ", 81903, 0, 0}
   ,{"(55) Carlos Sainz Jr.   ", 82055, 0, 0}
*/
};
#define NDRIVERS (int)(sizeof(D)/sizeof(D[0]))
typedef struct {
  sem_t   sector1;
  sem_t   sector2;
  sem_t   sector3;
  int     ndrivers;
  int     relTime;
  pid_t   relPID;
  drivers D[NDRIVERS];
} shareMem;
#define MSIZE (int) sizeof(shareMem)
shareMem* mymap;
char      tmpString[TMPSTRING];
// ==============================
void flushprintf(char* message) {
   pid_t relPID=getpid() - mymap->relPID;
   printf("RPID[%d] %s\n", relPID, message); 
   fflush(NULL);
}
// ===========================
void miliSleep(int duration) {
   for(int ii=0; ii<duration; ii++) 
      usleep(MILISECOND);
}
// ==============
void init(void) {
   mymap=mmap(NULL, MSIZE, MYPROTECT, 
              MYVISIBILITY, 0, 0);
   mymap->relPID=getpid() - 1000;
   flushprintf("INIT: START");
   sem_init (&(mymap->sector1), 1, S1);
   sem_init (&(mymap->sector2), 1, S2);
   sem_init (&(mymap->sector3), 1, S3);
   mymap->ndrivers=NDRIVERS;
   mymap->relTime=0;
   memcpy(mymap->D, D, (int) sizeof(D));
   flushprintf("INIT: DONE");
}
// ===================
void car(int number) {
   do {
      sem_wait(&(mymap->sector1));
      miliSleep(DELAY1);
      sem_post(&(mymap->sector1));
      miliSleep(SECTORTIME);
      sem_wait(&(mymap->sector2));
      miliSleep(DELAY2);
      sem_post(&(mymap->sector2));
      miliSleep(SECTORTIME);
      sem_post(&(mymap->sector3));
      for(int ii=0;
         ii<mymap->D[number].speedAvg*LT;ii++)
            ;
      sem_post(&(mymap->sector3));
      miliSleep(SECTORTIME);
      mymap->D[number].relTime=
         mymap->relTime++;
   } while (++mymap->D[number].lapCount < LAP);
   sprintf(tmpString, "%s Lap %2d rTime %3d",
      mymap->D[number].name,
      mymap->D[number].lapCount,
      mymap->D[number].relTime);
   flushprintf(tmpString);
   exit (0);
}
// ==============
void main(void) {
   init();
   flushprintf("MAIN: READY");
   for (int ii=0; ii<NDRIVERS; ii++)
      if(!fork()) car(ii); 
   sem_post(&(mymap->sector1));
   flushprintf("MAIN: START");
   for (int ii=0; ii<NDRIVERS; ii++)
      wait(NULL);
   flushprintf("MAIN: FINISH");
}

//       1         2         3         4
// 4567890123456789012345678901234567890

