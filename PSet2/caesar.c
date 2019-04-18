#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc != 2)// Check if there are excatly 2 command line arguments
    {
        printf("Usage: ./caesar key");
    }
    else
    {
        int k = atoi(argv[1]); // Get the key from the command line argument
        // Check if the key is at least 1
        if (k < 1) // Check if the key is at least 1
        {
            printf("Usage: ./caesar key");
        }
        else
        {
            string plaintext = get_string("plaintext: "); // Get the input from the use
            printf("ciphertext: ");
            // Iterate over each character in plaintext[i] to interchange from ascii index to alphabetical index back to ascii
            for(int i = 0, n = strlen(plaintext); i < n; i++)
            {
                if (islower(plaintext[i])) // Encript lowercase letters
                {
                printf("%c", (((plaintext[i] - 97) + k) % 26) + 97);
                }
                else if (isupper(plaintext[i])) // Encript uppercase letters
                {
                printf("%c", (((plaintext[i] - 65) + k) % 26) + 65);
                }
                else // Leave punctuation marks and spaces unchanged
                {
                    printf("%c", plaintext[i]);
                }
            }
        }
    }
    printf("\n");
}
