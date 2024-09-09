#include <stdio.h>
#include "caesar.h"
#include "cipher.h"

int main()
{
    printf("Welcome to this caesar en- and decrypter!\n");
    while (1) {
        get_input();
    }
    return 0;
}

void get_input(){
    print_choices();
    char choice;
    
    fgets(choice, 1, stdin);
    switch (choice){
        case 'd': 
    }
}

void print_choices(){
    printf("(d) to decrypt\n");
    printf("(e) to encrypt\n");
    printf("(x) to exit\n");
}