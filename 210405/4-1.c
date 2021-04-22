/*단순 연결리스트 프로그램1*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode{

    char data[4]; //data 영역을 char로 할당 
    struct ListNode* link; //link영역을 ListNode의 포인터로 주소지를 할당 

} listNode; 

typedef struct { //리스트의 시작을 나타내는 head 노드를 구조체로 정의

    listNode* head; //listNode* 형 변수 head (가장 첫번째 노드)

}linkedList_h; //head노드의 구조체변수 linkedList_h를 선언 

//공백 연결 리스트를 생성하는 연산 
linkedList_h* createLinkedList_h(void){
    linkedList_h* L; //공백 리스트 L 생성  
    L = (linkedList_h*)malloc(sizeof(linkedList_h)); //L을 linkedList_h 크기만큼 동적 할당
    L -> head = NULL; //공백 리스트이므로 L의 헤드노드는 NULL
    return L;
}

//연결 리스트의 전체 메모리를 해제하는 연산
void freeLinkedList_h(linkedList_h* L){
    listNode* p; //listNode* p 선언 
    while(L->head != NULL){ //헤드노드가 NULL이 아닐 때 까지
        p = L -> head; //p에 head노드에 들어있는 것을 대입 
        L -> head = L -> head -> link; //head노드에 다음 데이터를 삽입 (데이터가 NULL일 때 까지 반복)
        free(p); //p를 할당 해제 
        p = NULL;
    }
}

//연결 리스트를 출력 
void printList(linkedList_h* L){
    listNode* p; //listNode* p declare
    printf("L=(");
    p = L -> head; //p에 head노드의 내용을 대입 
    while(p!=NULL){ //p가 비어있지 않으면 
        printf("%s", p->data); //p에 들어있는 데이터를 출력(head노드의 데이터)
        p=p->link;//p에 연결된 데이터를 삽입 (다음 데이터)
        if(p!=NULL) printf(", "); //p가 비어있지 않으면 출력 - while문 반복 (비어있을 때까지)
    }
    printf(") \n"); //p가 NULL이 되면 
}

// 첫번째 노드로 삽입하는 연산
void insertFirstNode(linkedList_h *L, char *x){
    listNode* newNode; //newNode를 선언 
    newNode = (listNode*)malloc(sizeof(listNode)); //listNode의 크기만큼 할당 
    strcpy(newNode->data, x); //newNode의 데이터 == x값 
    newNode -> link = L -> head; 
    L -> head = newNode; //headNode가 newNode(새롭게 생성된 노드)
}

// 노드를 pre 뒤에 삽입하는 연산
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x){ //pre는 노드의 삽입 위치를 지정하는 포인터
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode -> data, x);
    if(L==NULL){ //리스트가 공백 리스트인 경우 
        newNode -> link = NULL; //newNode의 link(다음 노드)는 비어있음 (마지막 노드임)
        L -> head = newNode; //공백 리스트 L의 head노드에 newNode의 주소지를 저장함 
    }
    else if (pre == NULL){ //pre가 비어있으면 
        L -> head = newNode; //headNode는 newNode
    }
    else{ //pre노드가 비어있지 않으면 (headNode가 존재하는 경우)
        newNode->link = pre->link; 
        pre->link = newNode; //pre의 다음 노드는 newNode
    }
}

void insertLastNode(linkedList_h* L, char* x){
    listNode* newNode; 
    listNode* temp;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    newNode->link=NULL;
    
    if(L -> head == NULL){
        L -> head = newNode;
        return;
    }

    temp = L -> head; //temp는 L의 head노드에서부터 시작 
    while(temp->link != NULL) temp = temp -> link; //temp의 다음 노드가 없을 때 까지 (마지막 노드가 될 때 까지) temp는 다음 노드의 주소지를 가짐 
    temp -> link = newNode; //temp가 마지막 노드가 되면 temp의 다음 노드는 newNode가 된다 (newNode가 마지막 노드 )

}

int main(){
    linkedList_h* L;
    L = createLinkedList_h();
    printf("(1) 공백 리스트 생성\n");
    printList(L);

    printf("(2) 리스트에 [수] 노드 삽입\n");
    insertFirstNode(L, "수");
    printList(L);

    printf("(3) 리스트 마지막에 [금] 노드 삽입\n");
    insertLastNode(L, "금");
    printList(L);

    printf("(4) 리스트 첫번째에 [월] 노드 삽입\n");
    insertFirstNode(L, "월");
    printList(L);

    printf("(5) 리스트 공간을 해제하여 공백 리스트로 만들기\n");
    freeLinkedList_h(L);
    printList(L);

    return 0;

}
//그림 그려보기 !!!! 