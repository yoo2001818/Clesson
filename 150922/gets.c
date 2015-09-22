#include <stdio.h>

int main() {
  FILE * input = fopen("data.csv", "r");
  char buffer[512];
  if (input == NULL) {
    printf("Cannot open data.csv\n");
    return 1;
  }
  while (fgets(buffer, sizeof(buffer), input)) {
    puts(buffer);
  }
  fclose(input);
}
