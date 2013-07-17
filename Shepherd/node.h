//
//  node.h
//  Shepherd
//
//  Created by Artem Titoulenko on 7/17/13.
//  Copyright (c) 2013 Artem Titoulenko. All rights reserved.
//

#ifndef Shepherd_node_h
#define Shepherd_node_h

#include <stdio.h>
#include <stdlib.h>

#include "common.h"

struct Node {
  char * name;
  callback cb;
  struct Node ** parents;
  int num_parents, _num_max_parents;
};
typedef struct Node node_t;

node_t * node_new(char * name, callback cb);
void node_free(node_t * target);

#endif
