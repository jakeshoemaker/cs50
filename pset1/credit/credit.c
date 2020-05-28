#include <stdio.h>
#include <cs50.h>
#include <math.h>


int main(void) {

    // INITIALIZING
    long card; int digits;
    int numDigits(long card);

    // CHECK TO SEE IF VALID NUM DIGITS

    do
    {
        card = get_long("Insert Card Number: ");


    }
    while(card < 0);

    // CHECK TO SEE IF THERE IS CORRECT AMOUNT OF DIGITS
    digits = numDigits(card);
    if( digits != 13 && digits != 15 && digits != 16 )
    {
        printf("INVALID\n");
    }

    // PUTTING NUMBER IN AN ARRAY
    int number[digits];   // Just for clarification the number will be in reverse order

    // FIRST CHECK
    for (int i = 0; i < digits; i++)
    {
        number[i] = card % 10;
        card = card / 10;
    }

    //CREATING A COPY TO VALIDATE LATER
    int originalNumber[digits];
    for (int i = 1; i < digits; i++)
    {
        originalNumber[i] = number[i];
    }

    // MULTIPLYING PRODUCT BY 2
    for (int i = 1; i < digits; i += 2)
    {
        number[i] = number[i] * 2;
    }

    int v = 0;
    int temp;

    // CHECK VISA
    if(digits == 13)
    {
        for(int i = 0; i < digits; i++)
        {
            temp = (number[i] % 10) + (number[i]/10 % 10);
            v = v + temp;
        }
        if ( originalNumber[12] == 4 && v % 10 == 0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    // CHECK AMEX
    if(digits == 15)
    {
        for(int i = 0; i < digits; i++)
        {
            temp = (number[i] % 10) + (number[i]/10 %10);
            v = v + temp;
        }
        if ( originalNumber[14] == 3 && v % 10 == 0 && ((originalNumber[13] == 3) || (originalNumber[13] == 7)))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    // CHECK MASTERCARD AND VISA
    if(digits == 16)
    {
        for(int i = 0; i < digits; i++)
        {
            temp = (number[i] % 10) + (number[i]/10 %10);
            v = v + temp;
        }
        if (originalNumber[15] == 4 && v % 10 == 0 )
        {
            printf("VISA\n");
        }
        else if (originalNumber[15] == 5 && v % 10 == 0 && (originalNumber[14] == 1 || originalNumber[14] == 2 || originalNumber[14] == 3 || originalNumber[14] == 4 || originalNumber[14] == 5))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    return 0;
}


int numDigits(long card)
{
    int count = 0;
    long num = card;
    do
    {
        // increment loop & divide by 10 to accumulate the number of digits
        count++;

        num = num / 10;
    }
    while(num != 0);
    return count;
}