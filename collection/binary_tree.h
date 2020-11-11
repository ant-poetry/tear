//
// Created by w on 2020/11/11.
//

#ifndef TEAR_BINARY_TREE_H
#define TEAR_BINARY_TREE_H

struct binary_tree_node_t {
    void * data;
    struct binary_tree_node_t * parent;
    struct binary_tree_node_t * left;
    struct binary_tree_node_t * right;
};

struct binary_tree_t {
    struct binary_tree_node_t * root;
};


void binary_tree_init(struct binary_tree_t * tree);

void binary_tree_release(struct binary_tree_t * tree);

void binary_tree_add(struct binary_tree_t * tree,void * data);

int binary_tree_remove(struct binary_tree_t * tree,void * data);

int binary_tree_find(struct binary_tree_t * tree,void * data);

void binary_tree_for_each(struct binary_tree_t * tree,void (*itr) (void *));

#endif //TEAR_BINARY_TREE_H
