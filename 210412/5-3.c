/*수식의 괄호 쌍을 검사하는 프로그램*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element; //스택의 변수를 char 형으로 선언 
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

/*-- 스택을 연결 리스트로 구현한 코드와 같은 부분--*/

//수식의 괄호를 검사하는 연산 
int testPair(char *exp){
    char symbol, open_pair;
    int i, length=strlen(exp); //char형 포인터 매개변수로 받은 수식 exp의 길이를 계산하여 length 변수에 저장 
    top=NULL;

    for(i=0; i<length; i++){
        symbol=exp[i]; //exp 문자열의 요소를 차례로 symbol에 넣어 switch문 실행 
        switch(symbol){
            case '(':
            case '[':
            case '{':
            push(symbol); break; //해당 괄호를 스택으로 push

            case ')':
            case ']':
            case '}': //닫히는 괄호가 있는 경우 
            if(top==NULL) return 0;
            else{
                open_pair = pop(); //open_pair에 가장 최근 읽은 기호를 pop해서 저장할 것 
                if((open_pair=='(' &&symbol != ')')||
                (open_pair=='['&&symbol != ']')||
                (open_pair=='{'&&symbol != '}')) return 0; //수식의 괄호 쌍이 맞지 않는 경우 수식 오류 -- return 0;

                else break; //수식의 괄호 쌍이 맞는 경우 break; (계속해서 검사를 진행함)
            }
        }
    }

    if(top==NULL) return 1; //top == NULL : 모든 괄호가 pop되었음 (즉, 모든 수식이 올바르게 사용됨)
    else return 0; //수식 오류 
}

void main(void){
    char* express="{(A+B)-3}*5+[{cos(x+y)+7}-1]*4";
    printf("%s", express);

    if(testPair(express)==1){
        printf("\n\n 수식의 괄호가 맞게 사용되었습니다.\n");
    }
    else printf("\n\n 수식의 괄호가 틀렸습니다.\n");
}