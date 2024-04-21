#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <cs50.h>

#define ALPHABET_LENGTH 26

int is_valid_key(const char *key);
void encrypt_message(const char *plaintext, const char *key);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (!is_valid_key(argv[1])) {
        printf("Invalid key. Key must contain 26 unique Alphabets.\n");
        return 1;
    }

    char plaintext[1000];
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    encrypt_message(plaintext, argv[1]);

    return 0;
}

int is_valid_key(const char *key) {
    int key_length = strlen(key);

    if (key_length != ALPHABET_LENGTH) {
        return 0;
    }

    int used[ALPHABET_LENGTH] = {0};
    for (int i = 0; i < key_length; i++) {
        char ch = toupper(key[i]);

        if (!isalpha(ch)) {
            return 0;
        }

        int index = ch - 'A';
        if (used[index]) {
            return 0;
        }
        used[index] = 1;
    }

    return 1;
}

void encrypt_message(const char *plaintext, const char *key) {
    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];

        if (isalpha(ch)) {
            char encrypted_char = key[toupper(ch) - 'A'];

            if (islower(ch)) {
                printf("%c", tolower(encrypted_char));
            } else {
                printf("%c", toupper(encrypted_char));
            }
        } else {
            printf("%c", ch);
        }
    }
    printf("\n");
}
