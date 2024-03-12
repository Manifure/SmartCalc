#ifndef STACK_H

#define MAX_SIZE 256

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double items[MAX_SIZE];
  int top;  // Индекс вершины стека
} Stack;

void initializeStack(Stack *stack);
int isEmpty(Stack *stack);
int isFull(Stack *stack);
void push(Stack *stack, double value);
double pop(Stack *stack);
double peek(Stack *stack);

#endif