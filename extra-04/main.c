#include <stdio.h>
#include <string.h>

int balancedStringSplit(char* s);

int main() {
    char s[] = "RLRRRLLRLL";
    printf("Maximum number of balanced substrings: %d\n", balancedStringSplit(s));
    return 0;
}

int balancedStringSplit(char* s) {
    int counterR = 0;
    int counterL = 0;
    int result = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 'L') {
            counterL++;
        } else if (s[i] == 'R') {
            counterR++;
        }

        if (counterL == counterR) {
            result++;
        }
    }

    return result;
}
