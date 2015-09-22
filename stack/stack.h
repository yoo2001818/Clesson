#ifndef __STACK_H__
#define __STACK_H__

#ifndef NULL
#define NULL (0)
#endif

#define STACK_DEBUG 1

typedef struct Stack Stack;
typedef struct StackEntry StackEntry;

struct StackEntry {
  char *data;
  StackEntry *next;
};

struct Stack {
  StackEntry *head;
  // Do I really need to implement tail? It's not necessary.
};

void stack_init(Stack *stack);
void stack_push(Stack *stack, char *data);
char* stack_pop(Stack *stack);
void stack_print(Stack *stack);
void stack_clear(Stack *stack);

#endif
