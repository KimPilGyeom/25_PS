/*
[Full Name] : 김필겸
[Student ID] : 21900204
[Honor Code Pledge] : 나 김필겸은 하나님과 사람 앞에서 정직하고 성실하게 테스트를 수행하겠습니다.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct st_person {
    char name[20];       
    int birthdate;     
    int age;            
    int year, month, day; 
} PERSON;

const char *monthnames[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

void setPerson(PERSON* p){
    p->year = p->birthdate / 10000;
    p->month = (p->birthdate % 10000) / 100;
    p->day = p->birthdate % 100;

    p->age = 2025 - p->year;
}

void printPerson(PERSON* p){
    printf("%s - %d (%s %d, %d)\n", p->name, p->age, monthnames[p->month - 1], p->day, p->year);
}

int main(void){
    PERSON* one;
    one = (PERSON*) malloc(sizeof(PERSON));
    scanf("%s %d", one->name, &one->birthdate);
    setPerson(one);
    printPerson(one);
    return 0;
}