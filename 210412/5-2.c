/*연결 자료구조를 이용한 스택의 구현*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*스택의 원소 -> 연결 리스트의 노드
  원소의 순서 -> 연결 리스트 노드의 링크
  스택의 top -> 포인터 top(NULL로 설정)*/
typedef int element;

//스택의 노드를 구조체로 정의 
typedef struct stackNode{
    element data;
    struct stackNode *link;
}stackNode;

//스택의 top 노드를 지정하기 위한 pointer 
stackNode* top;

int isEmpty(){
    if(top==NULL) return 1;
    else return 0;
}

//스택에 노드를 추가하는 연산 
void push(element item){
    stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
    temp->data=item; //pointer temp가 가리키는 data = 새로 입력된 변수 (스택에 쌓임)
    temp->link=top; //pointer temp가 가리키는 link = top (새로 입력된 변수의 순서 - 항상 새로 들어오는 것이 top)
    top=temp; // 새로 추가된 node의 주소값이 top이 된다 
}

//스택에서 노드를 삭제하는 연산 
element pop(){
    element item;
    stackNode* temp=top; //가장 위에 있는 노드(top)부터 pop하기 때문에 pointer temp가 top노드를 가리키도록 한다 

    if(top==NULL){ //비어있는 스택인 경우 
        printf("\n\n Stack is empty\n");
        return 0;
    }
    else{
        item=temp->data; //삭제할 노드의 데이터 값을 item에 저장(반환 용도)
        top=temp->link; //top노드가 다음 노드가 됨 (한 칸 아래 노드)
        free(temp); //삭제된 값을 가리키는 포인터 temp를 할당 해제해준다 
        return item; //삭제된 값 item을 반환 
    }
}

element peek(){
    if(top==NULL){ //공백 스택인 경우 
        printf("\n\n Stack is empty\n");
        return 0;
    }
    else{
        return (top->data); //top이 가리키는 데이터 (가장 위에 쌓인 데이터)
    }
}

void printStack(){
    stackNode* p = top; //포인터 p 선언 (top에서부터 시작)
    printf("\n STACK [ ");
    while(p){ //연결 스택에 노드가 있는 동안 ... (NULL이 될 때 까지? 인듯)
        printf("%d", p->data);
        p=p->link; //아래로 한칸씩 내려가면서 노드의 데이터를 출력 
    }
    printf(" ] ");
}

void main(void){
    element item;
    top=NULL;
    printf("\n ** 연결 스택 연산 ** \n");
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

}