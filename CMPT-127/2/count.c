#include <stdio.h>

int main()
{

    unsigned long int charcount = 0, wordcount = 0, linecount = 0;
    char previous = getchar();

    while (previous != EOF)
    {
        charcount++;

        char current = getchar();
        int resultForPrevious = 0;
        int resultForCurrent = 0;

        if ((previous >= 'a' && previous <= 'z') || (previous >= 'A' && previous <= 'Z') || previous == '\'')
        {
            resultForPrevious = 1;
        }
        else
        {
            resultForPrevious = 0;
        }

        if ((current >= 'a' && current <= 'z') || (current >= 'A' && current <= 'Z') || current == '\'' || current == EOF)
        {
            resultForCurrent = 1;
        }
        else
        {
            resultForCurrent = 0;
        }

        if (resultForPrevious == 0 && resultForCurrent == 1)
        {
            wordcount++;
        }

        if (current == '\n')
        {
            linecount++;
        }

        previous = current;
    }

    printf("%lu %lu %lu\n", charcount, wordcount, linecount);
    return 0;
}
