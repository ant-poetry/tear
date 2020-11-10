//
// Created by w on 2020/11/10.
//

#ifndef TEAR_LINKED_LIST_H
#define TEAR_LINKED_LIST_H



struct linked_list_node_t {
    void * data;
    struct linked_list_node_t * next;
    struct linked_list_node_t * prev;
};


struct linked_list_t {
    int  size;
    struct linked_list_node_t * first;
    struct linked_list_node_t * last;
};

void linked_list_init(struct linked_list_t * list);

void linked_list_add(struct linked_list_t * list,void * data);

void * linked_list_remove(struct linked_list_t * list,void * data);

int linked_list_find(struct linked_list_t * list,void * data);

void * linked_list_find_index(struct linked_list_t * list,int  index);

void * linked_list_change(struct linked_list_t * list,void * old,void * newest);

void * linked_list_change_index(struct linked_list_t * list,int index,void * newest);

void linked_list_release(struct linked_list_t * list);

void linked_list_for_each(struct linked_list_t * list,void (*iterator)(void *));

#endif //TEAR_LINKED_LIST_H
