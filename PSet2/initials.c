#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    string name = get_string("Your name: \n"); // Get the user's name
    printf("%c", toupper(name[0]));
    for (int i = 0, n = strlen(name); i < n; i++) // Increment over each character in the name
    {
        if (name[i] == ' ') // Print the character after the space
        printf("%c\n", toupper(name[i+1])); // The space is 'i', i+1 = the first character after the space
    }
}
