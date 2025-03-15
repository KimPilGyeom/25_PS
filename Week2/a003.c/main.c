#include <stdio.h>

int main() {
    int count=0;
    int people, height, weight; // 인원수, 신장(cm), 체중(kg) 
    float bmi; // 비만도 수치 

    scanf("%d", &people);

    for(int i=0; i<people; i++){
        scanf("%d %d", &height, &weight);
        bmi = weight/(height*height*0.01*0.01);
        if(bmi>=25){
            count++;
        }
    }
    printf("%d\n", count);
}