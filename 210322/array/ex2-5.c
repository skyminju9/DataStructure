#include <stdio.h>

void main(){
    int i, length=0;
    char str[50];
    printf("\n 문자열을 입력하세요: ");
    gets(str); //입력된 문자열을 str에 저장 
    printf("\n 입력된 문자열은 \n\"");
    for (i=0; str[i]; i++){ //배열에 저장된 문자열을 출력 
        printf("%c", str[i]);
        length += 1; //문자열의 길이를 세는 변수 
    }

    printf("\" \n입니다.");
    printf("\n\n 입력된 문자열의 길이 = %d\n", length);
}