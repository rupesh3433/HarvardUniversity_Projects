#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define MAX_LENGTH 1000

int totalNumberOfWords(const char *paragraph);
int totalNumberOfSentences(const char *paragraph);
int totalNumberOfLetters(const char *paragraph);

int main() {
    char text[MAX_LENGTH];

    printf("Text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';


    int numWords = totalNumberOfWords(text);
    int numSentences = totalNumberOfSentences(text);
    int numLetters = totalNumberOfLetters(text);

    double L = (numLetters*100.0)/numWords;
    double S = (numSentences*100.0)/numWords;

    double resultFloat = (0.0588 * L) - (0.296 * S) - 15.8;
    int result = (int)round(resultFloat);
    if(result < 1){
        printf("Before Grade 1\n");
    }
    else if(result >= 16){
        printf("Grade 16+\n");
    }
    else{
        printf("Grade %d\n", result);
    }

    return 0;
}




int totalNumberOfWords(const char *paragraph) {
    int wordCount = 0;
    int inWord = 0;

    while (*paragraph) {
        if (isspace(*paragraph)) {
            inWord = 0;
        } else {
            if (!inWord) {
                wordCount++;
                inWord = 1;
            }
        }
        paragraph++;
    }

    return wordCount;
}

int totalNumberOfSentences(const char *paragraph) {
    int sentenceCount = 0;

    while (*paragraph) {
        if (*paragraph == '.' || *paragraph == '!' || *paragraph == '?') {
            sentenceCount++;
        }
        paragraph++;
    }

    return sentenceCount;
}

int totalNumberOfLetters(const char *paragraph) {
    int letterCount = 0;

    while (*paragraph) {
        if (isalpha(*paragraph)) {
            letterCount++;
        }
        paragraph++;
    }

    return letterCount;
}
