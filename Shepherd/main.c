//
//  main.c
//  Shepherd
//
//  Created by Artem Titoulenko on 7/17/13.
//  Copyright (c) 2013 Artem Titoulenko. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

int important_value = 1;
void * pre_req(void * data) {
  return &important_value; // or something
}

void * do_work(void * data) {
  if (*(int *)data == 1) {
    return 1;
  } else {
    return 0;
  }
}

int main(int argc, const char ** argv) {
  graph_t * graph = malloc(sizeof(graph_t));
  
   graph_add_node(graph, "bar", pre_req);
   
   graph_add_node(graph, "foo", do_work);
   graph_node_builds(graph, "foo", "bar");
  
   printf("graph_eval(graph, 'foo'): %i\n", *(int *)graph_eval(graph, "foo")); // #=> 1
   
  free(graph);
  return 0;
}

