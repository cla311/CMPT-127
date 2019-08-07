#include <stdio.h>

int main() {
        float a;
        float smallest, largest, sum;
        int count;

        scanf("%f", &a);
        smallest = a;
        largest = a;
        sum = a;
        count = 1;

        while(scanf("%f", &a) != EOF) {
                if(a <= smallest) {
                        smallest = a;
                } else if (a >= largest) {
                        largest = a;
                }

                sum += a;
                count++;
        }

        printf("%.2f %.2f %.2f\n", smallest, largest, sum/count);
        return 0;
}
