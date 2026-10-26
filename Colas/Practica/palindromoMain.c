#include <stdio.h>
#include "palindromo.h"

int main() {
    char phrase[MAX_SIZE];

    printf("Introduce una frase para saber si es o no un palindromo: ");
    fgets(phrase, sizeof(phrase), stdin);
    phrase[strcspn(phrase, "\n")] = '\0';

    if (isPalindrome(phrase)) {
        printf("La frase introducida es un palindromo.\n");
    } else {
        printf("La frase introducida no es un palindromo.\n");
    }

    return 0;
}