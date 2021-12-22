#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size

    int start, end, years, born, died;
    
    do
    {
        start = get_int("Starting Populaton: ");
    }
    while (start < 9);

    // TODO: Prompt for end size
    
    do
    {
        end = get_int("Ending Populaton: ");
    }
    while (start > end);

    // TODO: Calculate number of years until we reach threshold
    
    for (years = 0; start < end; years++)
    
    {
        born = start / 3;
        died = start / 4;
        
        start = start + born - died;
    }
    
    
    // TODO: Print number of years
    
    {
        printf("Years: %i\n", years);
    }
}
