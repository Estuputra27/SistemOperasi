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

 * REV03 Sun Apr 28 10:32:18 WIB 2019
 * REV02 Fri Apr 26 14:26:13 DST 2019
 * REV01 Thu Apr 25 09:25:10 WIB 2019
 * START Wed Apr 24 18:02:10 WIB 2019
 */

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
#include <unistd.h>

#define LAP         50
#define NAME        20
#define TMPSTRING   256
#define MILISECOND  877
#define DELAY0      1
#define DELAY1      200
#define DELAY2      5
#define LT          50
#define MYFLAGS     O_CREAT | O_RDWR
#define MYPROTECT PROT_READ | PROT_WRITE
#define MYVISIBILITY          MAP_SHARED
#define SFILE       "demo-file.bin"

typedef  struct {
   char  name[NAME];
   int   laptime;
   int   carNumber;
   int   lapCount;
} drivers;
drivers  D[]={
   //= Driver Name = = =,lapTime, Car#,Lap#[] 
   {"Valtteri Bottas    ", 80177,   77, 0},
   {"Lewis Hamilton     ", 80244,   44, 0},
   {"Max Verstappen     ", 80333,   33, 0},
   {"Sebastian Vettel   ", 80405,    5, 0},
   {"Charles Leclerc    ", 80516,   16, 0},
   {"Kevin Magnussen    ", 80620,   20, 0},
   {"Nico Huelkenberg   ", 80727,   27, 0},
   {"Kimi Raeikkoenen   ", 80807,    7, 0},
   {"Lance Stroll       ", 80918,   18, 0},
   {"Daniil Kvyat       ", 81026,   26, 0},
   {"Pierre Gasly       ", 81110,   10, 0},
   {"Lando Norris       ", 81204,    4, 0},
   {"Sergio Perez       ", 81311,   11, 0},
   {"Alexander Albon    ", 81423,   23, 0},
   {"Antonio Giovinazzi ", 81599,   99, 0},
   {"George Russell     ", 81663,   63, 0},
   {"Robert Kubica      ", 81788,   88, 0},
   {"Romain Grosjean    ", 81808,    8, 0},
   {"Daniel Ricciardo   ", 81903,    3, 0},
   {"Carlos Sainz Jr.   ", 82055,   55, 0}
};
#define NDRIVERS (int)(sizeof(D)/sizeof(D[0]))
typedef struct {
  sem_t   mutex0;
  sem_t   mutex1;
  sem_t   mutex2;
  int     ndrivers;
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
   int fd   =open(SFILE,MYFLAGS,S_IRWXU);
   truncate(SFILE, MSIZE);
   mymap=mmap(NULL, MSIZE, MYPROTECT, 
              MYVISIBILITY, fd, 0);
   mymap->relPID=getpid() - 1000;
   flushprintf("INIT: START");
   sem_init (&(mymap->mutex0), 1, 0);
   sem_init (&(mymap->mutex1), 1, 1);
   sem_init (&(mymap->mutex2), 1, 2);
   mymap->ndrivers=NDRIVERS;
   memcpy(mymap->D, D, (int) sizeof(D));
   flushprintf("INIT: DONE");
}
// ======================
void car(int number) {
      sem_wait(&(mymap->mutex1));
      sprintf(tmpString, "Car[%2.2d] is ready!",
         mymap->D[number].carNumber);
      flushprintf(tmpString);
      sem_post(&(mymap->mutex1));
      do {
         sem_wait(&(mymap->mutex0));
         miliSleep(DELAY0);
         sem_post(&(mymap->mutex0));
         sem_wait(&(mymap->mutex2));
         miliSleep(DELAY2);
         sem_post(&(mymap->mutex2));
         sem_post(&(mymap->mutex1));
         int idx1=sprintf(tmpString, "[%2.2d]  %s -- %2d",
            mymap->D[number].carNumber,
            mymap->D[number].name,
            mymap->D[number].lapCount);
         flushprintf(tmpString);
         sem_post(&(mymap->mutex1));
         for(int ii=0;ii<mymap->D[number].laptime*LT;ii++)
            ;
         miliSleep(DELAY1);
      } while (mymap->D[number].lapCount++ < LAP);
      exit (0);
}
// ==============
void main(void) {
   init();
   flushprintf("main: START");
   for (int ii=0; ii<NDRIVERS; ii++)
      if(!fork()) car(ii); 
   for (int ii=0;ii<3;ii++) {
      system("date '+DRIFT MILISECOND: %N'");
      miliSleep(1000);
   }
   sem_post(&(mymap->mutex0));
   for (int ii=0; ii<NDRIVERS; ii++)
      wait(NULL);
   flushprintf("main: STOP");
}

//       1         2         3         4
// 4567890123456789012345678901234567890

