#include <stdio.h>

struct KT {
  int age;
  struct KT * next;
};

int main() {
  struct KT a = {10}, b = {20}, c = {30};
  struct KT *ap;
  ap = &c;
  c.next = &b;
  b.next = &a;
  a.next = NULL;
  while(ap != NULL) {
    printf("%3d", ap->age);
    ap = ap->next;
  }
  printf("\n");
}
