//
// Created by ant_poetry on 2020/11/10.
//

#include "queue.h"

#include <malloc.h>
#include <assert.h>
#include <memory.h>

void queue_init(struct queue_t *queue) {
    memset(queue,0,sizeof(struct queue_t));
}

void queue_release(struct queue_t *queue) {
    while (queue_peek(queue)) {
        queue_pop(queue);
    }
    queue->head = NULL;
    queue->tail = NULL;
}

void queue_push(struct queue_t *queue, void *data) {
    struct queue_node_t * node = malloc(sizeof(struct queue_node_t));
    memset(node,0,sizeof(struct queue_node_t));
    node->data = data;
    if(queue->tail) {
        queue->tail->next = node;
        node->prev = queue->tail;
        queue->tail = node;
    } else {
        queue->tail = queue->head = node;
    }
}

void *queue_pop(struct queue_t *queue) {
    assert(queue);
    struct queue_node_t * node = queue->head;
    if (node) {
        void * data = node->data;
        queue->head = node->next;
        if(!queue->head) {
            queue->tail = NULL;
        } else {
            queue->head->prev = NULL;
        }
        node->next = NULL;
        free(node);
        return data;
    }
    return NULL;
}

void *queue_peek(struct queue_t *queue) {
    return queue->head ?  queue->head->data : NULL;
}
