#include <stdio.h>
#include <stdlib.h>

struct KT {
  int age;
  struct KT * next;
};

int main() {
  struct KT *ap, *hp;
  hp = (struct KT *) malloc(sizeof(struct KT));
  ap = hp;
  for (int i = 0; i < 3; ++i) {
    scanf("%d", &ap->age);
    if (i < 2) {
      ap->next = (struct KT *) malloc(sizeof(struct KT));
      ap = ap->next;
    } else {
      ap = NULL;
    }
  }
  ap = hp;
  while (ap != NULL) {
    printf("%d ", ap->age);
    struct KT * next = ap->next;
    free(ap);
    ap = next;
  }
  printf("\n");
}
