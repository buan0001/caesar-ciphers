#include <stdio.h>
#include <ctype.h>
#include "cipher.h"

// Leftovers from trying to make ÆØÅ work
// char alphabet[29][4] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "Æ", "Ø", "Å"};
// wchar_t alphabet[255] = L"ABCDEFGHIJKLMNOPQRSTUVWXYZÆØÅ";
// char alphabet[40] = {'A','B','C','D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U','V','W','X','Y','Z', 'Æ', 'Ø', 'Å'};

// Alphabet that gave up on ÆØÅ
char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int length = sizeof(alphabet) / sizeof(alphabet[0]);
// int entries;

int get_size()
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (!alphabet[i]) {
        // printf("End of array reached at index: %d\n", i);
        break;
        }
        // printf("Value at index %d: %c\n", i, alphabet[i]);
        // printf("Adress of index %d: %p\n", i, &alphabet[i]);
        count++;
    }
    return count;
}

int letter_to_number(char letter)
{
    char upper = toupper(letter);
    for (int i = 0; i < length; i++)
    {
        if (!alphabet[i]) {
            // printf("End of array reached at index: %d\n", i);
            break;
        }
        else{
            if (upper == alphabet[i]) {
                return i;
            }
        }

    }
    return -1;
    
}

char number_to_letter(int number)
{
    char found = alphabet[number];
    printf("Number %d is equivalent to %c\n", number, found);
    return found;
}

int shift(int number, int shift_value, int direction)
{

    
    // printf("Number: %d. Shift value: %d\n", number, shift_value);
    int new_number;
    int iterations = 0;
    if (direction > 0) {
        return (number + shift_value + 26) % 26;
    }
    else {
        new_number = number - shift_value;
        while (new_number < 0) {
            iterations++;
            // printf("Number too low: %d\n", new_number);
            new_number += length;
            if (iterations > 30) {
                printf("Too many iterations, breaking out of shift\n");
                return -1;
            }
        }
    }
    printf("Shifted number: %d\n", new_number);
    return new_number;
}

void encrypt(char* text, int shift_value)
{
    for (int i = 0; i < length; i++)
    {
        if (!text[i]) {
            // printf("End of array reached at index: %d\n", i);
            break;
        }
        else {
            // printf("letter to number\n");
            int numbered_letter = letter_to_number( text[i] );
            if (numbered_letter == -1) {
                text[i] = ' ';
            }
            else {
            // printf("shifted number\n");
            int shifted_number = shift( numbered_letter, shift_value, 1 );
            // printf("number to letter\n");
            text[i] = number_to_letter( shifted_number );
            }
        }
    }
    // printf("done encrypting\n");
    
}

void decrypt(char* text, int shift_value)
{
    for (int i = 0; i < length; i++)
    {
        if (!text[i]) {
            // printf("End of array reached at index: %d\n", i);
            break;
        }
        else {
            int numbered_letter = letter_to_number(text[i]);
            if (numbered_letter == -1) {
                text[i] = ' ';
            }
            else {
                int shifted_number = shift( numbered_letter, shift_value, -1 );
                text[i] = number_to_letter(shifted_number);
            }
        }
    }
    
}

int indexOf(char letter)
{
    char upper = toupper(letter);
    for (int i = 0; i < length; i++)
    {
        if (!alphabet[i]) {
            // printf("End of array reached at index: %d\n", i);
            break;
        }
        else{
            if (upper == alphabet[i]) {
                return i;
            }
        }

    }
    return -1;
    
}

// int main()
// {
//     entries = get_size();
//     printf("Entries are: %d\n", entries);
// //     char test_string[] = "abc";
//     printf("pre encrypt: %s\n", test_string);
// //     encrypt(test_string, 14);
//     printf("post encrypt: %s\n", test_string);
// //     decrypt(test_string, 14);
//     printf("post decrypt: %s\n", test_string);
//     return 0;
//     // OPQ
// }