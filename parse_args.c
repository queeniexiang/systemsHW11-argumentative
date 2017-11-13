/* 
Queenie Xiang
Systems pd5
HW11: Don't get argumentative
2017-11-13
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* TESTING
   char line[100] = "wow-this-is-cool";
   char *s1 = line;
   printf("[%s]\n", strsep( &s1, "-" ));
   printf("[%s]\n", s1);
*/

char ** parse_args( char * line ) {
  char ** arr = (char **) calloc(6, sizeof(char*));
  char ** arr_ptr = arr;
  char * ptr = line;
  
  while (ptr != NULL) { 
    //printf("%s\n", strsep(&ptr, " "));
    *(arr) = strsep( &ptr, " " );
    arr++; 
  }

  return arr_ptr;
}


int main() {
  char str[100] = "ls -l";
  char ** args = parse_args( str );
  //printf("%s\n", args[0]); 
  execvp(args[0], args);
  return 0;
}
