#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // the following statement asks the user for a name and inserts it into the placeholder
    printf("hello, %s\n", get_string("what is your name?"));
}