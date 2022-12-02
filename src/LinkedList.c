# include "LinkedList.h"

#include <assert.h>
# include <stdio.h>
# include <stdlib.h>



LinkedList *LinkedList_new() {
   LinkedList *new_ll = malloc(sizeof(LinkedList));
   if (!new_ll) return NULL;

    new_ll -> head =  NULL;
    new_ll -> tail = NULL;
    new_ll -> size = 0;
    return new_ll;
}

// Shamelessly stolen from Jakob
// no reason to reinvent the wheel
void LinkedList_delete(LinkedList *ll){
  assert(ll);
  LinkedListNode *next;	
  for(LinkedListNode *node = ll->head; node; node = next) {
    next = node->next;
    free(node);
  }
  free(ll);


}

LinkedListNode *LinkedList_append(LinkedList *ll, void *elem) {
    LinkedListNode *node = malloc(sizeof(LinkedListNode));
    if (!node) return NULL;
    
    // sets the new node
    node -> next = NULL;
    node -> prev = ll -> tail;
    node -> data = elem;
   
    // If the list is empty set new node to head
    if (ll -> head == NULL) {
        ll -> head = node;
        ll -> tail = node;
    }else { // if list is not empty append new node
        ll -> tail -> next = node;
        ll -> tail = node;
    }
    ll -> size++;
    
    return node;

}

void *LinkedList_popFront(LinkedList *ll) {
    LinkedListNode *h = ll -> head;
   
    // only one node in  the list
    if (h -> next == NULL) {
        ll -> head = NULL;
        ll -> tail = NULL;
        ll -> size--;
    }else { // more than one node in the list
        ll -> head = h -> next;
        ll -> size--;
    }
    return h;
}

LinkedListNode *LinkedList_find(LinkedList *ll, void *elem) {
    LinkedListNode *next_node = ll -> head;
    // stop if the next_node is NULL or if elem is found
    while ((next_node != NULL) & (next_node -> data != elem)) {
        next_node = next_node -> next;
    }
    // if next_node == NULL, then the elem wasn't in the list
    if (next_node == NULL) return NULL;
    
    // if next_node exist, we found the node that points to the elem
    return next_node;
}


void *LinkedList_remove(LinkedList *ll, LinkedListNode *node) {
    void *r_data;
    // if node -> next == NULL it's tail or head/tail of a tree of size 1
    if (node -> next == NULL) {
        r_data = node -> data;
    } else { // node has a prev & next in this case
        r_data = node -> data;
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
    }
    free(node);
    ll -> size--;
    return r_data;
}





