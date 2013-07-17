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

int main(int argc, const char ** argv) {
  graph_t * graph = malloc(sizeof(graph_t));
  
  /* ideal API
   
   void * pre_req(void * data) {
   return &1; // or something
   }
   
   void * do_work(void * data) {
     if ((int *)data == 1) {
       return true;
     } else {
       return false
     }
   }
   
   graph->add_node("bar", pre_req);
   
   graph->add_node("foo", do_work)
     ->using("bar");
   
   printf("graph->eval('foo'): %i\n", graph->eval('foo')); // #=> 1
   
   */

  free(graph);
  return 0;
}

