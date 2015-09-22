#include <stdio.h>

struct KT {
  int age;
  struct KT * next;
};

int main() {
  struct KT m, n;
  struct KT *ap = &n;
  ap->age = 10;
  ap->next = &m;
  m.age = 20;
  m.next = NULL;
  printf("%3d", ap->age);
  printf("%3d\n", ap->next->age);
}
