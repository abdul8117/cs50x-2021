#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // char alphabet[26];

    // for (int i = 65; i <= 90; i++)
    // {
    //     alphabet[i - 65] = (char) i;
    // }

    // for (int i = 0; i < 26; i++)
    // {
    //     printf("%c", alphabet[i]);
    // }

    char l_alphabet[26];
    char u_alphabet[26];

    for (int i = 0; i < 26; i++)
    {
        l_alphabet[i] = (char)(i + 97);
        u_alphabet[i] = (char)(i + 65);
    }

    for (int i = 0; i < 26; i++)
    {
        printf("%c", l_alphabet[i]);
    }
}