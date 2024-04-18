#include <stdio.h>
#include <cs50.h>

// Function prototypes
bool validateCard(long long cardNumber);
int countDigits(long long number);
bool isAmericanExpress(long long cardNumber);
bool isMasterCard(long long cardNumber);
bool isVisa(long long cardNumber);

int main()
{
    long long cardNumber;
    do
    {
        cardNumber = get_long_long("Number: ");
    }
    while (cardNumber <= 0); // Ensure a valid positive number is entered

    if (validateCard(cardNumber))
    {
        if (isAmericanExpress(cardNumber))
        {
            printf("AMEX\n");
        }
        else if (isMasterCard(cardNumber))
        {
            printf("MASTERCARD\n");
        }
        else if (isVisa(cardNumber))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}

bool validateCard(long long cardNumber)
{
    int sum = 0;
    bool doubleDigits = false;
    int numDigits = countDigits(cardNumber);

    while (cardNumber > 0)
    {
        int digit = cardNumber % 10;

        if (doubleDigits)
        {
            digit *= 2;
            while (digit > 0)
            {
                sum += digit % 10;
                digit /= 10;
            }
        }
        else
        {
            sum += digit;
        }

        cardNumber /= 10;
        doubleDigits = !doubleDigits;
    }

    return (sum % 10 == 0) && (numDigits >= 13 && numDigits <= 16);
}

int countDigits(long long number)
{
    int count = 0;
    while (number > 0)
    {
        number /= 10;
        count++;
    }
    return count;
}

bool isAmericanExpress(long long cardNumber)
{
    int firstTwoDigits = cardNumber / 10000000000000;
    return (firstTwoDigits == 34 || firstTwoDigits == 37);
}

bool isMasterCard(long long cardNumber)
{
    int firstTwoDigits = cardNumber / 100000000000000;
    return (firstTwoDigits >= 51 && firstTwoDigits <= 55);
}


bool isVisa(long long cardNumber)
{
    // Count the number of digits in the card number
    int numDigits = 0;
    long long temp = cardNumber;

    while (temp > 0)
    {
        temp /= 10;
        numDigits++;
    }

    // Check if it's a Visa card based on length and starting digits
    if ((numDigits == 13 || numDigits == 16) && (cardNumber / 1000000000000 == 4 || cardNumber / 1000000000000000 == 4))
    {
        return true;
    }

    return false;
}
