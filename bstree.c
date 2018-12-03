#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bstree.h"

//fuctions not mentioned in bstree.h
void inorder_trav(BStree_node *current) ;
static void tree_free(BStree_node *bt);
void BStree_insert(BStree_node *node_ptr, Key key, Data data);
BStree_node *new_node(Key key, Data data);

//Allocate memory of type BStree node*, set the value to NULL, and return a pointer to the allocated memory
BStree bstree_ini (void)
{

  BStree bst;
//dynamically allocate memory to bst 
  bst = (BStree) malloc (sizeof (BStree_node *));
  *bst = NULL;
  return bst;
}


//pointer to tree node from key and data
BStree_node *new_node(Key key, Data data)
{
    BStree_node *node_p;
    node_p = (BStree_node *) malloc(sizeof(BStree_node));
    node_p->key = key;
    node_p->data = data;
    node_p->left = NULL;
    node_p->right = NULL;
    return node_p;
}

//Insert data with key into bst
void bstree_insert(BStree bst, Key key, Data data) {
    if (*bst == NULL){
        *bst = new_node(key,data);
    }
    //inserts using node
    BStree_insert(*bst, key, data);
}

//inserts using BStree node recursively adds
void BStree_insert(BStree_node *node_ptr, Key key, Data data){
	//if comparison is less than 0, add to left 
    if ( key_comp(key, node_ptr->key) < 0 )
        if (node_ptr->left==NULL){
            node_ptr->left = new_node(key,data);
        }
        else{
            BStree_insert(node_ptr->left, key, data);
        }
    //if comparison is more than 0, add to right
    else if ( key_comp(key, node_ptr->key) > 0 ){
        if (node_ptr->right==NULL){
            node_ptr->right = new_node(key,data);
        }
        else{
            BStree_insert(node_ptr->right, key, data);
        }
    }
    
}


//If key is in bst, return key’s associated data. If key is not in bst, return NULL.
Data bstree_search(BStree bst, Key key){
        if((*bst) == NULL){
            return NULL;
        }
        if (key_comp(key, (*bst)->key) == 0){
            return (*bst)->data;
        }
	//search left if comp is less than 0
        else if (key_comp(key, (*bst)->key) < 0){
            BStree bst_left=&(*bst)->left;
            return bstree_search(bst_left, key);
        }
	//search right if comp is greater than 0
        else if (key_comp(key, (*bst)->key) > 0){
            BStree bst_right = &(*bst)->right;
            return bstree_search(bst_right, key);
        }
}

//In order traversal of bst and print each node’s key and data.
void bstree_traversal(BStree bst)
{
// use node as an input to traversal function
   BStree_node *current = *bst;
   inorder_trav(current);
}

//use node to traverse
void inorder_trav(BStree_node *current) 
{ 
//if current isn't null traverse accordingly 
    if (current != NULL) 
    { 
        inorder_trav(current->left); 
        key_print(current->key);
        data_print(current->data);
        inorder_trav(current->right); 
    } else{
        ;
    }
}


//frees memory of tree
static void tree_free(BStree_node *bt) { 
    if ( bt == NULL ) 
        return; 
    tree_free(bt->left); 
    tree_free(bt->right);
    free(bt->key);
    free(bt->data);
    free(bt); 
}

//Free all the dynamically allocated memory of bst. calls tree_free
void bstree_free(BStree bst) { 
    tree_free(*bst);
    free(bst);
}

