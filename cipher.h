#ifndef CIPHER_H
#define CIPHER_H

int letter_to_number(char letter);
char number_to_letter(int number);
int shift(int number, int shift_value, int shift_direction);
void encrypt(char* text, int shift);
void decrypt(char* text, int shift);
int get_size();
#endif