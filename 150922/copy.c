#include <stdio.h>

int main() {
  FILE * istream, * ostream;
  char buf;
  if ((istream = fopen("input.txt", "r")) == NULL) {
    printf("파일이 존재하지 않습니다.");
    return 1;
  }
  ostream = fopen("output.txt", "w");
  while ((buf = fgetc(istream)) != EOF) {
    fputc(buf, ostream);
  }
  fclose(istream);
  fclose(ostream);
}
