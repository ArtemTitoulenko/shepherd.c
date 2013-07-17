//
//  graph.c
//  Shepherd
//
//  Created by Artem Titoulenko on 7/17/13.
//  Copyright (c) 2013 Artem Titoulenko. All rights reserved.
//

#include "graph.h"

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
  hash_set(graph->nodes, name, node); /* todo(artem): there are some errors here, investigate */
}

void graph_remove_node(graph_t * graph, char * name) {
  node_t * node = hash_get(graph->nodes, name);
  node_free(node);
  hash_del(graph->nodes, name);
}

void graph_node_builds(graph_t * graph, char * node, char * target) {
  /* todo(artem): finish this implementation */
}

void * graph_eval(graph_t * graph, char * node) {
  /* todo(artem): finish this implementation */
  return 1;
}