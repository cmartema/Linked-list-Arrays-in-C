#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


linked_list* create_linked_list() {
	linked_list *list = malloc(sizeof(linked_list));
	if (list == NULL) {
		return NULL;
	}
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return list;
}

bool insert_in_order(
		linked_list *list, void *data, int (*cmp)(const void*, const void*)) {
	if (list == NULL || data == NULL || cmp == NULL) {
		return false;
	}
	node *new_node = malloc(sizeof(node));
	if (new_node == NULL) {
		return false;
	}
	new_node->data = data;
	new_node->prev = NULL;
	new_node->next = NULL;
	
	//Case 1: Empty list
	if (list->head == NULL) {
		list->head = new_node;
		list->tail = new_node;
		list->size = 1;
		return true;
	}
	
	//Case 2: Insert at the head of the list 
	if (cmp(new_node->data, list->head->data) < 0) {
		new_node->next = list->head;
		list->head->prev = new_node;
		list->head = new_node;
		list->size++;
		return true;
	}

	//Case 3: Insert in the tail or middle of the list
	node *cur = list->head;
	while (cur != NULL && cmp(cur->data, new_node->data) < 0) {
		cur = cur->next;
	}
	if (cur == NULL) { 
		new_node->prev = list->tail;
		list->tail->next = new_node;
		list->tail = new_node;
	} else { 
		new_node->next = cur;
		new_node->prev = cur->prev;
		cur->prev->next = new_node;
		cur->prev = new_node;
	}
	list->size++;
	return true;
}

void print_list(linked_list *list, void (*print_function)(void*)) {
    putchar('[');
    node *cur = list->head;
    if (cur != NULL) {
        print_function(cur->data);
        cur = cur->next;
    }
    for ( ; cur != NULL; cur = cur->next) {
        printf(", ");
        print_function(cur->data);
    }
    printf("]\n{length: %lu, head->data: ", list->size);
    list->head != NULL ? print_function(list->head->data) :
                         (void)printf("NULL");
    printf(", tail->data: ");
    list->tail != NULL ? print_function(list->tail->data) :
                         (void)printf("NULL");
    printf("}\n\n");
}

void free_list(linked_list *list, void (*free_data)(void*)) {
	if (list == NULL) {
		return;
	}
	node *cur = list->tail;
	while (cur != NULL) {
		node *prev_node = cur->prev;
		if (free_data != NULL) {
			free_data(cur->data);
		}
		free(cur);
		cur = prev_node;
	}
	free(list);
}
