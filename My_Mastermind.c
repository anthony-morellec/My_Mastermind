#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "mastermind.h"

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
                        if (not_number_or_dup(av[1 + nb_param], code_length) != 1) {
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
        while(not_number_or_dup(code, code_length) != 1) {
            for (int nbc_index = 0; nbc_index < code_length; nbc_index++) {
                nbc = rand() % 9 + '0';

                code[nbc_index] = nbc;
            }
            code[code_length] = '\0';
        }
    }

    mastermind_game(code, input, code_length, round, max_round);

    return 0;
}