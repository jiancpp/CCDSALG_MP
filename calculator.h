#ifndef CALCULATOR_H

#define CALCULATOR_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char String[256];
typedef struct  {
    String data;
    LinkedListNode *ptr;
} LinkedListNode;

#endif