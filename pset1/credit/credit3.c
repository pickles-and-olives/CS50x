#include <stdio.h>
#include <cs50.h>
#include <math.h>

// prototypes
long get_whole_number (void);
int get_cc_length (long);
bool discern_checksum_validity (long);
int discern_type_of_card (long);

// declare variables
long whole_number;
int cc_length;
bool checksum_validity;
int type_of_card;


// main function
int main(void)
{
    whole_number = get_whole_number();
    cc_length = get_cc_length(whole_number);
    checksum_validity = discern_checksum_validity(whole_number);
    type_of_card = discern_type_of_card(whole_number);

    if ((checksum_validity == false) || (type_of_card == 0))
    {
        printf("INVALID\n");
    } 
    else if ((checksum_validity == true) && (type_of_card == 1))
    {
        printf("AMEX\n");
    }
    else if ((checksum_validity == true) && (type_of_card == 2))
    {
        printf("VISA\n");
    }
    else if ((checksum_validity == true) && (type_of_card == 3))
    {
        printf("MASTERCARD\n");
    }
}



// functions
long get_whole_number (void)
{
    long local_version_of_whole_number;
    local_version_of_whole_number = get_long("Number:");
    return local_version_of_whole_number;
}

int get_cc_length (long get_whole_number)
{
    long local_version_of_whole_number = whole_number;
    int local_version_of_cc_length = 0;
    while (local_version_of_whole_number > 0)
    {
        local_version_of_whole_number = local_version_of_whole_number / 10;
        local_version_of_cc_length++;
    }
    return local_version_of_cc_length;
}

bool discern_checksum_validity (long get_whole_number)
{
    int sum_of_non_doubled_digits = 0;
    int sum_of_doubled_digits = 0;
    long local_version_of_whole_number = whole_number;
    bool local_version_of_checksum_validity = false;
    int should_this_digit_be_doubled = -1;

    for (int digit_counter = 0 ; digit_counter < cc_length ; digit_counter++)
    {
        int digit_being_processed = 0;
        
        if (should_this_digit_be_doubled == -1)
        {
            digit_being_processed = local_version_of_whole_number % 10;
            sum_of_non_doubled_digits = digit_being_processed + sum_of_non_doubled_digits;
            local_version_of_whole_number = (local_version_of_whole_number - (local_version_of_whole_number % 10)) / 10;
        } 
        else if (should_this_digit_be_doubled == 1)
        {
            digit_being_processed = local_version_of_whole_number % 10;
            digit_being_processed = digit_being_processed * 2;
            if (digit_being_processed < 10)
            {
                sum_of_doubled_digits = digit_being_processed + sum_of_doubled_digits;
                local_version_of_whole_number = (local_version_of_whole_number - (local_version_of_whole_number % 10)) / 10;
            } 
            else if (digit_being_processed >= 10)
            {
                int first_digit = 0;
                first_digit = digit_being_processed % 10;
                int second_digit = 1;
                sum_of_doubled_digits = first_digit + second_digit + sum_of_doubled_digits;
                local_version_of_whole_number = (local_version_of_whole_number - (local_version_of_whole_number % 10)) / 10;
            }
        }
        should_this_digit_be_doubled = should_this_digit_be_doubled * -1;
    }
    
    if (((sum_of_non_doubled_digits + sum_of_doubled_digits) % 10) == 0)
    {
        local_version_of_checksum_validity = true;
    }
    
    return local_version_of_checksum_validity;
}



int discern_type_of_card (long get_whole_number)
{
    long local_version_of_whole_number = whole_number;
    int local_version_of_type_of_card = 0;
    int first_two_digits;
    
    first_two_digits = (whole_number / (pow (10 , (cc_length - 2))));
    
    if ((cc_length == 15) && (first_two_digits == 34 || first_two_digits == 37))
    {
        local_version_of_type_of_card = 1;//AMEX
    }
    
    else if (((13 <= cc_length) && (cc_length <= 16)) && ((40 <= first_two_digits) && (first_two_digits <= 49)))
    {
        local_version_of_type_of_card = 2;//VISA
    }
    
    else if ((cc_length == 16) && (51 <= first_two_digits) && (first_two_digits <= 55))
    {
        local_version_of_type_of_card = 3;//MASTERCARD
    }
    else 
    {
        local_version_of_type_of_card = 0;//SATISFIES CHECKSUM, BUT IS NOT A REAL CARD ie. INVALID
    }
    
    return local_version_of_type_of_card;
}