#include <stdio.h>
#include <stdlib.h>
#include "./stack.h"

void stack_init(Stack *stack) {
  if(STACK_DEBUG) printf("Stack initialized\n");
  stack->head = NULL;
}

void stack_push(Stack *stack, char *data) {
  StackEntry *head = stack->head;
  StackEntry *next = (StackEntry*) malloc(sizeof(StackEntry));
  if(STACK_DEBUG) printf("Pushed %s into stack\n", data);
  next->data = data;
  next->next = head;
  stack->head = next;
}

char * stack_pop(Stack *stack) {
  StackEntry *head = stack->head;
  char *data;
  if(stack->head == NULL) {
    printf("Failed to execute stack_pop: Stack underflow occurred\n");
    return NULL;
  }
  stack->head = head->next;
  data = head->data;
  if(STACK_DEBUG) printf("Popped %s from stack\n", data);
  free(head);
  return data;
}

void stack_print(Stack *stack) {
  StackEntry *next = stack->head;
  while(next != NULL) {
    printf("%s ", next->data);
    next = next->next;
  }
  printf("\n");
}

void stack_clear(Stack *stack) {
  if(STACK_DEBUG) printf("Stack cleared\n");
  while(stack->head != NULL) {
    StackEntry *next = stack->head->next;
    if (stack->head->data != NULL) free(stack->head->data);
    free(stack->head);
    stack->head = next;
  }
}

int main() {
  int isRunning = 1;
  Stack stack; 
  stack_init(&stack);
  printf("(Personal info redacted)\n");
  while(isRunning) {
    printf("메뉴를 선택하세요.\n");
    printf("1. 삽입\n2. 출력\n3. 꺼내기\n4. 모두 삭제\n5. 끝내기\n입력: ");
    int selection;
    scanf("%d", &selection);
    getchar();
    char * buffer, choice;
    switch (selection) {
      case 1:
        buffer = (char*) malloc(256);
        printf("넣을 데이터를 입력해주세요: ");
        gets(buffer);
        stack_push(&stack, buffer);
        break;
      case 2:
        stack_print(&stack);
        break;
      case 3:
        buffer = stack_pop(&stack);
        printf("꺼낸 데이터: %s\n", buffer);
        free(buffer);
        break;
      case 4:
        printf("정말 모두 삭제하시겠습니까? (yn)");
        choice = getchar();
        if (choice == 'y') stack_clear(&stack);
        break;
      case 5:
        isRunning = 0;
        break;
    }
  }
  #ifdef _WIN32
  getchar();
  #endif
}
