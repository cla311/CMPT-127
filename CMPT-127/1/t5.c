#include <stdio.h>
#include <math.h>

int main() {
        float a;
        while(scanf("%f", &a) != EOF) {
                printf("%d %d %d\n", (int)floor(a), (int)round(a), (int)ceil(a));
        }

        printf("Done.\n");
        return 0;
}
