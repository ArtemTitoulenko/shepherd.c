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
#include "node.h"
#include "common.h"

struct Graph {
  hash_t * nodes;
  int num_nodes, _num_max_nodes;
};
typedef struct Graph graph_t;

graph_t * graph_new();
void graph_free(graph_t * graph);

void graph_add_node(graph_t * graph, char * name, callback cb);
void graph_remove_node(graph_t * graph, char * name);

void graph_node_builds(graph_t * graph, char * node, char * target);

void * graph_eval(graph_t * graph, char * node);

#endif
