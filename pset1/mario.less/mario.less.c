#include <cs50.h>
#include <stdio.h>

int main(void)
{
// ask user for height input between 1-8

    int height;

    do
    {
        height = get_int("Height: ");
    }
    while (height > 8 || height < 1);



    for (int hash = 0; hash < height; hash++)
// calculates how many times the loop is run, so if number of hashes is less than height, run again
    {

        for (int row = 0; row < height; row++)
            // calculates number of rows, adds a 'row' if the number is less than height

        {
// using if / else function to add spaces on the left of the hashes
            if (hash + row < height - 1)

            {
                printf(" ");

            }
            else

            {
                printf("#");
            }


        }


        printf("\n"); // instructs to make new line for each iteration
    }

}