int not_number_or_dup(char* code, int ln_code) {
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

void mastermind_game(char *code, char *input, int code_length, int round, int max_round) {
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
            return;
        }

        printf("Well placed pieces: %d\nMisplaced pieces: %d\n", wplaced, msplaced);

        round++;
    }
    printf("game over");
}