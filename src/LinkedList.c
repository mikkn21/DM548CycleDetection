# include "LinkedList.h"
#include "Graph.h"

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
    Vertex *id = node -> data;
    free(node -> data);
    free(node);
  }
  free(ll);


}

LinkedListNode *LinkedList_append(LinkedList *ll, void *elem) {
    LinkedListNode *node = malloc(sizeof(LinkedListNode));
    if (!node) return NULL;
   
    // If the list is empty set new node to head
    if (ll -> head == NULL) {
        ll -> head = node;
        ll -> tail = node;
	node -> prev = NULL;
    }else { // if list is not empty append new node
        ll -> tail -> next = node;
	node -> prev = ll -> tail;
        ll -> tail = node;
    }
    // sets the new node
    node -> next = NULL;
    node -> data = elem;

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
    return h -> data;
}


LinkedListNode *LinkedList_find(LinkedList *ll, void *elem) {
  assert(ll -> head); 
  LinkedListNode *next_node = ll -> head;

  int i = 0;
  while (i < ll -> size) {
    if (next_node -> data  == elem) {
      return next_node;
    }
    i++; 
    next_node = next_node -> next;
  }   
  return NULL;
}

void *LinkedList_remove(LinkedList *ll, LinkedListNode *node) {
  assert(node);
  void *data;

  // if node -> next == NULL it's tail or head/tail of a tree of size 1 
  if (node -> next == NULL) {
    data = node -> data;
    
    // case 1: head/tail of a tree of size 1
    if (ll -> head == node) {
      ll -> head = NULL;
      ll -> tail = NULL;
    } else { // case 2: node is tail
      ll -> tail = node -> prev;
      node -> prev -> next = NULL;
    }
  } else { // node is head or has prev & next
    data = node -> data;
    // case 1: node is head = no prev
    if (ll -> head == node) {
      ll -> head = node -> next;
    } else { // case 2: has prev & next
      node -> prev -> next = node -> next;
      node -> next -> prev = node -> prev;
    }
  } 
  free(node);
  ll -> size--;
  return data;
}





