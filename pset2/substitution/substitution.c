#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void substitution_cipher(string plaintext, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    int key_len = strlen(argv[1]);

    if (key_len != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // check for repeat chars in key
    for (int i = 0; i < key_len; i++)
    {
        for (int j = 0; j < key_len; j++)
        {
            if ((tolower(key[i]) == tolower(key[j])) && (i != j))
            {
                printf("Key cannot contain repeating characters.\n");
                return 1;
            }
        }
    }

    // check if all chars are alphabets
    for (int i = 0; i < key_len; i++)
    {
        if (!(isalpha(key[i])))
        {
            printf("Key cannot contain non-alphabetical characters.\n");
            return 1;
        }
    }

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    substitution_cipher(plaintext, key);
}

void substitution_cipher(string plaintext, string key)
{
    int index;
    int key_letter;

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            if ((int)plaintext[i] >= 97)
            {
                // char is lowercase
                // get index of the letter, plaintext[i], in the alphabet

                index = (int)plaintext[i] - 'a';

                key_letter = (int) key[index];

                if (key_letter < 97)
                {
                    // key_letter: ascii encoding of the letter of the key corresponding to plaintext[i]
                    // convert it to lowercase: 
                    key_letter += 32;
                    printf("%c", key_letter);
                }
                else
                {
                    printf("%c", key_letter);
                }
            }
            else
            {
                // char is uppercase
                index = (int)plaintext[i] - 'A';

                key_letter = (int) key[index];

                if (key_letter > 97)
                {
                    key_letter -= 32;
                    printf("%c", key_letter);
                }
                else
                {
                    printf("%c", key_letter);
                }
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
}