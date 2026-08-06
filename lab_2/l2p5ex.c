#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_winner(int *v, int idx, int n, int max_idx) {
    if (idx > n) return max_idx;
    if (v[idx] > v[max_idx]) max_idx = idx;
    return find_winner(v, idx + 1, n, max_idx);
}

int main5() {
    int students, candidates, i, vote;
    char dummy;

    printf("Enter number of students (voters): ");
    scanf("%d", &students);

    printf("Enter number of candidates: ");
    scanf("%d", &candidates);

    int *votes = (int *)calloc(candidates + 1, sizeof(int));
    char **names = (char **)calloc(candidates, sizeof(char *));

    for (i = 0; i < candidates; i++) {
        names[i] = (char *)calloc(50, sizeof(char));
        printf("Enter name of candidate %d: ", i + 1);
        scanf("%s", names[i]);
    }

    printf("\nFaculty, press 's' and Enter to start voting: ");
    scanf(" %c", &dummy);

    for (i = 0; i < students; i++) {
        printf("\nStudent %d, enter your vote (1 to %d): ", i + 1, candidates);
        scanf("%d", &vote);

        if (vote < 1 || vote > candidates) {
            votes[0]++;
            printf("Vote recorded as foul (Invalid choice)!\n");
        } else {
            votes[vote]++;
            printf("Vote successfully recorded for %s!\n", names[vote - 1]);
        }
    }

    printf("\n--- Election Results ---\n");
    for (i = 0; i < candidates; i++) {
        printf("Candidate %d (%s): %d votes\n", i + 1, names[i], votes[i + 1]);
    }
    printf("Foul/Invalid votes: %d\n", votes[0]);

    int winner_idx = find_winner(votes, 1, candidates, 1);

    if (votes[winner_idx] == 0 && votes[0] == (students)) {
        printf("\nNo valid votes cast. No winner.\n");
    } else {
        int tie = 0;
        for (i = 1; i <= candidates; i++) {
            if (i != winner_idx && votes[i] == votes[winner_idx]) {
                tie = 1;
                break;
            }
        }
        if (tie) {
            printf("\nThere is a tie!\n");
        } else {
            printf("\nWinner: %s with %d votes!\n", names[winner_idx - 1], votes[winner_idx]);
        }
    }

    free(votes);
    for (i = 0; i < candidates; i++) {
        free(names[i]);
    }
    free(names);

    return 0;
}

