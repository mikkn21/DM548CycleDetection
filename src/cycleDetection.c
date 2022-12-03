# include "cycleDetection.h"
# include "LinkedList.h"
# include "Graph.h"
#include <stdio.h>
#include <stdlib.h>




// private helper function
static LinkedList *list_s(Vertex *vertices, int n) {
  LinkedList *s = LinkedList_new();
  int i = 0;
  while (i < n) {
    if (vertices[i].inNeighbours -> size == 0) {
      LinkedList_append(s, &vertices[i]);
    }
    i++;
  }
  return s;
}

// private helper function
// remove v from u's outNeighbours
// remove u from v's inNeighbours
static void remove_edge(Vertex *u, Vertex *v) {
  // printf("Looking at Vertex: %i & %i\n", u -> id, v -> id);

  LinkedList_remove(u -> outNeighbours, LinkedList_find(u -> outNeighbours, v));
  LinkedList_remove(v -> inNeighbours, LinkedList_find(v -> inNeighbours, u));
}


void cycleDetection(Graph *g) {
  LinkedList *L = LinkedList_new();
  LinkedList *S = list_s(g -> vertices, g -> numVertices);

  while (S -> size > 0) {
    Vertex *u = LinkedList_popFront(S);   
    LinkedList_append(L, u);
  
    LinkedList *out_list_u = u -> outNeighbours;

    LinkedListNode *next;	
    for(LinkedListNode *node = out_list_u->head; node; node = next) {
      Vertex *current_v = node -> data;
      if (current_v -> inNeighbours -> size == 1) {
          LinkedList_append(S, current_v);
      } 
      next = node->next;
      remove_edge(u, current_v);
      g -> numEdges--;
    }
  }
  if (g -> numEdges > 0) {
    printf("CYCLE DETECTED!\n");
  } else {
    LinkedListNode *n = L -> head;
    while (n != NULL) {
      Vertex *v_id = n -> data;
      printf("%i, ", v_id -> id );
      n = n -> next;
    }
    printf("\n");
  }
  LinkedList_delete(L);
  LinkedList_delete(S);
}
