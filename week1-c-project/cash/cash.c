#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Prompt user for change owed (positive integer)
    int change;
    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 0);

    // Define coin denominations
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;

    // Initialize variable to count coins
    int coins = 0;

    // Calculate minimum number of coins needed
    while (change >= quarter)
    {
        coins += change / quarter;
        change %= quarter;
    }
    while (change >= dime)
    {
        coins += change / dime;
        change %= dime;
    }
    while (change >= nickel)
    {
        coins += change / nickel;
        change %= nickel;
    }
    while (change >= penny)
    {
        coins += change / penny;
        change %= penny;
    }

    // Print the minimum number of coins
    printf("%i\n", coins);

    return 0;
}
