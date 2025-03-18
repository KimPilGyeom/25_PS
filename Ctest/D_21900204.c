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

int loadPersons(PERSON* list[]){
    int n;
    scanf("%d", &n);

    for (int i=0; i<n; i++){
        list[i] = (PERSON*) malloc(sizeof(PERSON));
        scanf("%s %d", list[i]->name, &list[i]->birthdate);
        setPerson(list[i]); 
    }

    return n;
}

PERSON* oldestPerson(PERSON* list[], int size){
    PERSON* oldest = list[0];

    for (int i=1; i<size; i++){
        if (list[i]->birthdate < oldest->birthdate){
            oldest = list[i];
        }
    }

    return oldest;
}

PERSON* youngestPerson(PERSON* list[], int size){
    PERSON* youngest = list[0];

    for (int i=1; i<size; i++){
        if (list[i]->birthdate > youngest->birthdate){
            youngest = list[i];
        }
    }

    return youngest;
}

int main(void){
    PERSON* persons[100];
    int count = loadPersons(persons);
    printf("Oldest: ");
    printPerson(oldestPerson(persons, count));
    printf("Youngest: ");
    printPerson(youngestPerson(persons, count));

    return 0;
}