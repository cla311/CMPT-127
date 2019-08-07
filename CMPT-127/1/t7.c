#include <stdio.h>

int main() {
  int a;
  while (scanf("%d", &a) != EOF) {
    for(int i = 0; i < a; i++) {
      printf("#");
    }
    printf("\n");
  }
  return 0;
}
