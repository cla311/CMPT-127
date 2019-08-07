#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        int len1 = strlen(argv[1]);
        int len2 = strlen(argv[2]);

        int arr3[len1 + 1];

        for (int i = 0; i < len1; i++)
        {
            arr3[i] = 0;
        }

        if (len1 >= len2)
        {
            int count = 0;

            for (int i = 0; i < len1; i++)
            {
                if (argv[1][i] == argv[2][0])
                {
                    arr3[i] = 1;
                    count = 1;
                }
            }

            if (count == 1)
            {
                for (int j = 0; j < len1; j++)
                {
                    for (int i = 1; i < len2; i++)
                    {
                        if (arr3[j] == 1)
                        {
                            if (argv[2][i] == argv[1][j + i])
                            {
                                count++;
                            }
                        }
                    }
                    if (count == len2)
                    {
                        printf("true\n");
                        break;
                    } else {
                        count = 1;
                    }
                }

                if (count != len2)
                {
                    printf("false\n");
                }
            }
            else
            {
                printf("false\n");
            }
        }
        else
        {
            printf("false\n");
        }
    }
    else
    {
        printf("false\n");
    }
}