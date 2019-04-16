#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)

{
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;
    float change;
    int count = 0; // This variable will keep track of the number of coins

    do
    {
        change = get_float("Change owed: "); // Get the input from the user
    }
    while(change <= 0); // Ask for the input again if the current input is equals to or less than zero


    int amount_in_cents = change * 100; // Convert the amount in dollars into cents
    printf("This equals to %i in cents.\n", amount_in_cents);

    while(amount_in_cents >= quarter) // Count the quarters needed
        {
            count++;
            amount_in_cents -= quarter;
            printf("Amount left:%i\n", amount_in_cents);
        }

    while(amount_in_cents >= dime) // Count the dimes needed
        {
            count++;
            amount_in_cents -= dime;
            printf("Amount left:%i\n", amount_in_cents);
        }

    while(amount_in_cents >= nickel) // Count the nickels needed
        {
            count++;
            amount_in_cents -= nickel;
            printf("Amount left:%i\n", amount_in_cents);
        }

    while(amount_in_cents >= penny) // Count the pennies needed
        {
            count++;
            amount_in_cents -= penny;
            printf("Amount left:%i\n", amount_in_cents);
        }

    printf("Number of coins:%i\n", count);
}
