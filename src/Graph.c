# include "Graph.h"
# include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// private helper function
static Vertex* Vertex_find(Vertex *vertices, int id) {
  Vertex *v;
  int i = 0;
  do {
    v = &vertices[i];
  } while (v -> id != id); 
  return v;
}

Graph *Graph_new(int n) {
  Graph *new_graph = malloc(sizeof(Graph));
  if (!new_graph) return NULL;
  
  new_graph -> numVertices = n;
  new_graph -> numEdges = n;
  
  // allocate enough mem to all the vertex needed  
  Vertex *vertices = malloc(sizeof(Vertex)* n);
  if (!vertices) return NULL;
 
  // init each vertex
  int i = 0;
  while (i < n) {
    vertices[i].id = i;
    vertices[i].outNeighbours = LinkedList_new(); 
    vertices[i].inNeighbours =  LinkedList_new(); 
    i++;
  }

  new_graph -> vertices = vertices; 
  return new_graph;
}

// pre: g is created by Graph_new
void Graph_addEdge(Graph *g, int i, int j) {
  Vertex *verts = g -> vertices;

  Vertex *v_1 =  Vertex_find(verts, i);
  Vertex *v_2 =  Vertex_find(verts, j);
 
  // make sure that the append worked
  // add the in-edge from i to j 
  // add the out-edge form j to i
  assert((LinkedList_append(v_1 -> outNeighbours, v_2) != NULL));
  assert((LinkedList_append(v_2 -> inNeighbours , v_1) != NULL));
}

Graph *Graph_read(const char *filename) {
  printf("Hit 1");
  FILE* filestream = fopen(filename, "r");
  if (!filestream) return NULL;

  char* lineptr = NULL;
  size_t n = 0;

  // get the first line of file, indicating numVertices of new_g
  getline(&lineptr, &n, filestream);
  int g_size = atoi(lineptr);

  Graph* new_g = Graph_new(g_size);
  if (!new_g) return NULL;
 printf("Hit 2");
  // (i,j) = (row, column)
  for (int i = 0; i < g_size; i++) {
    getline(&lineptr, &n, filestream);     
    for (int j = 0; j < g_size; j++) {
      if (lineptr[j] == '1') {
        Graph_addEdge(new_g, i, j);
      } 
    }
  }
  free(lineptr);
  fclose(filestream);
  return new_g;
}

void Graph_delete(Graph *g) {
  assert(g == NULL);
  
  for(int i = 0; i < g -> numVertices; i++) {
    LinkedList_delete(g ->vertices[i].inNeighbours);
    LinkedList_delete(g ->vertices[i].outNeighbours);
  }
  free(g -> vertices);
}

void Graph_print(Graph *g) {
  printf("numVertices: %i\n numEdges: %i\n", g->numVertices, g->numEdges);
  // 
  // Vertex *vertices = g -> vertices;
  //
  // for (int i = 0; i < g -> numVertices; i++) {
  //   LinkedList *l_out = vertices[i] . outNeighbours;
  //   LinkedList *l_in = vertices[i] . inNeighbours;
  // 
  //
  //   LinkedListNode *current = l_in -> head; 
  //   for (int j = 0; j < l_in -> size; j++) {
  //     Vertex  *info = current -> data;
  //     printf("%i ", info -> id); 
  //     *current = *current -> next;
  //   }
  //   printf("\n");  
  //
  //    LinkedListNode *current2 = l_out -> head; 
  //   for (int k = 0; k < l_in -> size; k++) {
  //     Vertex  *info2 = current2 -> data;
  //     printf("%i ", info2 -> id); 
  //     *current2 = *current2 -> next;

}





