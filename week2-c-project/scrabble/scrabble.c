#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int calculateScore(const char *word);

int main(void) {
    char player1[100], player2[100];

    printf("Player 1: ");
    fgets(player1, sizeof(player1), stdin);
    player1[strcspn(player1, "\n")] = '\0';

    printf("Player 2: ");
    fgets(player2, sizeof(player2), stdin);
    player2[strcspn(player2, "\n")] = '\0';

    int player1_score = calculateScore(player1);
    int player2_score = calculateScore(player2);

    if (player1_score > player2_score) {
        printf("Player 1 wins!\n");
    } else if (player2_score > player1_score) {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }

    return 0;
}

int calculateScore(const char *word) {
    int score = 0;
    int letterScores[] = {
        1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10,
        1, 1, 1, 1, 4, 4, 8, 4, 10
    };

    while (*word) {
        char ch = toupper(*word);
        if (ch >= 'A' && ch <= 'Z') {
            score += letterScores[ch - 'A'];
        }
        word++;
    }

    return score;
}
