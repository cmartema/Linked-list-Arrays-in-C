#include <stddef.h>
#include "mystring.h"

#include <stdio.h>

/**
 * This function calculates the length of a character array passed in,
 * returning the length as a size_t. Calculation must be done via pointer
 * arithmetic. No credit will be given for calling strlen() in <string.h>.
 * 
 * src: character array, possibly NULL (which will be considered length 0)
 * 
 * return: length of src as a size_t
 */
size_t my_strlen(char *src){
	
	char *ptr = src;
	size_t len = 0; 

	while(*ptr != '\0'){
		len++;
		ptr++; 
	}

	return len; 

	//len = sizeof(src)/sizeof(char);
	//return len;
}

/**
 * This function copies a character array src into dest. The caller must ensure
 * that the length of dst is at least length of src plus one. This function then
 * returns a pointer to dst. Computation must be done via pointer arithmetic.
 * No credit will be given for calling memcpy() in <string.h>.
 * 
 * dst: target character array
 * src: source character array, possibly NULL
 *
 * return: pointer to dst
 *         If src is NULL, return NULL.
 */
char *my_strcpy(char *dst, char *src){

	if(src == NULL){
		return NULL; 
	}

	char *s = src;
	char *d = dst;

	while(*s != '\0'){
		*d = *s;
                s++;
	        d++;
         }
	
	*d = '\0';

	return dst;

}

/**
 * This function loops over the character array src, converting any uppercase
 * character to lowercase. You must use tolower() from <ctype.h> in this
 * function's implementation.
 *    
 * src: source character array, possibly NULL
 *
 * return: void
 */
void my_strlower(char *src){
	
	char *s = src; 

	while(*s != '\0'){
		if(*s >= 'A' && *s <= 'Z'){
			*s = tolower(*s);
		}
		s++; 
	}
}
