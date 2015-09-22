#include <stdio.h>

int main() {
  FILE * output = fopen("dic.txt", "w");
  for(int i = 0; i < 10000; ++i) {
    fprintf(output, "%04d\n", i);
  }
  fclose(output);
}
