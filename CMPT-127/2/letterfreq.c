#include <stdio.h>
#include <ctype.h>

int isLetter(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    float letters[26] = {0}, totalLetters = 0;
    char c = getchar();

    while (c != EOF)
    {
        if (isLetter(c) == 1)
        {
            // convert all upper case letter to lower case
            c = tolower(c);
            totalLetters++;

            // since 'a' Dec is 97, 'z' Dec is 122
            // c belongs to [97, 122], there are 26 letters
            // c - 97/'a' = [0, 25]
            c -= 'a';
            int index = (int)c;

            // the value at the index indicates how many times does the letter appear
            letters[index]++;
        }

        // get out the loop
        c = getchar();
    }

    for (int i = 0; i < 26; i++)
    {
        if (letters[i] != 0)
        {
            char letter = 'a' + i;
            float freq = letters[i] / totalLetters;
            printf("%c %.4f\n", letter, freq);
        }
    }
    return 0;
}