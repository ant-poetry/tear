//
// Created by w on 2020/11/10.
//

#ifndef TEAR_STACK_H
#define TEAR_STACK_H

struct stack_node_t {
    void * data;
    struct stack_node_t * next;
};

struct stack_t {
    struct stack_node_t * top;
};


void stack_init(struct stack_t * stack);

void stack_push(struct stack_t * stack,void * data);

void * stack_pop(struct stack_t * stack);

void * stack_peek(struct stack_t * stack);

void stack_release(struct stack_t * stack);


#endif //TEAR_STACK_H
