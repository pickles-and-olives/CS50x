#include <cs50.h>
#include <stdio.h>
#include <math.h>

// Luhn's Algorithm:
// 1. Multiply every other digit by 2, starting with the second number to the last
// 2. Add the sum of those digits
// 3. Add the sum of the other digits that were not multiplied
// 4. If the total sum ends with 0, it is valid.


int main(void)
{
    long long cardnumber;
    
    do
    {
        //promt user for number
        cardnumber = get_long_long("Credit card number: \n");
    }
    while (cardnumber < 0);
    
    //count digits
    int len = 0;
    long long cn = cardnumber;
    
    while (cn > 0)
    {
        cn = cn / 10;
        len++;
    }
    
    int sum1 = 0;
    int sum2 = 0; 
    long long cn1 = cn;
    long long cn2 = cn;
    int remain0;
    int remain1;
    int remain2;
    
    while (cn1 != 0)
    {
        remain1 = 2 * ((cn1 % 100) / 10);
        remain0 = remain1 % 10 + round(remain1 / 10);
        sum1 = sum1 + remain0 ;
        cn1 = cn1 / 100;
    }
    
    while (cn2 != 0)
    {
        remain2 = cn2 % 10;
        sum2 = sum2 + remain2;
        cn2 = cn2 / 100;
    }
    
    long sum3 = sum1 + sum2;
    
    if (sum3 % 10 == 0 && (len == 13 || len == 16) && floor(cardnumber / 1000000000000) == 4)
    {
        printf("VISA\n");
        return 0;
    }

    if (sum3 % 10 == 0 && len == 15 && (cardnumber / 1000000000000 == 34 || cardnumber / 1000000000000 == 37))
    {
        printf("AMEX\n");
        return 0;
    }
    
    if (sum3 % 10 == 0 && len == 16 && (cardnumber / 1000000000000 == 51 || cardnumber / 1000000000000 == 52 || 
    cardnumber / 1000000000000 == 53 || cardnumber / 1000000000000 == 54 || cardnumber / 1000000000000 == 55))
    {
        printf("MASTER\n");
        return 0;
    }
    else 
    {
        printf("INVALID\n");
    }
    
}
