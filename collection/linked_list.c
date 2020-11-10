//
// Created by w on 2020/11/10.
//

#include "linked_list.h"

#include <assert.h>
#include <memory.h>
#include <malloc.h>

void linked_list_init(struct linked_list_t * list) {
    memset(list,0,sizeof(struct linked_list_t));
}

void linked_list_add(struct linked_list_t * list,void * data) {
    assert(list);
    struct linked_list_node_t * node = malloc(sizeof(struct linked_list_node_t));
    memset(node,0,sizeof(struct linked_list_node_t));
    node->data = data;
    if(!list->size) {  //没有数据
        list->first = node;
    } else {
        list->last->next = node;
        node->prev = list->last;
    }
    list->last = node;
    list->size++;
}

void * linked_list_remove(struct linked_list_t * list,void * data) {
    assert(list);
    struct linked_list_node_t * node = list->first;
    while (node) {
        if(node->data == data) {
            struct linked_list_node_t * prev = node->prev;
            struct linked_list_node_t * next = node->next;
            if (!prev) {
                next->prev = NULL;
                list->first = next;
            } else {
                prev->next = next;
                node->prev = NULL;
            }
            if (!next) {
                list->last = prev;
                prev->next = NULL;
            } else {
                next->prev = prev;
                node->next = NULL;
            }
            free(node);
            list->size--;
            return data;
        }
        node = node->next;
    }
    return NULL;
}

int linked_list_find(struct linked_list_t * list,void * data) {
    int index = -1;
    struct linked_list_node_t * node = list->first;
    while (node) {
        index++;
        if(node->data == data) {
            return index;
        }
        node = node->next;
    }
    return -1;
}

void * linked_list_find_index(struct linked_list_t * list,int  index) {
    assert(index > -1);
    assert(list);
    struct linked_list_node_t * node = list->first;
    while (node && (--index) > -1) {
        node = node->next;
    }
    if(node) {
        return node->data;
    }
    return NULL;
}


void * linked_list_change(struct linked_list_t * list,void * old,void * newest) {
    assert(list);
    struct linked_list_node_t * node = list->first;
    while (node) {
        if (node->data == old) {
            node->data = newest;
            return old;
        }
    }
    return NULL;
}

void * linked_list_change_index(struct linked_list_t * list,int index,void * newest) {
    assert(index > -1);
    assert(list);
    struct linked_list_node_t * node = list->first;
    while (node && (--index) > -1) {
        node = node->next;
    }
    if(node) {
        void * old = node->data;
        node->data = newest;
        return old;
    }
    return NULL;
}

void linked_list_release(struct linked_list_t *list) {
    if(list->size) {
        struct linked_list_node_t * node = list->first;
        while (node) {
            struct linked_list_node_t * prev = node;
            node = node->next;
            free(prev);
        }
    }
    list->size = 0;
    list->first = NULL;
    list->last = NULL;
}

void linked_list_for_each(struct linked_list_t *list, void (*iterator)(void *)) {
    assert(iterator);
    assert(list);
    struct linked_list_node_t * node = list->first;
    while (node) {
        iterator(node->data);
        node = node->next;
    }
}
