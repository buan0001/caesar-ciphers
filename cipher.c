#include <stdio.h>
#include <ctype.h>
#include "cipher.h"

char alphabet[255] = "ABCDEFGHIJKLMNOPQRSTUVWXYZÆØÅ";
// char alphabet[255] = "ABCDEFGHIJKLMNOPQRSTUVWXYZÆØÅ";
int length = sizeof(alphabet) / sizeof(alphabet[0]);
int entries;
// char alphabet[40] = {'A','B','C','D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U','V','W','X','Y','Z', 'Æ', 'Ø', 'Å'};

int get_size()
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (!alphabet[i]) {
        printf("End of array reached at index: %d\n", i);
        break;
        }
        // printf("Value at index %d: %c\n", i, alphabet[i]);
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
            printf("End of array reached at index: %d\n", i);
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
    printf("Number: %d. Shift value: %d\n", number, shift_value);
    int new_number;
    if (direction > 0) {
        new_number = number + shift_value;
        if (new_number > entries -1) {
            new_number = new_number - entries;
        }
    }
    else {
        new_number = number - shift_value;
        if (new_number < 0) {
            new_number = new_number + entries;
        }
    }

    return new_number;
}

void encrypt(char* text, int shift_value)
{
    for (int i = 0; i < 255; i++)
    {
        if (!text[i]) {
            printf("End of array reached at index: %d\n", i);
            break;
        }
        else {
            int numbered_letter = letter_to_number( text[i] );
            int shifted_number = shift( numbered_letter, shift_value, 1 );
            text[i] = number_to_letter( shifted_number );
        }
    }
    
}

void decrypt(char* text, int shift_value)
{
    for (int i = 0; i < 255; i++)
    {
        if (!text[i]) {
            printf("End of array reached at index: %d\n", i);
            break;
        }
        else {
            int numbered_letter = letter_to_number(text[i]);
            int shifted_number = shift( numbered_letter, shift_value, -1 );
            text[i] = number_to_letter(shifted_number);
        }
    }
    
}

int indexOf(char letter)
{
    char upper = toupper(letter);
    for (int i = 0; i < length; i++)
    {
        if (!alphabet[i]) {
            printf("End of array reached at index: %d\n", i);
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

int main()
{
    entries = get_size();
    printf("Entries are: %d\n", entries);
    char test_string[] = "ABC";
    printf("pre encrypt: %s\n", test_string);
    encrypt(test_string, 40);
    printf("post encrypt: %s\n", test_string);
    decrypt(test_string, 40);
    printf("post decrypt: %s\n", test_string);
    // printf("Å is: %c\n", alphabet[entries-2]);
    // char result1 = number_to_letter(54);
    // int result2 = letter_to_number('f');
    // printf("number_to_letter: %c\n", result1);
    // printf("letter_to_number: %d\n", result2);
    return 0;
}