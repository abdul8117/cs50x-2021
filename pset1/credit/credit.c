#include <cs50.h>
#include <stdio.h>
#include <math.h>

int card_checksum(long number, int len);
int card_length(long number);

int main(void)
{

    // get input

    long card_number = get_long("Number: ");
    int card_len = card_length(card_number);

    // calculate checksum
    // function, takes in the input, returns the last digit of the checksum
    int checksum_last_digit = card_checksum(card_number, card_len);
    int first_two_digits = trunc(card_number / pow(10, card_len - 2));

    // VISA
    // int first_digit = card_number / 10**len;

    if (trunc(card_number / pow(10, card_len - 1)) == 4 && (card_len == 13 || card_len == 16) && (checksum_last_digit == 0))
    {
        printf("VISA\n");
    }
    else if (first_two_digits == 34 || (first_two_digits == 37 && card_len == 15 && checksum_last_digit == 0))
    {
        printf("AMEX\n");
    }
    else if ((first_two_digits >= 51 && first_two_digits <= 55) && card_len == 16 && checksum_last_digit == 0)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int card_length(long number)
{
    int len = 0;

    // while (number > 10)
    // {
    //     number /= 10;
    //     len++;
    // }

    for (long i = 1; number / i > 1; i *= 10)
    {
        len++;
    }

    return len;
}

int card_checksum(long number, int len)
{
    // (number / i) % 10
    // number is the input
    // where i is the powers of ten

    int i = 0;
    long multiplier = 1;
    int last_digit;
    bool toggle = false;
    int sum = 0;

    while (i < len)
    {
        last_digit = (number / multiplier) % 10;
        // printf("%i\n", last_digit);

        // print every other digit from the second last

        if (toggle)
        {
            last_digit *= 2;

            if (last_digit >= 10)
            {
                sum += (last_digit % 10) + ((last_digit / 10) % 10);
            }
            else
            {
                sum += last_digit;
            }

            toggle = false;
        }
        else
        {
            sum += last_digit;

            toggle = true;
        }

        multiplier *= 10;
        i++;
    }

    return sum % 10;
}