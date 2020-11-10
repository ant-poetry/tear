//
// Created by w on 2020/11/10.
//

#include <memory.h>
#include <malloc.h>
#include <assert.h>
#include "stack.h"

void stack_init(struct stack_t *stack) {
    assert(stack);
    memset(stack,0,sizeof(struct stack_t));
}

void stack_push(struct stack_t *stack, void *data) {
    assert(stack);
    struct stack_node_t * node = malloc(sizeof(struct stack_node_t));
    memset(node,0,sizeof(struct stack_node_t));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
}

void* stack_pop(struct stack_t *stack) {
    assert(stack);
    struct stack_node_t * node = stack->top;
    if(node) {
        void * data = node->data;
        stack->top = node->next;
        node->next = NULL;
        free(node);
        return data;
    }
    return NULL;
}

void stack_release(struct stack_t *stack) {
    struct stack_node_t * node = stack->top;
    while (node) {
        struct stack_node_t * tmp = node;
        node = node->next;
        free(tmp);
    }
    stack->top = NULL;
}

void *stack_peek(struct stack_t *stack) {
    assert(stack);
    struct stack_node_t * node = stack->top;
    return node ? node->data : NULL;
}
