#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct stackNode{
    element data;
    struct stackNode *link;
}stackNode;

stackNode* top;

int isEmpty(){
    if(top==NULL) return 1;
    else return 0;
}

void push(element item){
    stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
    temp->data=item;
    temp->link=top;
    top=temp;
}

element pop(){
    element item;
    stackNode* temp=top;

    if(top==NULL){
        printf("\n\n Stack is empty\n");
        return 0;
    }
    else{
        item=temp->data;
        top=temp->link;
        free(temp);
        return item;
    }
}

/*--스택을 연결 리스트를 이용하여 표현한 부분--*/

element evalPostfix(char* exp){
    int opr1, opr2, value, i=0;
    int length = strlen(exp); //입력된 수식의 길이
    char symbol;
    top=NULL;

    for (i=0; i<length; i++){
        symbol = exp[i];
        if(symbol != '+'&&symbol != '-' && symbol != '*' && symbol != '/'){ //입력된 문자가 숫자인 경우 
            value = symbol - '0'; //symbol에 저장된 char형 값에서 '0'을 뺀 값, 즉 숫자 코드값으로 변환하여 int형 변수 value에 저장
            push(value);
        }
        else{ //입력된 문자가 기호인 경우 
            opr2=pop(); //숫자를 위에서부터 (최근 쌓인 것부터) pop하여 opr 1, 2에 저장함 
            opr1=pop();

            switch(symbol){
                case '+': push(opr1+opr2); break;
                case '-': push(opr1-opr2); break;
                case '*': push(opr1*opr2); break;
                case '/': push(opr1/opr2); break;
            }
        }
    }

    return pop(); //수식 exp에 대한 처리를 마친 후 스택에 남아있는 결과값을 pop하여 반환함 
}

void main(void){
    int result;
    char* express = "35*62/-";
    printf("후위 표기식 : %s", express);
    
    result = evalPostfix(express);
    printf("\n\n 연산 결과 => %d\n", result);

}