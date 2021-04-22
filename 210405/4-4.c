#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//이중 연결 리스트의 노드를 구조체로 구현
typedef struct ListNode{
    struct ListNode* llink; //이전 노드의 주소지
    char data[4];
    struct ListNode* rlink; //다음 노드의 주소지
}listNode;

//head노드를 구조체로 정의
typedef struct{
    listNode* head;
}linkedList_h;

//공백 이중 연결 리스트를 생성 
linkedList_h* createLinkedList_h(void){
    linkedList_h* DL;
    DL = (linkedList_h*)malloc(sizeof(linkedList_h)); //헤드 노드 할당
    DL->head = NULL; //공백 리스트이므로 NULL
    return DL;
}

//이중 연결 리스트를 순서대로 출력하는 연산 
void printList(linkedList_h* DL){
    listNode* p;
    printf("DL = (");
    p=DL->head;
    while (p!=NULL){
        printf("%s", p->data);
        p=p->rlink;
        if(p!=NULL) printf(", ");
    }

    printf(") \n");
}

//pre 뒤에 노드를 삽입하는 연산 
void insertNode(linkedList_h* DL, listNode* pre, char* x){
    listNode* newNode;
    newNode=(listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    
    //공백 리스트인 경우 
    if(DL->head==NULL){
        newNode->rlink=NULL; //좌, 우 링크가 모두 비어 있음 
        newNode->llink=NULL;
        DL->head=newNode; //newNode가 headNode
    }
    else{
        newNode->rlink=pre->rlink; //newNode의 오른쪽 링크 칸에 pre 노드의 오른쪽 링크를 줌 
        pre->rlink=newNode; //pre의 rlink 칸에는 newNode의 주소지를 할당한다 
        newNode->llink=pre; //newNode의 llink 칸에는 pre의 주소지를 할당한다 
        if(newNode->rlink!=NULL) newNode->rlink->llink=newNode; //newNode의 다음 노드의 llink에는 newNode를 할당한다 
    }
}

//이중 연결 리스트에서 old 노드를 삭제하는 연산 
void deleteNode(linkedList_h* DL, listNode* old){
    if(DL->head == NULL) return; //공백 리스트인 경우 return
    else if(old==NULL) return; //삭제할 노드가 없는 경우 return
    else{
        old->llink->rlink=old->rlink; //삭제할 노드의 이전 노드의 rlink에 삭제할 노드의 rlink값을 전달 
        old->rlink->llink=old->llink; //삭제할 노드의 다음 노드의 llink에 삭제할 노드의 llink값을 전달 
        free(old); //할당 해제 
    }
}

//리스트에서 x 노드를 탐색하는 연산 
listNode* searchNode(linkedList_h* DL, char* x){ 
    listNode* temp; //노드를 탐색할 임시 포인터 변수 temp
    temp=DL->head; //헤드 노드부터 탐색 시작 
    while(temp!=NULL){ //temp가 NULL이 될 때 까지 (마지막 노드의 rlink까지)
        if(strcmp(temp->data, x)==0) return temp; //temp가 가리키는 data가 x와 같으면 temp return
        else temp=temp->rlink; //계속해서 오른쪽 노드를 가리킴 
    }
    return temp;
}

int main(){
    linkedList_h* DL;
    listNode* p;
    DL=createLinkedList_h();
    printf("(1) 이중 연결 리스트 생성하기\n");
    printList(DL);

    printf("(2) 이중 연결 리스트에 [월] 노드 삽입하기\n");
    insertNode(DL, NULL, "월");
    printList(DL);

    printf("(3) 이중 연결 리스트의 [월] 노드 뒤에 [수] 노드 삽입하기\n");
    p=searchNode(DL, "월"); 
    insertNode(DL, p, "수");
    printList(DL);

    printf("(4) 이중 연결 리스트의 [수] 노드 뒤에 [금] 노드 삽입하기\n");
    p=searchNode(DL, "수");
    insertNode(DL, p, "금");
    printList(DL);

    printf("(5) 이중 연결 리스트에서 [수] 노드 삭제하기\n");
    p=searchNode(DL, "수");
    deleteNode(DL, p);
    printList(DL);
    
    return 0;

}