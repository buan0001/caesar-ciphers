#include <stdio.h>
#include "caesar.h"
#include "cipher.h"

int main()
{
    printf("Welcome to this caesar en- and decrypter!\n");

    get_input();
    
    return 0;
}

void get_input(){
 while (1)
 {
    char choice;
    int shift_value;
    char input[255];
    
    int exit = handle_input(&choice, &shift_value, input);
    if (exit == -1) {
        return;
    }
    printf("Choice: %c. Shift value: %d. Input: %s\n", choice, shift_value, input);
    switch (choice){
        case 'd': {
            decrypt(input, shift_value);
            printf("\nDecrypted message: %s\n", input);
            break;
        }
        case 'e': {
            encrypt(input, shift_value);
            printf("\nEncrypted message: %s\n", input);
            break;
        }
        default: {
            printf("Bad input, try again\n");
        }
    }
    printf("\n======================\n\n");
 }
}

void print_choices(){
    printf("(d) to decrypt\n");
    printf("(e) to encrypt\n");
    printf("(x) to exit\n");
}

int handle_input(char *choice, int *shift_value, char *input){
    print_choices();
    scanf(" %c", choice);
    if (*choice == 'x') {
        return -1;
    }
    printf("Now enter the value to shift every letter by: ");
    scanf(" %d", shift_value);
    // fgets(shift_value, 100, stdin);

    // Removes newline character left in the buffer
    getchar();

    printf("Finally, enter the text you want to shift\n");
    if (fgets(input, 255, stdin) == NULL) {
        printf("Something went wrong with input\n");
        return 0;
    }

    return 0;
}