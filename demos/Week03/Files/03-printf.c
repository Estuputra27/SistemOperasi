#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define DEMO "demo-file4.txt"

void main(void) {
   int filed = open (DEMO, O_APPEND | O_RDWR , 0664);
   if (filed < 0) {
      printf("fopen error...\n");
      exit(1);
   }
   dprintf(filed, "[dprintf] file: %s; discriptor: %d\n", DEMO, filed);
   close(filed); 

   FILE *filep = fopen(DEMO, "aw"); 
   if (filep == NULL) {
      printf("fopen error...\n");
      exit(1);
   }
   fprintf(filep, "[fprintf] file: %s\n", DEMO);
   fclose(filep); 

   printf("See also file %s\n", DEMO);
}

