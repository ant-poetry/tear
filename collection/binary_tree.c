//
// Created by w on 2020/11/11.
//

#include "binary_tree.h"


#include <assert.h>
#include <malloc.h>
#include <memory.h>

struct binary_tree_node_t * create_node(struct binary_tree_node_t * parent,void * data) {
   struct binary_tree_node_t * node =  malloc(sizeof(struct binary_tree_node_t));
   memset(node,0,sizeof(struct binary_tree_node_t));
   node->data = data;
   node->parent = parent;
   return node;
}

void release_sub_node(struct binary_tree_node_t *node);

void node_for_each(struct binary_tree_node_t *node, void (*itr)(void *));

struct binary_tree_node_t *node_find(struct binary_tree_node_t *node, void *data) {
    if (!node) {
        return NULL;
    }
    if (node->data == data) {
        return node;
    }
    struct binary_tree_node_t * sub = node_find(node->left,data);
    if (!sub) {
        sub = node_find(node->right,data);
    }
    return sub;
}

void binary_tree_init(struct binary_tree_t *tree) {
    memset(tree,0,sizeof(struct binary_tree_t));
}

void binary_tree_release(struct binary_tree_t *tree) {
    release_sub_node(tree->root);
    tree->root =NULL;
}

void release_sub_node(struct binary_tree_node_t *node) {
    if (!node) {
        return;
    }
    if (node->left || node->right) {
        release_sub_node(node->left);
        release_sub_node(node->right);
    }
    free(node);
}


void node_sub_add(struct binary_tree_node_t *node, void *data) {
    assert(node);
    if (!node->left) {
        node->left = create_node(node,data);
    } else if(!node->right) {
        node->right = create_node(node,data);
    } else {
        int l = 0,r = 0;
        struct binary_tree_node_t * tmp = node->left;
        while (tmp) {
            l++;
            tmp = tmp->right;
        }
        tmp = node->right;
        while (tmp) {
            r++;
            tmp = tmp->left;
        }
        if (r != l) {
            node_sub_add(node->right,data);
        } else {
            node_sub_add(node->left,data);
        }
    }
}

void binary_tree_add(struct binary_tree_t *tree, void *data) {
    assert(tree);
    assert(data);
    if (!tree->root) {
        tree->root = create_node(NULL,data);
    } else {
        node_sub_add(tree->root,data);
    }
}

int binary_tree_remove(struct binary_tree_t *tree, void *data) {
    assert(tree);
    assert(data);
    struct binary_tree_node_t * node = node_find(tree->root,data);
    if (!node) {
        return 0;
    }
    if (!node->left) {  //没有左子树
        if(node->parent) {
            if (node == node->parent->left) {
                node->parent->left = node->right;
            } else {
                node->parent->right = node->right;
            }
            if (node->right) {
                node->right->parent = node->parent;
            }
        } else {
            //没有父级的必定是root
            tree->root = node->right;
            tree->root->parent = NULL;
        }
    } else if(!node->right) {  //没有右子树
        if(node->parent) {
            if (node == node->parent->left) {
                node->parent->left = node->left;
            } else {
                node->parent->right = node->left;
            }
            if(node->left) {
                node->left->parent = node->parent;
            }
        } else {
            //没有父级的必定是root
            tree->root = node->left;
            tree->root->parent = NULL;
        }
    } else {
        struct binary_tree_node_t * sub = node->left;
        while (1) {
            while (sub->right) {
                sub = sub->right;
            }
            if (!sub->left) {
                break;
            }
            sub = sub->left;
        }
        node->data = sub->data;
        if (sub->parent->left == sub) {
            sub->parent->left = NULL;
        } else {
            sub->parent->right = NULL;
        }
        sub->parent = NULL;
        node = sub;
    }
    free(node);
    return 1;
}

int binary_tree_find(struct binary_tree_t *tree, void *data) {
    assert(tree);
    assert(data);
    struct binary_tree_node_t * node = node_find(tree->root,data);
    if (node) {
        return 1;
    }
    return 0;
}

void binary_tree_for_each(struct binary_tree_t *tree, void (*itr)(void *)) {
    assert(tree);
    assert(itr);
    node_for_each(tree->root,itr);
}

void node_for_each(struct binary_tree_node_t *node, void (*itr)(void *)) {
    if (!node) {
        return;
    }
    itr(node->data);

    node_for_each(node->left,itr);
    node_for_each(node->right,itr);
}


