#include <stdio.h>

int bmiLevel(int height, int weight);

int main() {
    int height[20], weight[20]; 
    int bmi_level[20];
    int all;
    char bmi_string[5][20] = {"Underweight","Normal weight","Overweight","Mild obesity","Severe obesity"};

    scanf("%d", &all);
    for(int i=0; i<all; i++){
        scanf("%d %d", &height[i], &weight[i]);
        bmi_level[i]= bmiLevel(height[i],weight[i]);
    }

    for(int i=0; i<all; i++){
        if (bmi_level[i]>=3){
            printf("%d %s\n", i+1, bmi_string[bmi_level[i]]);
        }
        }
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