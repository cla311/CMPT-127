#include <stdio.h>
#include <math.h>

int main()
{
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);

        for (int i = z - 1; i >= 0; i--)
        {
                for (int j = 0; j < x; j++)
                {
                        if (i == 0)
                        {
                                printf("#");
                        }

                        int left = floor(i * (x / (2.0 * z)));
                        int right = ceil((x - 1) + (-i) * (x / (2.0 * z)));

                        if (z != 1)
                        {
                                if (i != 0 && i != z - 1)
                                {
                                        if (j < left)
                                        {
                                                printf(" ");
                                        }
                                        if (j == left || j == right)
                                        {
                                                printf("#");
                                        }
                                        if (j > left && j < right)
                                        {
                                                printf(".");
                                        }
                                }

                                if (i == z - 1)
                                {
                                        if (j < left)
                                        {
                                                printf(" ");
                                        }
                                        if (j == left || j == right)
                                        {
                                                printf("#");
                                        }
                                        if (j > left && j < right)
                                        {
                                                printf("#");
                                        }
                                }
                        }
                }
                printf("\n");
        }

        return 0;
}
