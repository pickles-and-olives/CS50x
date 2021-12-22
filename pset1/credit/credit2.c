#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    
    long long credit_number;
    
    do
    {
        credit_number = get_long_long("Card number: \n");
    }
    while (credit_number < 0);
    
   
}

bool check_valid(long long credit_number)
{
    int len = find_length(credit_number);
    
    return (len == 13 || len == 15 || len == 16) && checksum(credit_number);

}

int find_length(long long n)
{   
    int len;
    for (len = 0; n != 0; n /= 10; len++)
}

bool checksum(long long ccn)
{
    
}