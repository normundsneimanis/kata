      #include <stdio.h>
      #include <string.h>
	#include <stdlib.h>

      #define MAX_LENGTH 5000
      #define MAX_LINES 15000

      void print_array ( char (*ary)[MAX_LENGTH] ) {
        int i=0, j=0; /* loop counters */
        char *p;
        for(i=0; i< MAX_LINES; i++){
          p = ary + i * MAX_LENGTH;
          for(j=0; j < MAX_LENGTH; j++){
            putchar(*ary);
            if(*ary == '\0'){
          break;
            }
          }
        }
      }
      int main(int argc, char **argv){

        int c; /* char buffer */
        int i=0, j=0; /* loop counters */
        char lines[MAX_LINES][MAX_LENGTH];
        /* open file : name is argv[1] */
        /* loop until EOF */
        while((c=getchar()) != EOF){
          if(i < MAX_LENGTH - 1){
            lines[j][i++] = c; 
          }
          if(c == '\n' || i == (MAX_LENGTH - 1)){
            lines[j++][i] = '\0'; /* end of string */
          }
          print_array(lines);
        }
		exit(EXIT_SUCCESS);
      } 
