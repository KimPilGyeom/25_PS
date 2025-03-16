#include <stdio.h>

int bmiLevel(int height, int weight);

int main() {
    int height[10], weight[10]; 
    int bmi_level[10];
    int count=0;
    char bmi_string[5][20] = {"Underweight","Normal weight","Overweight","Mild obesity","Severe obesity"};

    for(int i=0; i<10; i++){
        scanf("%d %d", &height[i], &weight[i]);
        bmi_level[i]= bmiLevel(height[i],weight[i]);
    }

    for(int i=0; i<10; i++){
        if (bmi_level[i]>=3){
            count++;
            printf("%d ", i+1);
        }
        }
    
    printf("\n%d ", count);    
    return 0;
}

int bmiLevel(int height, int weight){
    float bmi;
    bmi = weight/(height*height*0.01*0.01);

    if (bmi >= 30.0) {
        return 4;
    } else if (bmi >= 25.0) {
        return 3;
    } else if (bmi >= 23.0) {
        return 2;
    } else if (bmi >= 18.5) {
        return 1;
    } else {
        return 0;
    }
}