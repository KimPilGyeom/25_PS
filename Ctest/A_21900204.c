/*
[Full Name] : 김필겸
[Student ID] : 21900204
[Honor Code Pledge] : 나 김필겸은 하나님과 사람 앞에서 정직하고 성실하게 테스트를 수행하겠습니다.
*/

#include <stdio.h>

int main(void) {
    const char *monthnames[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    char name[20];
    int birthdate;
    int year, month, day;
    int age;

    scanf("%s", name);
    scanf("%d", &birthdate);

    year = birthdate / 10000;
    month = (birthdate % 10000) / 100;
    day = birthdate % 100;

    age = 2025 - year;

    printf("%s - %d (%s %d, %d)\n", name, age, monthnames[month - 1], day, year);

    return 0;
}