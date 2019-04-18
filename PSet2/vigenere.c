#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc != 2) // Check if there are excatly 2 command line arguments
    {
        printf("There should be 2 command line arguments for this to work!!!\n");
        return 1;
    }
    else
    {
        char *key = (argv[1]); // Get the key from the command line argument
        for(int i = 0, len = strlen(key); i < len; i++) // Check that the key only contains letters
        {
            if(!isalpha(key[i])) //'!' means 'not equals'
            {
            printf("The key should only contain letters.\n");
            return 1;
            }
        }
        string plaintext = get_string("plaintext: "); // Get the input from the user
        int letter = 0;
        int n = 0;
        int key_pos = 0;
        printf("ciphertext: ");
        // Iterate over each character in plaintext[i] to interchange from ascii index to alphabetical index back to ascii
        for(int i = 0, text_len = strlen(plaintext); i < text_len; i++)
        {
            if (islower(plaintext[i])) // Cipher lowercase letters
            {
                key_pos = (letter % (strlen(key)));
                n = (tolower(key[key_pos]) - 97); // Calculate the alphabetical index of the letter in the key word
                printf("%c", (((plaintext[i] - 97) + n) % 26) + 97);
                letter++; // Increment the letter count
            }
            else if (isupper(plaintext[i])) // Cipher uppercase letters
            {
                key_pos = (letter % (strlen(key)));
                n = (toupper(key[key_pos]) - 65); // Calculate the alphabetical index of the letter in the key word
                printf("%c", (((plaintext[i] - 65) + n) % 26) + 65);
                letter++; // Increment the letter count
            }
            else // Leave numbers, punctuation marks and spaces unchanged
            {
                printf("%c", plaintext[i]);
            }
        }
    }
    printf("\n");
    return 0;
}
