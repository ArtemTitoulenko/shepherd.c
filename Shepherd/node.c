//
//  node.c
//  Shepherd
//
//  Created by Artem Titoulenko on 7/17/13.
//  Copyright (c) 2013 Artem Titoulenko. All rights reserved.
//

#include "node.h"

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