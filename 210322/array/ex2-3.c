#include <stdio.h>

void main(){
    int i=0, n;
    int mul[9];

    printf("1~9 정수 입력 : ");

    while(1){
        scanf("%d", &n); //n에 정수를 할당받음 
        if(n<0||n>9) printf("1~9의 정수 입력 : ");
        else break;
    }

    printf("\n");
    for (i=0; i<9; i++){
        mul[i]=n*(i+1); //할당받은 정수 * 1~9까지를 mul 배열에 저장 
        printf("%d * %d = %d\n", n, (i+1), mul[i]); //출력 
    }
}