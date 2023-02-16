#include <stdio.h>
#include <string.h>
#include "linked_list.h"

int cmp(const void *a, const void *b) {
	return strcmp(*(const char **)a, *(const char **)b);
}

void display_list(void *data) {
	printf("\"%s\"", (char*)data);
}

int main(int argc, char **argv) {
    linked_list *list = create_linked_list();
    for (int i = 1; i < argc; i++) {
	    insert_in_order(list, &argv[i], cmp);
    }
    print_list(list, display_list);
    free_list(list, free);
    return EXIT_SUCCESS;
}
