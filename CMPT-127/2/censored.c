#include <stdio.h>
#include <string.h>

int check(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '\'')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(int argc, char *argv[])
{
    char word[128];
    char c;
    int target = 0, indexForWord = 0;

    while ((c = getchar()) != EOF)
    {
        if (check(c) == 0)
        {
            // '\0' -> null character
            word[indexForWord] = '\0';
            // the first argc is program's name itself
            for (int i = 1; i < argc; i++)
            {
                if (strcmp(argv[i], word) == 0)
                {
                    target = i;
                    if (i > 0)
                    {
                        i = argc;
                    }
                }
                else
                {
                    target = 0;
                }
            }

            // if there are mathc up, just print the word
            // else print CENSORED
            if (target == 0)
            {
                printf("%s", word);
            }
            else
            {
                printf("CENSORED");
            }

            printf("%c", c);
            indexForWord = 0;
        }
        else
        {   
            // if the 'c' is a letter
            // add 'c' to the word
            // index++
            word[indexForWord] = c;
            indexForWord++;
        }
    }
    return 0;
}
