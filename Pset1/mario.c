#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = 0;
    int line = 0;
    int space = 0;
    int hash = 0;

    while(height < 1 || height > 23)
    {
        printf("Height (a number that is greater than 1 but less than 24): \n"); // Get the input from the user
        scanf("%d", &height);
    }

    for(line = 0; line < height; line++)
    {
        for(space = 0; space <= height - line - 1; space++) // Print spaces on each line of the first pyramid
            printf(" ");

        for(hash = 0; hash <= line; hash++) // Print hashes on each line of the first pyramid
            printf("#");

        printf("  "); // Print the space between the two pyramids

        for(hash = 0; hash <= line; hash++) // Print hashes on each line of the second pyramid
            printf("#");

        for(space = 0; space <= height - line - 1; space++) // Print spaces on each line of the second pyramid
            printf(" ");


        printf("\n");
    }
}
