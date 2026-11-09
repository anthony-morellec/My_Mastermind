#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NOT_NUMBER_OR_DUP_AV(AV, NB) (AV[1 + NB][0] < '0' || AV[1 + NB][0] > '8' || AV[1 + NB][1] < '0' || AV[1 + NB][1] > '8' || AV[1 + NB][2] < '0' || AV[1 + NB][2] > '8' || AV[1 + NB][3] < '0' || AV[1 + NB][3] > '8' || AV[1 + NB][0] == AV[1 + NB][1] || AV[1 + NB][0] == AV[1 + NB][2] || AV[1 + NB][0] == AV[1 + NB][3] || AV[1 + NB][1] == AV[1 + NB][2] || AV[1 + NB][1] == AV[1 + NB][3] || AV[1 + NB][2] == AV[1 + NB][3])
#define NOT_NUMBER_OR_DUP_INPUT(INPUT) (input[4] != 0 || input[0] < '0' || input[0] > '8' || input[1] < '0' || input[1] > '8' || input[2] < '0' || input[2] > '8' || input[3] < '0' || input[3] > '8' || input[0] == input[1] || input[0] == input[2] || input[0] == input[3] || input[1] == input[2] || input[1] == input[3] || input[2] == input[3])

int main(int ac, char **av) {
    srand(time(NULL));

    int round = 0;
    int max_round = 10;
    
    char nbc = 0;
    char code[5];
    char input[5];
    int code_created = 0;
    int nb_param = 0;

    if (ac > 1) {
        nb_param = 1;
    }

    while (nb_param != 2 && nb_param > 0) {
        if (av[0 + nb_param][0] == '-') {
            switch (av[0 + nb_param][1]) {
                case 'c':
                    if (av[1 + nb_param][4] != 0 ) {
                        printf("Invalid code. please retry.\n");
                        return 0;
                    }
                    else {
                        if (NOT_NUMBER_OR_DUP_AV(av, nb_param)) {
                            printf("Invalid code. please retry.\n");
                            return 0;
                        }
                        else {
                            for (int code_index = 0; code_index < 4; code_index++) {
                                code[code_index] = av[1 + nb_param][code_index];
                            }
                            code_created = 1;
                        }
                    }
                    break;

                case 't':
                    max_round = atoi(av[1 + nb_param]);
                    break;

                default:
                    printf("invalid option");
                    return 0;
            }
        }
        nb_param++;
        if (nb_param == 2 && ac > 3) {
            nb_param = 3;
        }
        else{
            nb_param = 2;
        }
    }
    
    if (code_created == 0) {
        for (int nbc_index = 0; nbc_index < 4; nbc_index++) {
            while (nbc == code[0] || nbc == code[1] || nbc == code[2]) {
                nbc = rand() % 9 + '0';
            }
            
            code[nbc_index] = nbc;
        }
    }

    printf("Will you find the secret code?\nPlease enter a valid guess\n");

    while (round < max_round) {
        int wplaced = 0;
        int msplaced = 0;
        int valid = 0;

        printf("---\nRound %d\n", round);

        while(valid != 1) {
            scanf("%4s", input);
            if (NOT_NUMBER_OR_DUP_INPUT(input)) {
                printf("Invalid input. please retry.\n");
            }
            else {
                valid = 1;
            }
        }
        
        for (int wplaced_index = 0; wplaced_index < 4; wplaced_index++) {
            if (code[wplaced_index] == input[wplaced_index]) {
                wplaced++;
            }
            for (int msplaced_index = 0; msplaced_index < 4; msplaced_index++) {
                if (code[msplaced_index] == input[wplaced_index] && code[wplaced_index] != input[wplaced_index]) {
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