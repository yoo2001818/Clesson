#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void list_init(List * list) {
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

void list_add_last(List * list, char * data) {
  // Replace tail with the new entry
  ListEntry * tail = list->tail;
  ListEntry * newEntry = (ListEntry *) malloc(sizeof(ListEntry));

  newEntry->data = data;
  newEntry->next = NULL;

  if (tail != NULL) {
    tail->next = newEntry;
  } else {
    list->head = newEntry;
  }
  list->tail = newEntry;
  list->size ++;
}

void list_add_first(List * list, char * data) {
  // Replace head with the new entry
  ListEntry * head = list->head;
  ListEntry * newEntry = (ListEntry *) malloc(sizeof(ListEntry));

  newEntry->data = data;
  newEntry->next = head;

  if (head == NULL) list->tail = newEntry;
  list->head = newEntry;
  list->size ++;
}

void list_add(List * list, int pos, char * data) {
  if (list->size <= pos) pos = list->size - 1;
  if (pos == 0) return list_add_first(list, data);
  ListEntry * parent = NULL;
  ListEntry * current = list->head;
  for (int index = 0; index < pos; ++index) {
    parent = current;
    current = current->next;
  }
  // TODO Reached target
}

void list_delete(List * list, int pos) {

}

void list_clear(List * list) {

}

void list_replace(List * list, int pos, char * data) {
  
}
