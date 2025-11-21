#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX 100
#define SIZE_INT sizeof(int)

int aggregate(const char *array);

int main() {
    char *array_p[5];
    array_p[0] = "string 1";
    printf("size is: %d first element: %s length: %d\n", sizeof(array_p), array_p[0], strlen(array_p[0]));
    /*printf("int is: %d\n", SIZE_INT); */
    printf("aggregating address %p\n", array_p);
    aggregate(array_p);
    exit(EXIT_SUCCESS);
}

int aggregate(const char array) {
    printf("Got address: %p\n", &array);
    return 0;
    int i;
    for (i=0; i < (sizeof(array)/SIZE_INT); i++ ) {
        if (strlen(array[i]) > 0) {
             printf("array[%d] = %s\n", i, array[i]);
        } else {
            printf("array[%d] is empty\n", i);
        }
    }
}
