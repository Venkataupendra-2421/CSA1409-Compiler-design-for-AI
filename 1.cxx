#include <stdio.h>
#include <ctype.h>

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    char identifiers[30] = "";
    int constants[30] = {0};
    char operators[30] = "";
    int ic = 0, cc = 0, oc = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            identifiers[ic++] = input[i];
        } else if (isdigit(input[i])) {
            int num = input[i] - '0';
            while (isdigit(input[i+1])) {
                num = num * 10 + (input[i+1] - '0');
                i++;
            }
            constants[cc++] = num;
        } else if (input[i] == '*' || input[i] == '-' || input[i] == '+' || input[i] == '='|| input[i]=='/'){
            operators[oc++] = input[i];
        }
    }

    printf("Identifiers: %s\n", identifiers);
    printf("Constants: ");
    for (int i = 0; i < cc; i++) {
        printf("%d ", constants[i]);
    }
    printf("\nOperators: %s\n", operators);

    return 0;
}