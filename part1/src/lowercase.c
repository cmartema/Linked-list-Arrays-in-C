#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"

/**
 * Take an array of char* pointers and print each of the strings to standard
 * out. This function must use only pointer arithmetic and no array
 * subscripting. The output start with "[", ends with "]\n", and prints the
 * strings inside, each separated by a comma and space.
 * Example: [Hi, BYE, AP, COMSW 3157, FunTimes]
 */
void display_strings(char **strings) {
    printf("[");
    if (strings != NULL) {
        char **str_ptr = strings;
        if (*str_ptr != NULL) {
            printf("%s", *str_ptr++);
            while (*str_ptr != NULL) {
                printf(", %s", *str_ptr++);
            }
        }
    }
    printf("]\n");
}

static char **copy_args_lowercase(int argc, char **argv) {

	char **copy = (char **)malloc(argc * sizeof(char *));

	for(int i = 1; i < argc; i++){
		//printf("argv[i] = %s\n", argv[i]); 
		copy[i] = (char *)malloc(100 * sizeof(char));
		copy[i] = my_strcpy(copy[i], argv[i]); 
                
		//printf("copy[i] = %s\n", copy[i]);
		my_strlower(copy[i]); 
		
		//printf("copy[i] = %s\n", copy[i]);

	}    
	
	return copy;
}

static void free_copy(char **copy) {

	size_t len = my_strlen(*copy); 

	for(int i = 0; i < len; i++){

		free((void *)copy[i]); 
	}

	free(copy); 
}


/**
 * DO NOT MODIFY main()
 */
int main(int argc, char **argv) {

    char **copy;
    copy = copy_args_lowercase(argc, argv);

    printf("Raw arguments       : ");
    display_strings(argv + 1);

    printf("Lowercase arguments : ");
    display_strings(copy);

    free_copy(copy);

    return EXIT_SUCCESS;
}
