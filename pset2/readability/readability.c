#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    
    //Get user input
    string s = get_string("Text: ");

    //define integer starting point
    
    int letters = 0; // Count number of letters
    int words = 1; // Count number of words
    int sentences = 0; // Count number of sentences
    
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        //count number of letters
        if (isalpha(s[i])) 
        {
            letters++;
        }
        
        //count number of words
        if (isspace(s[i])) 
        {
            words++;
        }
        
        //count number of sentences
        if ((s[i] == '.') || (s[i] == '!') || (s[i] == '?'))
        {
            sentences++;
        }
    }
    
    //compute grade
    
    float L = (letters * 100.0f) / words;
    float S = (sentences * 100.0f) / words;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    
    //print grade
    
    {
        if (index < 1)
        {
            printf("Before Grade 1\n");
        }
        else if (index >= 16)
        {
            printf("Grade 16+\n");
        }
        else
        {
            printf("Grade %i\n", index);
        }

    }
}