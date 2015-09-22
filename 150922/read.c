#include <stdio.h>
// Why
//#include <windows.h>

int main() {
  FILE * fstream;
  char buf;
  if ((fstream = fopen("a.txt", "r")) == NULL) {
    printf("파일이 존재하지 않습니다.");
    return 1;
  }
  while ((buf = fgetc(fstream)) != EOF) {
    putchar(buf);
  }
  fclose(fstream);
}
