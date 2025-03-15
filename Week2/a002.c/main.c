#include <stdio.h>

int main() {
    int height, weight; // 신장(cm), 체중(kg) 
    float bmi; // 비만도 수치 

    // printf("키 값(cm)? :");
    scanf("%d %d", &height, &weight);
    // printf("몸무게? :");
    // scanf("%d", &weight);

   
    bmi = weight/(height*height*0.01*0.01);

    if(bmi>=25){
        printf("%.1f", bmi);
        printf(" Overweight\n");
    }
    else{
        printf("%.1f", bmi);
        printf(" Normal\n");
    }
}