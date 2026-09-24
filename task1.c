// File: task1.c
// Author: Mikayla Pelletier
// Creation date: 9/23/2026
// Revision date: 9/24/2026
// Collaborators: None
// Other sources for the code: None
// Description: takes a football score and gives all possible combination of ways that score could have been achieved
// Inputs: Int for score
// Outputs: Every possible combination of ways to get that score until user enters 1
// Revisions: Added comments

#include <stdio.h>

int main() {
    int score;

    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): ");
        if (scanf("%d", &score) != 1) { //user input
            printf("Invalid score input. Please enter a number\n");
            return 1; // Handle non-integers
        }

        if (score <= 1) {
            break; // ends program if user enters 1 or less
        }

        printf("Possible combinations of scoring plays if a team's score is %d:\n", score);

        // Nested loops from outermost (TD + 2pt) to innermost (Safety)
        // 8 points: TD + 2-point conversion
        for (int td_2pt = 0; td_2pt * 8 <= score; td_2pt++) {
            // 7 points: TD + 1-point field goal
            for (int td_fg = 0; td_2pt * 8 + td_fg * 7 <= score; td_fg++) {
                // 6 points: Touchdown
                for (int td = 0; td_2pt * 8 + td_fg * 7 + td * 6 <= score; td++) {
                    // 3 points: Field goal
                    for (int fg = 0; td_2pt * 8 + td_fg * 7 + td * 6 + fg * 3 <= score; fg++) {
                        // 2 points: Safety
                        for (int safety = 0; td_2pt * 8 + td_fg * 7 + td * 6 + fg * 3 + safety * 2 <= score; safety++) {
                            
                            // Check if the current combination matches the target score
                            if (td_2pt * 8 + td_fg * 7 + td * 6 + fg * 3 + safety * 2 == score) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", 
                                       td_2pt, td_fg, td, fg, safety);
                            }
                        }
                    }
                }
            }
        }
        printf("\n"); // Enters between rounds
    }

    return 0;
}