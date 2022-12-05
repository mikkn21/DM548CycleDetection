# include "Graph.h"
# include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

Graph *Graph_new(int n) {
  Graph *new_graph = malloc(sizeof(Graph));
  if (!new_graph) return NULL;
  
  new_graph -> numVertices = n;
  new_graph -> numEdges = 0;
  
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
  
  // make sure that the append worked
  // add the in-edge from i to j 
  // add the out-edge form j to i
  assert((LinkedList_append(verts[i].outNeighbours, &verts[j]) != NULL));
  assert((LinkedList_append(verts[j].inNeighbours , &verts[i]) != NULL));
}

Graph *Graph_read(const char *filename) {
  FILE* filestream = fopen(filename, "r");
  if (!filestream) return NULL;

  char* lineptr = NULL;
  size_t n = 0;

  // get the first line of file, indicating numVertices of new_g
  getline(&lineptr, &n, filestream);
  int g_size = atoi(lineptr);

  Graph* new_g = Graph_new(g_size);
  if (!new_g) return NULL;
  // (i,j) = (row, column)
  for (int i = 0; i < g_size; i++) {
    getline(&lineptr, &n, filestream);     
    for (int j = 0; j < g_size; j++) {
      if (lineptr[j] == '1') {
        Graph_addEdge(new_g, i, j);
        new_g -> numEdges++;
      } 
    }
  }
  free(lineptr);
  fclose(filestream);
  return new_g;
}

void Graph_delete(Graph *g) {
  printf("NUMVERTEX: %i\n", g -> numVertices);
  if (g -> numVertices > 0) {
    Vertex *verts = g -> vertices;  
    int i = 0;
    while ( i < g -> numVertices) {
      Vertex current_vert = verts[i];
      printf("CURRENT AT VERTEX: %i\n", i);
      LinkedList_delete(current_vert . outNeighbours); 
      LinkedList_delete(current_vert . inNeighbours); 
      i++;
    }
  }
  free(g -> vertices);
  free(g);
}

void Graph_print(Graph *g) {
  printf("*****************************\n");
  printf("numVertices: %i\nnumEdges: %i\n", g->numVertices, g->numEdges);
  int i = 0;
  printf("id: \tout: \tin:\n");
  while (i < g -> numVertices) {
    printf("%i \t%i \t%i\n", i, g->vertices[i].outNeighbours -> size, g->vertices[i].inNeighbours -> size );
    i++;
  }
  printf("*****************************\n");
}
