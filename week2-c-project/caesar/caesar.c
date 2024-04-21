#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


int only_digits(const char *str);
char rotate(char ch, int key);

int main(int argc, char *argv[]) {
    if (argc != 2 || !only_digits(argv[1])) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    char plaintext[1000];
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++) {
        char encrypted = rotate(plaintext[i], key);
        printf("%c", encrypted);
    }
    printf("\n");

    return 0;
}

int only_digits(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

char rotate(char ch, int key) {
    if (isalpha(ch)) {
        char base = islower(ch) ? 'a' : 'A';
        return base + (ch - base + key) % 26;
    }
    return ch;
}
