#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>
#include <math.h>

int count_letters(string txt);
int count_words(string txt);
int count_sentences(string txt);

int main(void)
{
    string text = get_string("Text: ");

    float no_of_letters = count_letters(text);
    float no_of_words = count_words(text);
    float no_of_sentences = count_sentences(text);

    // printf("%f letter(s)\n", no_of_letters);
    // printf("%f word(s)\n", no_of_words);
    // printf("%f sentence(s)\n", no_of_sentences);

    float L = no_of_letters / no_of_words * 100;
    float S = no_of_sentences / no_of_words * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);


    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");   
    }
    else
    {
        printf("Grade %i\n", index);
    }
    


    
}

int count_letters(string txt)
{
    int count = 0;

    for (int i = 0, len = strlen(txt); i < len; i++)
    {
        if (isalpha(txt[i]))
        {
            count++;
        }
    }

    return count;   
}

int count_words(string txt)
{
    int count = 1;

    for (int i = 0, len = strlen(txt); i < len; i++)
    {
        if ((int) txt[i] == 32)
        {
            count++;
        }

        // if (txt[i] == ' ')
        // {
        //     count++;
        // }

        // both work
    
    }
    
        return count;
}

int count_sentences(string txt)
{
    int count = 0;

    for (int i = 0, len = strlen(txt); i < len; i++)
    {
        if ((int) txt[i] == 46 || (int) txt[i] == 33 || (int) txt[i] == 63)
        {
            /*
            . is 46
            ! is 33
            ? is 63
            */

           count++;
        }
    }

    return count;
}
