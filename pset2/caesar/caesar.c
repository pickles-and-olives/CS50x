#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //Check that program was run with one command-line argument
    //Iterate over the provided argument to make sure all characters are digits
    {
        if (argc != 2)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }    
        int key = atoi(argv[1]);
        string plain = get_string("plaintext: ");
        printf("ciphertext: ");
            
        for (int j = 0; j < strlen(plain); j++)
        {

            if (islower(plain[j]) > 'z')
                //If it is a lowercase letter, rotate it, preserving case, then print out the rotated character
            {
                printf("%c", (plain[j] - 'a' + key) % 26 + 'a');
            }
            else if (isupper(plain[j]) > 'Z')
                //If it is an uppercase letter, rotate it, preserving case, then print out the rotated character
            {
                printf("%c", (plain[j] - 'A' + key) % 26 + 'A');
            }
            else 
            {
                printf("%c", (plain[j]));
            }
        }
    }
    //Print a newline
    printf("\n");
    return 0;
            
}

