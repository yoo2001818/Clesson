#include <stdio.h>

struct Student {
  int score[3];
  int total;
  char name[100];
  int id;
};

int main() {
  FILE * input = fopen("data.csv", "r");
  struct Student students[3];
  if (input == NULL) {
    printf("Cannot open data.csv\n");
    return 1;
  }
  for (int i = 0; i < 3; ++i) {
    struct Student * student = &(students[i]);
    fscanf(input, "%d%s", &(student->id), student->name);
    student->total = 0;
    for (int j = 0; j < 3; ++j) {
      fscanf(input, "%d", &(student->score[j]));
      student->total += student->score[j];
    }
    printf("%3d%15s%5d%5d%5d%6d\n", student->id, student->name,
      student->score[0], student->score[1], student->score[2], student->total);
  }
  fclose(input);
}
