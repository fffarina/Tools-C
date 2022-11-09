#include <stdio.h>
#include <stdlib.h>

typedef struct List *List;

struct List{
	int key;
	List next;
	List prev;
};

List init_list(int key) {
	List new_list = (List) malloc(sizeof(List));
       	new_list->key = key;
	new_list->next = NULL;
	new_list->prev = NULL;
	return new_list;
}

List append(List the_list, int key) {
	List copy = the_list;
	List new_member = (List) malloc(sizeof(List));
	new_member->key = key;
	new_member->next = the_list;
	new_member->prev = NULL;
	the_list->prev = new_member;
	return new_member;
}

List pop(List the_list, int key) {
	List copy = the_list;
	while(the_list->key != key) the_list = the_list->next;
	if (the_list->next && the_list->prev){
		List previous = the_list->prev;
		List next = the_list->next;
		previous->next = next;
		next->prev = previous;
		free(the_list);
		return copy;
	}
	else if (!the_list->prev) { 
		List next = the_list->next;
		next->prev = NULL;
		free(the_list);
		return next;
	}
	else if (!the_list->next) {
		List previous = the_list->prev;
		previous->next = NULL;
		free(the_list);
		return copy;
	}
	
}

void show_list(List the_list) {
	while(the_list){
		printf("Key: %d, Prev: %p, Next: %p\n", the_list->key, the_list->prev, the_list->next);
		the_list = the_list->next;
	}
}

void print_list(List the_list) {
	printf("[");
	while(the_list->next) {
		printf("%d, ", the_list->key);
		the_list = the_list->next;
	}
	printf("%d]\n",the_list->key);
}

int list_length(List the_list) {
	int n = 0;
	while(the_list){
		++n;
		the_list = the_list->next;
	}
	return n;
} 
		
List find_key(List the_list, int key) {
	while (the_list) {
		if (the_list->key == key) return the_list;
		else the_list = the_list->next;
	}

	return NULL;
}

void del_list(List lista) {
	while(lista) {
		List next = lista->next;
		free(lista);
		lista = next;
	}
}
