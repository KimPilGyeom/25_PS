#include <stdio.h>

struct bmi_struct {
    char name[20];
    int height;
    int weight;
    float bmi;
    int bmi_level;
};

char bmi_string[5][20] = {"Underweight", "Normal weight", "Overweight", "Mild obesity", "Severe obesity"};

int loadData(struct bmi_struct list[]);
void bmiResolve(struct bmi_struct* sp);
void printBmiData(struct bmi_struct list[], int size);

int main(void) 
{
    struct bmi_struct data[20];
    int count;

    count = loadData(data);

    for (int i = 0; i < count; ++i) {
        bmiResolve(&data[i]);
    }

    printBmiData(data, count);

    return 0;
}

int loadData(struct bmi_struct list[]) 
{
    int n;

    printf("몇 명의 데이터를 입력할까요? ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("%d번째 사람 이름, 키(cm), 몸무게(kg)를 입력하세요: ", i + 1);
        scanf("%s %d %d", list[i].name, &list[i].height, &list[i].weight);
    }

    return n;
}

void bmiResolve(struct bmi_struct* sp) 
{
    float height_m = sp->height / 100.0;
    sp->bmi = sp->weight / (height_m * height_m);

    if (sp->bmi >= 30.0) {
        sp->bmi_level = 4;
    } else if (sp->bmi >= 25.0) {
        sp->bmi_level = 3;
    } else if (sp->bmi >= 23.0) {
        sp->bmi_level = 2;
    } else if (sp->bmi >= 18.5) {
        sp->bmi_level = 1;
    } else {
        sp->bmi_level = 0;
    }
}

void printBmiData(struct bmi_struct list[], int size) 
{
    printf("\n==== BMI 결과 ====\n");

    for (int i = 0; i < size; ++i) {
        printf("%s: %dcm %dkg, BMI: %.1f, 상태: %s\n", 
               list[i].name, 
               list[i].height, 
               list[i].weight, 
               list[i].bmi, 
               bmi_string[list[i].bmi_level]);
    }
}