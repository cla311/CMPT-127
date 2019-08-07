#include <stdio.h>

int main() {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        for(int i = y; i > 0; i--) {
                for(int j = 0; j < x; j++) {
                        if(i == y || i == 1) {
                                printf("#");
                        } else {
                                if(j == 0) {
                                        printf("#");
                                }
                                if(j != 0 && j != x-1) {
                                        printf(".");
                                }
                                if(j == x - 1) {
                                        printf("#");
                                }
                        }
                }
                printf("\n");
        }
        return 0;
}
