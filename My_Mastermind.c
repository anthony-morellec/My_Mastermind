#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int NOT_NUMBER_OR_DUP(char* code, int ln_code) {
    int check = 0;

    if (code[ln_code] != 0) {
        check++;
    }

    for (int index = 0; index < ln_code; index++) {
        if (code[index] < '0' || code[index] > '8') {
            check++;
        }

        for (int i = 0; i < index; i++) {
            if (code[i] == code[index]) {
                check++;
            }
        }
    }

    if (check > 0) {
        return 0;
    }

    return 1;
}

int main(int ac, char **av) {
    srand(time(NULL));

    int code_length = 4;

    int round = 0;
    int max_round = 10;
    
    char nbc = 0;
    char code[code_length+1];
    char input[code_length+1];
    int code_created = 0;
    int nb_param = 0;

    if (ac > 1) {
        nb_param = 1;
    }

    while (nb_param != 2 && nb_param > 0) {
        if (av[0 + nb_param][0] == '-') {
            switch (av[0 + nb_param][1]) {
                case 'c':
                    if (av[1 + nb_param][code_length] != 0 ) {
                        printf("Invalid code. please retry.\n");
                        return 0;
                    }
                    else {
                        if (NOT_NUMBER_OR_DUP(av[1 + nb_param], code_length) != 1) {
                            printf("Invalid code. please retry.\n");
                            return 0;
                        }
                        else {
                            for (int code_index = 0; code_index < code_length; code_index++) {
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
        else {
            printf("invalid option");
            return 0;
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
        while(NOT_NUMBER_OR_DUP(code, code_length) != 1) {
            for (int nbc_index = 0; nbc_index < code_length; nbc_index++) {
                nbc = rand() % 9 + '0';

                code[nbc_index] = nbc;
            }
            code[code_length] = '\0';
        }
    }

    printf("Will you find the secret code?\nPlease enter a valid guess\n");

    while (round < max_round) {
        int wplaced = 0;
        int msplaced = 0;
        int valid = 0;
        ssize_t input_size = 0;

        printf("---\nRound %d\n", round);

        while(valid != 1) {
            input_size = read(0, input, code_length);
            if (input[input_size-1] == '\n') {
                input_size--;
            }
            input[input_size] = '\0';

            if (input[0] != '\0') {
                if (NOT_NUMBER_OR_DUP(input, code_length) != 1) {
                    printf("Wrong input!\n");
                }
                else {
                    valid = 1;
                }
            }
        }
        
        for (int wplaced_index = 0; wplaced_index < code_length; wplaced_index++) {
            if (code[wplaced_index] == input[wplaced_index]) {
                wplaced++;
            }
            for (int msplaced_index = 0; msplaced_index < code_length; msplaced_index++) {
                if (code[msplaced_index] == input[wplaced_index] && code[wplaced_index] != input[wplaced_index]) {
                    msplaced++;
                }
            }
        }
        if (wplaced == code_length) {
            printf("Congratz! You did it!");
            return 0;
        }

        printf("Well placed pieces: %d\nMisplaced pieces: %d\n", wplaced, msplaced);

        round++;
    }
    printf("game over");
    return 0;
}