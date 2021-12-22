#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)

{
    float dollar;
    
    {
        
        do
     
        {
        
            dollar = get_float("Enter change amount: "); //ask for user input
        }
    
    
        while (dollar <= 0); 
    
        int cents = round(dollar * 100);
        int coins = 0;
    
        while (cents >= 25) //while cents is more than 25, 
    
        {
        
            cents = cents - 25; //while cents is more than 25, add 1 to the coin count
            coins++;
        
        }
    
        while (cents >= 10)
    
        {
            cents = cents - 10; //each loop runs until the parameters are no longer met, before moving to the next condition
            coins++;
        }
    
        while (cents >= 5)
    
        {
            cents = cents - 5;
            coins++;
        
        }
    
        while (cents >= 1)
    
        {
            cents = cents - 1;
            coins++;
        }
    
        printf("You will need %i coins \n", coins); //uses %i as placeholder for final integer
    
    }
        
}