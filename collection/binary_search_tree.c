//
// Created by w on 2020/11/11.
//

#include "binary_search_tree.h"
#include <assert.h>
#include <memory.h>
#include <malloc.h>

struct binary_search_tree_node_t * create_binary_search_tree_node(struct binary_search_tree_node_t * parent,void * data) {
     struct binary_search_tree_node_t * node = malloc(sizeof(struct binary_search_tree_node_t));
     memset(node,0,sizeof(struct binary_search_tree_node_t));
     node->data = data;
    node->parent = parent;
    return node;
}

void binary_search_tree_init(struct binary_search_tree_t *tree, comparator comp) {
    assert(tree);
    assert(comp);
    memset(tree,0,sizeof(struct binary_search_tree_t));
    tree->comp = comp;
}


void release_sub_binary_search_tree_node(struct binary_search_tree_node_t *node) {
    if (!node) {
        return;
    }
    if (node->left || node->right) {
        release_sub_binary_search_tree_node(node->left);
        release_sub_binary_search_tree_node(node->right);
    }
    free(node);
}

void binary_search_tree_release(struct binary_search_tree_t *tree) {
    release_sub_binary_search_tree_node(tree->root);
    tree->root = NULL;
}

int binary_search_tree_add(struct binary_search_tree_t *tree, void *data) {
    assert(tree);
    assert(data);
    if (!tree->root) {
        tree->root = create_binary_search_tree_node(NULL,data);
    } else {
        struct binary_search_tree_node_t * node = tree->root;
        while (node) {
            int comp = (tree->comp)(node->data,data);
            if(comp == 0) {
                return 2;
            } else if (comp > 0) {
                if(!node->left) {
                    break;
                }
                node = node->left;
            } else {
                if(!node->right) {
                    break;
                }
                node = node->right;
            }
        }
        if(node) {
            int comp = (tree->comp)(node->data,data);
            if(comp > 0) {
                node->left = create_binary_search_tree_node(node,data);
            } else {
                node->right = create_binary_search_tree_node(node,data);
            }
            return 1;
        }
    }
    return 0;
}

void binary_search_tree_remove(struct binary_search_tree_t *tree, void *data) {
}

int binary_search_tree_find(struct binary_search_tree_t *tree, void *data) {
    return 0;
}

void binary_search_tree_for_each(struct binary_search_tree_t *tree, void (*itr)(void *)) {
}

