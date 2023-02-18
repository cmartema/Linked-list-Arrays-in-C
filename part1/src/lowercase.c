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
	int j = 0; 
	for(int i = 1; i < argc; i++){
		copy[j] = (char *)malloc((my_strlen(argv[i])+1) * sizeof(char *));
		copy[j] = my_strcpy(copy[j], argv[i]);
		my_strlower(copy[j]); 
		
		j++; 
	}    
 	
	copy[argc-1] = NULL; 

	return copy;
}

static void free_copy(char **copy) {
 
	int i = 0; 
	while(copy[i] != NULL){

		free(copy[i]);
	        i++;
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
