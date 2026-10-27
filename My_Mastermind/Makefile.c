#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int ac, char **av) {
    srand(time(NULL));

    int round = 0;
    int max_round = 10;
    
    char nbc = 'n';
    char code[] = "nnnn";
    char input[] = "nnnn";
    int code_created = 0;
    if (ac > 1) {
        if (av[1][0] == '-') {
            switch (av[1][1]) {
                case 'c':
                    if (av[2][4] != 0) {
                        printf("Invalid code. please retry.\n");
                        return 0;
                    }
                    else {
                        if (av[2][0] <= '0' || av[2][0] >= '8' || av[2][1] <= '0' || av[2][1] >= '8' || av[2][2] <= '0' || av[2][2] >= '8' || av[2][3] <= '0' || av[2][3] >= '8' || av[2][0] == av[2][1] || av[2][0] == av[2][2] || av[2][0] == av[2][3] || av[2][1] == av[2][2] || av[2][1] == av[2][3] || av[2][2] == av[2][3]) {
                            printf("Invalid code. please retry.\n");
                            return 0;
                        }
                        else {
                            for (int c = 0; c < 4; c++) {
                                code[c] = av[2][c];
                            }
                            code_created = 1;
                        }
                    }
                    break;

                case 't':
                    max_round = atoi(av[2]);
                    break;

                default:
                    printf("invalid option");
                    return 0;
            }
        }

        if (ac > 3) {
            if (av[3][0] == '-') {
                switch (av[3][1]) {
                    case 'c':
                        if (av[4][4] != 0) {
                            printf("Invalid code. please retry.\n");
                            return 0;
                        }
                        else {
                            if (av[4][0] <= '0' || av[4][0] >= '8' || av[4][1] <= '0' || av[4][1] >= '8' || av[4][2] <= '0' || av[4][2] >= '8' || av[4][3] <= '0' || av[4][3] >= '8' || av[4][0] == av[4][1] || av[4][0] == av[4][2] || av[4][0] == av[4][3] || av[4][1] == av[4][2] || av[4][1] == av[4][3] || av[4][2] == av[4][3]) {
                                printf("Invalid code. please retry.\n");
                                return 0;
                            }
                            else {
                                for (int c = 0; c < 4; c++) {
                                    code[c] = av[4][c];
                                }
                            }
                        }
                        break;

                    case 't':
                        max_round = atoi(av[4]);
                        break;

                    default:
                        printf("invalid option");
                        return 0;
                }
            }
        }
    }

    if (code_created == 0) {
        for (int r = 0; r < 4; r++) {
            while (nbc == code[0] || nbc == code[1] || nbc == code[2]) {
                nbc = (rand() % (8 - 0 + 1) + 0) + '0';
            }
            code[r] = nbc;
        }
    }

    printf("Will you find the secret code?\nPlease enter a valid guess\n");
    
    while (round < max_round) {
        int wplaced = 0;
        int msplaced = 0;
        int valid = 0;

        printf("---\nRound %d\n", round);

        while (valid != 1) {
            scanf("%s", input);
            if (input[4] != 0) {
                printf("Invalid input. please retry.\n");
            }
            else {
                if (input[0] >= '0' && input[0] <= '8' && input[1] >= '0' && input[1] <= '8' && input[2] >= '0' && input[2] <= '8' && input[3] >= '0' && input[3] <= '8' && input[0] != input[1] && input[0] != input[2] && input[0] != input[3] && input[1] != input[2] && input[1] != input[3] && input[2] != input[3]) {
                valid = 1;
                }
                else {
                    printf("Invalid input. please retry.\n");
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            if (code[i] == input[i]) {
                wplaced++;
            }
            for (int n = 0; n < 4; n++) {
                if (code[n] == input[i] && code[i] != input[i]) {
                    msplaced++;
                }
            }
        }
        if (wplaced == 4) {
            printf("Congratz! You did it!");
            return 0;
        }

        printf("Well placed pieces: %d\nMisplaced pieces: %d\n", wplaced, msplaced);
        round++;
    }
    printf("game over");
    return 0;
}