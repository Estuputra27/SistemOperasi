/*
 * Copyright (C) 2015-2018 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV08 Wed Nov 14 17:32:43 WIB 2018
 * REV02 Tue Apr 18 15:28:19 WIB 2017
 * REV01 Wed Nov  2 11:49:30 WIB 2016
 * START Xxx Sep 30 XX:XX:XX UTC 2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "99-myutils.h"

#define  LOOP0      6

volatile int loop  = LOOP0;
volatile int share = 0;

void  sleepflush(int ii) {
   sleep (ii);
   fflush(NULL);
}

void* thread1 (void* a) {
   printf("THREAD#1--PID[%d]\n", getpid());
   sleepflush(1);
   rehat_acak(100);
   share = 1000;
   while (loop > 0) {
      rehat_acak(100);
      share++;
   }
}

void* thread2 (void* a) {
   printf("THREAD#2--PID[%d]\n", getpid());
   sleepflush(1);
   rehat_acak(100);
   share = 2000;
   while (loop > 0) {
      rehat_acak(100);
      share--;
   }
}

void* thread3 (void* a) {
   printf("THREAD#3--PID[%d]\n", getpid());
   while (loop-- > 0) {
      printf("SHARE  =  %4.4d\n", share);
      sleepflush(1);
   }
}

void main(void) {
   printf("MAIN------PID[%d]\n", getpid());
   daftar_trit   (thread1);
   daftar_trit   (thread2);
   daftar_trit   (thread3);
   jalankan_trit ();
   beberes_trit  ("Done...");
}

/*
 * TAKE NOTE(MGW)
 * Thread berjalan concurrently (berdampingan) dan mengakses memori 
 * yang sama secara bersamaan. Ketika main dijalankan, pertama akan 
 * mendaftarkan thread, mulai dari thread1, thread2, lalu thread3.
 * Lalu saat fungi jalankan_trit() dijalankan, thread akan jalan bersamaan 
 * dari pertama terdaftar, maka thread1 jalan terlebih dahulu lalu thread2 
 * lalu thread3 (print I am a thread masing-masing), dan sleep(1)
 * menunggu selama 1 detik.
 *
 * Kemudian thread1, thread2, dan thread3 kembali jalan bersamaan. 
 * Di saat yang bersamaan, thread1 mengubah share menjadi 1000 dan thread2 
 * mengubah share menjadi 2000 (kita tidak tahu siapa yang akan jalan terlebih 
 * dahulu sehingga variable share bisa menjadi 1000 atau 2000), dan akaan looping 
 * bersamaan pada thread1 dan thread2 increment dan decrement share.
 * Sedangkan pada thread3, setiap 2 detik akan print hasil share sebanyak 5 kali 
 * (seiring diubahnya share pada thread1 dan thread2).
 *
 * Setelah selesai, print "I am MAIN" yang diikuti dengan beberes_trit() untuk 
 * clear thread yang ada dan print "Done...".
 *
 * Hal ini disebut "Race condition" dimana tidak ada keteraturan dan kejelasan 
 * ketika beberapa thread mengakses 1 variable yang sama. Maka dari itu, 
 * datang peran semaphore pada file berikutnya.
 */

