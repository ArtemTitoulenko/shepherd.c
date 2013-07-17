//
//  graph.h
//  Shepherd
//
//  Created by Artem Titoulenko on 7/17/13.
//  Copyright (c) 2013 Artem Titoulenko. All rights reserved.
//

#ifndef Shepherd_graph_h
#define Shepherd_graph_h

#include <stdio.h>
#include <stdlib.h>

#include "deps/hash.h"

typedef void* (*callback)(void*);

struct Graph {
  hash_t * nodes;
  int num_nodes, _num_max_nodes;
};
typedef struct Graph graph_t;

struct Node {
  char * name;
  callback cb;
  struct Node ** parents;
  int num_parents, _num_max_parents;
};
typedef struct Node node_t;


node_t * node_new(char * name, callback cb) {
  node_t * temp = malloc(sizeof(node_t));
  temp->name = name;
  temp->cb = cb;
  temp->num_parents = 0;
  temp->_num_max_parents = 4;
  temp->parents = calloc(temp->_num_max_parents, sizeof(node_t *));
  return temp;
}

void node_free(node_t * target) {
  node_t * node;
  
  for (int i = target->num_parents; i >= 0; node = target->parents[i], i--) {
    printf("deleting parent: %i\n", i);
    node_free(node);
  }
  
  free(target->name);
  free(target);
}

graph_t * graph_new() {
  graph_t * graph = malloc(sizeof(graph_t));
  graph->num_nodes = 0;
  graph->_num_max_nodes = 4;
  graph->nodes = calloc(graph->_num_max_nodes, sizeof(node_t *));
  return graph;
}

void graph_free(graph_t * graph) {  
  hash_each_val(graph->nodes, {
    free(val);
  });
  
  free(graph);
}

void graph_add_node(graph_t * graph, char * name, callback cb) {
  node_t * node = node_new(name, cb);
  hash_set(graph->nodes, name, node);
}

void graph_remove_node(graph_t * graph, char * name) {
  node_t * node = hash_get(graph->nodes, name);
  node_free(node);
  hash_del(graph->nodes, name);
}

void graph_node_builds(graph_t * graph, char * node, char * target) {
  /* todo(artem): finish this implementation */
}

#endif
