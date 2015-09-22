#ifndef __STACK_H__
#define __STACK_H__

#ifndef NULL
#define NULL (0)
#endif

#define STACK_DEBUG 1

typedef struct List List;
typedef struct ListEntry ListEntry;

struct ListEntry {
  char * data;
  ListEntry * next;
};

struct List {
  ListEntry * head;
  ListEntry * tail;
  int size;
};

void list_init(List * list);

void list_add_last(List * list, char * data);
void list_add_first(List * list, char * data);
void list_add(List * list, int pos, char * data);

void list_delete(List * list, int pos);
void list_clear(List * list);
void list_replace(List * list, int pos, char * data);

bool list_has_item(List * list, char * data);
char * list_get_entry(List * list, int pos);

bool list_is_empty(List * list);
bool list_is_full(List * list);

void list_display(List * list);
#endif
