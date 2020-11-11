//
// Created by w on 2020/11/11.
//

#ifndef TEAR_BINARY_SEARCH_TREE_H
#define TEAR_BINARY_SEARCH_TREE_H


#include "../util/util.h"

struct binary_search_tree_node_t {
    void * data;
    struct binary_search_tree_node_t * left;
    struct binary_search_tree_node_t * right;
    struct binary_search_tree_node_t * parent;
};

struct binary_search_tree_t {
    comparator comp;
    struct binary_search_tree_node_t * root;
};

void binary_search_tree_init(struct binary_search_tree_t * tree,comparator  comp);

void binary_search_tree_release(struct binary_search_tree_t * tree);

int binary_search_tree_add(struct binary_search_tree_t * tree,void * data);

void binary_search_tree_remove(struct binary_search_tree_t * tree,void * data);

int binary_search_tree_find(struct binary_search_tree_t * tree,void * data);

void binary_search_tree_for_each(struct binary_search_tree_t * tree,void (*itr) (void *));

#endif //TEAR_BINARY_SEARCH_TREE_H
