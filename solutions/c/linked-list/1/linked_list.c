#include "linked_list.h"

struct list_node {
   struct list_node *prev, *next;
   ll_data_t data;
};

struct list {
   struct list_node *first, *last;
};


// constructs a new (empty) list
struct list* list_create(void) {
    struct list* list = malloc(sizeof(struct list));
    if (list == NULL) return NULL; 
	
    list->first = NULL;
    list->last = NULL;
    return list;
}

// counts the items on a list
size_t list_count(const struct list* list) {
    if (list == NULL) return 0;

    size_t count = 0;
    struct list_node* current = list->first;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// inserts item at back of a list
void list_push(struct list* list, ll_data_t item_data) {
    if (list == NULL) {
        printf("hello");
        return;
    }

    struct list_node* n = malloc(sizeof(struct list_node));
    if (n == NULL) return;
	
    n->data = item_data;
	n->next = NULL;
	n->prev = NULL;

    if (list->first == NULL) {
        list->first = list->last = n;
    }
    else {
        list->last->next = n;
        n->prev = list->last;
        list->last = n;
    }
    printf("%d, %d", list->first->data, list->last->data);
}

// removes item from front of a list
ll_data_t list_shift(struct list* list) {
    ll_data_t data = 0;
    if (list == NULL || list->first == NULL) return data;
    if (list->first == list->last) {
        data = list->first->data;
        free(list->first);
        list->first = NULL;
        list->last = NULL;
        return data;
    }
    struct list_node* toRemove = list->first;
    list->first = toRemove->next;
    list->first->prev = NULL;
    data = toRemove->data;
    free(toRemove);
    return data;
}

// removes item from back of a list
ll_data_t list_pop(struct list* list) {
    ll_data_t data = 0;
    if (list == NULL) return data;
	
    printf("%d, %d", list->first->data, list->last->data);
    if (list->first == list->last) {
        data = list->first->data;
        free(list->first);
        list->first = NULL;
        list->last = NULL;
    }
    else {
        struct list_node* toRemove = list->last;
        list->last = toRemove->prev;
        list->last->next = NULL;
        data = toRemove->data;
        free(toRemove);
    }
    return data;
}

// inserts item at front of a list
void list_unshift(struct list* list, ll_data_t item_data) {
    if (list == NULL) return;
    else {
        struct list_node* node = malloc(sizeof(struct list_node));
        if (node == NULL) return;
        node->data = item_data;
        node->prev = NULL;
        node->next = list->first;

        if (list->first == NULL) {
            list->first = list->last = node;
        }
        else {
            list->first->prev = node;
            list->first = node;
        }
    }

}

// deletes a node that holds the matching data
void list_delete(struct list* list, ll_data_t data) {
    if (list == NULL || list->first == NULL) return;
    struct list_node* current = list->first;
    bool has = false;
    while (current != NULL && !has) {
        if (current->data == data) has = true;
        else current = current->next;
    }
    if (!has) { 
	printf("Data not found in the list.\n");
        return; 
    }

    if (list->first == list->last) {
        list->first = list->last = NULL;
    }
    else if (current->prev == NULL) {
        list->first->next->prev = NULL;
        list->first = list->first->next;
    }
    else if (current->next == NULL) {
        list->last->prev->next = NULL;
        list->last = list->last->prev;
    }
    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    free(current);
}

// destroys an entire list
// list will be a dangling pointer after calling this method on it
void list_destroy(struct list* list) {

	if (list == NULL) return;
    while (list->first != NULL) {
        struct list_node* current = list->first;
        list->first = current->next;
        free(current);
    }

}


/*
// removes item from back of a list
ll_data_t list_pop(struct list *list){
    ll_data_t data = 0;
    if(list == NULL){
        return data;
    }
    printf("%d, %d", list->first->data, list->last->data);
    if(list->first == list->last){
        data = list->first->data;
        free(list->first);
        list->first = NULL;
        list->last = NULL;
    }
    else {
        struct list_node *toRemove = list->last;
        list->last = toRemove->prev;
        list->last->next = NULL;
        data = toRemove->data;
        free(toRemove);   
    }
    return data;
}

// inserts item at front of a list
void list_unshift(struct list *list, ll_data_t item_data){
    if(list == NULL) return;
    if(item_data == 0) return;
}


// deletes a node that holds the matching data
void list_delete(struct list *list, ll_data_t data){
    if(list == NULL) return;
    if(data == 0) return;
}

// destroys an entire list
// list will be a dangling pointer after calling this method on it
void list_destroy(struct list *list){
    if(list == NULL) return;
}
*/
