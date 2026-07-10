#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
    int n, i;

    printf("Enter no. of words: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of words.\n");
        return 1;
    }

    char words[n][100];
    printf("Enter %d words in small letters:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    srand(time(NULL));

    int score = 0;       // Initialize score to 0
    char choice;         // To check if user wants to play again

    // Loop to allow multiple rounds of play
    do {
        int random = rand() % n;
        printf("\nThe word is: %s\n", words[random]);

        char user[100];
        printf("Enter Anagram of the given word: ");
        scanf("%s", user);

        int isAnagram = 1; 

        if(strlen(user) != strlen(words[random])) {
            isAnagram = 0; 
        } else {
            int freq1[26] = {0};
            int freq2[26] = {0};

            for(i = 0; i < strlen(words[random]); i++) {
                char temp = words[random][i];

                int index = temp - 'a';

                freq1[index]++;
            }

            for(i = 0; i < strlen(user); i++) {
                char temp = user[i];

                int index = temp - 'a';

                freq2[index]++;
            }

            for(i = 0; i < 26; i++) {
                if(freq1[i] != freq2[i]) {
                    isAnagram = 0;
                    break;
                }
            }
        }

        // Update score based on the outcome
        if(isAnagram) {
            score += 10; // Add 10 points for a correct answer
            printf("Hurray! Words are Anagrams.\n");
        } else {
            printf("Oh no! Words are NOT Anagrams.\n");
        }

        // Display current score
        printf("Your Current Score: %d\n", score);

        printf("\nDo you want to play another round? (y/n): ");
        scanf(" %c", &choice); // Notice the space before %c to clear newline character

    } while(choice == 'y' || choice == 'Y');

    // Final game over screen
    printf("\n--- GAME OVER ---\n");
    printf("Your Final Score is: %d\n", score);

    return 0;
}