#include <stdio.h>

void main(){

    int student[10][3] ={
        {80, 70, 90},
        {60, 50, 80},
        {90, 99, 50},
        {70, 70, 66},
        {80, 70, 90},
        {70, 80, 90},
        {90, 70, 80},
        {70, 70, 60},
        {88, 75, 80},
        {85, 75, 95}
    };

    int total[10];
    
    for (int i=0; i<10; i++){
        for (int j=0; j<3; j++){
            total[i] += student[i][j];
        }
    }
    
    printf("학번 \t 국어 \t 영어 \t 수학 \t 총점 \t 평균\n");
    printf("**********************************************************\n");


    for (int i=0; i<10; i++){
        
        printf("%d \t %d \t %d \t %d \t %d \t %d\n", i+1, student[i][0], student[i][1], student[i][2], total[i], total[i]/3);

    }
}


