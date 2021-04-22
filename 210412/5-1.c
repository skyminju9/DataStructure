#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

typedef int element; //스택 원소의 자료형을 int로 정의
element stack[STACK_SIZE]; //1차원 배열 스택 선언 
int top=-1; //top 초기화

//스택이 비어있는지 확인하는 연산 
/*스택의 top에는 0~(n-1)까지 인덱스를 저장하므로,
스택의 초기 상태 (공백 상태) 에서는 -1을 저장한다.*/
int isEmpty(){
    if(top==-1) return 1;
    else return 0;
}

//스택이 포화 상태인지 확인하는 연산 
/*스택이 포화 상태인 경우, 만약 stack size가 100이라면
99번 인덱스까지 스택이 차 있어야 함 ! 
따라서 top == STACK_SIZE-1일 때가 포화 상태*/
int isFull(){
    if(top==STACK_SIZE-1) return 1;
    else return 0;
}

//스택에 변수를 삽입하는 연산 
void push(element item){
    if(isFull()){ //만약 스택이 포화 상태라면 (if (true)와 같은... 느낌?인듯?)
        printf("\n\n Stack is Full\n");
        return;
    }
    else stack[++top]=item; //스택이 포화 상태가 아니라면 stack[0]부터 차례대로 변수를 삽입 
}

//스택에서 변수를 삭제하는 연산
element pop(){
    if(isEmpty()){ //스택이 비어있는 경우
        printf("\n\n Stack is Empty\n");
        return 0;
    }
    else return stack[top--]; //스택이 비어있지 않은 경우 stack의 가장 최근 원소부터 삭제함 
}

//스택의 top 원소를 검색하는 연산
element peek(){
    if(isEmpty()){ //스택이 비어있는 경우
        printf("\n\n Stack is Empty\n");
        exit(1);
    }
    else return stack[top]; //비어있지 않으면 top을 출력 
}

//스택을 출력하는 연산 
void printStack(){
    int i;
    printf("\n STACK [ ");
    for(i=0; i<=top; i++){
        printf("%d", stack[i]);
    }
    printf(" ] ");
}

void main(void){

    element item;
    printf("\n ** 순차 스택 연산 ** \n");
    printStack();
    push(1); printStack();
    push(2); printStack();
    push(3); printStack();

    item=peek(); printStack();
    printf("peek => %d", item);

    item=pop(); printStack();
    printf("\t pop => %d", item);

    item=pop(); printStack();
    printf("\t pop => %d", item);

    item=pop(); printStack();
    printf("\t pop => %d", item);

    item=pop(); printStack();
    printf("\t pop => %d\n", item);

}