/*
[Full Name] : 김필겸
[Student ID] : 21900204
[Honor Code Pledge] : 나 김필겸은 하나님과 사람 앞에서 정직하고 성실하게 테스트를 수행하겠습니다.
*/

#include <stdio.h>

int main(void) {
    const char *monthnames[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    char names[100][20];
    int birthdate[100];
    int year, month, day;
    int age;
    int people;
    int oldest=0;

    scanf("%d", &people);
    for (int i=0; i<people; i++) {
        scanf("%s %d", names[i], &birthdate[i]);
    }

    for (int i=1; i<people; i++) {
        if (birthdate[i]<birthdate[oldest]) {
            oldest=i;
        }
    }

    year = birthdate[oldest] / 10000;
    month = (birthdate[oldest] % 10000) / 100;
    day = birthdate[oldest] % 100;

    age = 2025 - year;

    printf("%s - %d (%s %d, %d)\n", names[oldest], age, monthnames[month - 1], day, year);

    return 0;
}