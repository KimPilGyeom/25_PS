#include <stdio.h>

int main() {
    int size;
    printf("크기 입력: ");
    scanf("%d", &size);

    int stars, blank1, blank2;
    int i, j;

    for (i = 0; i < size; i++) {
        blank1 = i;
        stars = 1;
        blank2 = (size - i - 1) * 2;

        for (j = 0; j < blank1; j++) printf(" ");
        printf("*");
        for (j = 0; j < blank2; j++) printf(" ");
        if (i != size - 1) printf("*");
        printf("\n");
    }


    for (i = 0; i < size * 2; i++) {
        for (j = 0; j < size * 2; j++) {
            printf("*");
        }
        printf("\n");
    }


    for (i = size; i > 0; i--) {
        for (j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }


    for (i = 0; i < size * 2; i++) {
        printf("*");
    }
    printf("\n");

    return 0;
}