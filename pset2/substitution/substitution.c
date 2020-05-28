#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool isUnique(string argument);

void encipher(string plaintext, string key);


int main(int argc, string argv[])
{
    string key = argv[1];
    // HANDLE NO ARGUMENT GIVEN
    if (argc == 1)  // might have to toy with the first validation due to argc limitations
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // HANDLE NON-ALPHABETICAL CHARACTERS
    else if (argv[1])
    {
        for(int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if(!isalpha(argv[1][i]))
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
    }
    // HANDLE IF INCORRECT FORMAT GIVEN
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    // HANDLE REPEATING DIGITS
    if (isUnique(argv[1]) == false)
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }
    // VALIDATED

    string plaintext = get_string("plaintext: ");
    encipher(plaintext, argv[1]);

    return 0;

}

// OTHER FUNCTIONS

bool isUnique(string argument)
{
    for (int i = 0; i < strlen(argument); i++)
    {
        for (int j = i + 1; j < strlen(argument); j++)
        {
            if (argument[i] == argument[j])
            {
                return false;
            }
        }
    }
    // If no duplicate values are encountered return true
    return true;
}

void encipher(string plaintext, string key)
{

    // INITIALIZE VARIABLE
    char ciphertext[strlen(plaintext) + 1];
    int position;
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (islower(plaintext[i]) != 0)
            {
                // CAST VALUE TO INTEGER AND SET CIPHER
                position = (int) plaintext[i] - 97;     // if lower, then
                ciphertext[i] = tolower(key[position]); // set to lowercase
            }
            else
            {
                position = (int) plaintext[i] - 65;     // if upper, then
                ciphertext[i] = toupper(key[position]); // set to uppercase
            }
        }
        else
        {
            // IF NOT ALPHA, KEEP CHAR
            ciphertext[i] = plaintext[i];
        }
    }

    //PRINT CIPHER TEXT
    printf("ciphertext: ");
    // PRINT ARRAY OF CHAR
    for(int i = 0; i < strlen(plaintext); i++)
    {
        printf("%c", ciphertext[i]);
    }
    printf("\n");
}