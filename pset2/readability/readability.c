#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    // GET USER INPUT
    string user_input = get_string("Text: ");

    // GET LETTER COUNT
    float letters = 0;
    float words = 1;
    float sentences = 0;

    // LOOP GRABS LETTERS WORDS AND SENTENCES
    for (int i = 0; i < strlen(user_input); i++)
    {
        if (isalpha(user_input[i]))
        {
            letters++;
        }
        if (user_input[i] == ' ')
        {
            words++;
        }
        if (user_input[i] == '.' || user_input[i] == '!' || user_input[i] == '?')
        {
            sentences++;
        }
    }

    // CALCULATE COLEMAN - LIAU - INDEX
    float L = (letters / words) * 100;
    float S = (sentences / words) * 100;
    float indexf = (0.0588 * L) - (0.296 * S) - 15.8;

    // OUTPUT
    if (indexf > 16)
    {
        printf("Grade 16+\n");
    }
    else if (indexf < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", indexf);
    }
}