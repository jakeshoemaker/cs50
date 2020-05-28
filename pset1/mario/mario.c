#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // create variable height
    int height;
    void printedChar(string , int);
    do
    {
        height = get_int("enter a height: ");
    }
    while(height <= 0 || height > 8);

    // loop thru each row
    for(int count = 1; count < height + 1; count++)
    {
        // left spaces
        printedChar(" ", height-count);
        // left hash
        printedChar("#", count);
        // space
        printf("  ");
        // right hash
        printedChar("#", count);
        // new line
        printf("\n");
    }
}

void printedChar(string character, int numTimes)
{
    for( int i = 0; i < numTimes; i++)
    {
        printf("%s", character);
    }
}