#include <stdio.h>
#include "collection/linked_list.h"
#include "collection/stack.h"


void fi(void *data) {
    printf("%d \n",(int)(*(int *)data));
}

void test_linked_list() {
    struct linked_list_t list;
    linked_list_init(&list);
    int a = 0;
    int b = 1;
    int c = 2;
    linked_list_add(&list,&a);
    linked_list_add(&list,&b);
    linked_list_add(&list,&c);
    b = 100;
    printf("%d \n",(int)(*(int *)linked_list_find_index(&list,0)));
    printf("------------------------------- \n");
    linked_list_for_each(&list,&fi);
    linked_list_remove(&list,&b);
    printf("------------------------------- \n");
    linked_list_for_each(&list,&fi);
    linked_list_release(&list);
}

void test_stack() {
    struct stack_t stack;
    stack_init(&stack);
    int a = 0;
    int b = 1;
    int c = 2;
    stack_push(&stack,&a);
    stack_push(&stack,&b);
    stack_push(&stack,&c);
    printf("%d \n",(int)(*(int *)stack_pop(&stack)));
    printf("%d \n",(int)(*(int *)stack_peek(&stack)));
    printf("%d \n",(int)(*(int *)stack_pop(&stack)));
    printf("%d \n",(int)(*(int *)stack_pop(&stack)));
    stack_release(&stack);
}

int main() {
    test_stack();
    printf("Hello, World!\n");
    return 0;
}


