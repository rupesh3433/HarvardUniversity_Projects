#include <stdio.h>
#include <cs50.h>

void print_pyramid(int height);

int main()
{
    int height;
    do
    {
        height = get_int("Height (1-8): ");
    }
    while (height < 1 || height > 8);

    print_pyramid(height);

    return 0;
}

void print_pyramid(int height)
{
    for (int row = 1; row <= height; row++)
    {
        for (int space = height - row; space > 0; space--)
        {
            printf(" ");
        }

        for (int hash = 1; hash <= row; hash++)
        {
            printf("#");
        }

        printf("  ");

        for (int hash = 1; hash <= row; hash++)
        {
            printf("#");
        }

        printf("\n");
    }
}
