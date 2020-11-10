//
// Created by ant_poetry on 2020/11/10.
//

#ifndef TEAR_QUEUE_H
#define TEAR_QUEUE_H

struct queue_node_t {
    void * data;
    struct queue_node_t * next;
    struct queue_node_t * prev;
};

struct queue_t {
    struct queue_node_t * head;
    struct queue_node_t * tail;
};

void queue_init(struct queue_t * queue);

void queue_release(struct queue_t *queue);

void queue_push(struct queue_t *queue,void * data);

void * queue_pop(struct queue_t *queue);

void * queue_peek(struct queue_t * queue);

#endif //TEAR_QUEUE_H
