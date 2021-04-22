/*원형 연결 리스트 프로그램*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//node를 생성하는 구조체 
typedef struct ListNode{
    char data[4]; //데이터 영역 
    struct ListNode* link; //링크 영역 (다음 노드의 주소지)
}listNode; //구조체변수 

typedef struct{
    listNode* head; //헤드노드를 생성하는 구조체변수 
}linkedList_h;

//공백 연결 리스트를 생성 
linkedList_h* createLinkedList_h(void){
    linkedList_h* CL;
    CL = (linkedList_h*)malloc(sizeof(linkedList_h));
    CL -> head = NULL; //공백 연결 리스트이므로 NULL 
    return CL;
}

//원형 연결 리스트를 출력
void printList(linkedList_h* CL){
    listNode* p; //노드를 가리킬 임시 포인터 p를 선언 
    printf("CL = (");
    p=CL->head; //연결 리스트 CL의 헤드 노드

    //일단 한번 실행함 
    do{
        printf("%s", p->data); //포인터가 가리키는 데이터 (첫 시도에는 head노드의 데이터)를 출력 
        p=p->link; //헤드 노드의 다음 노드를 가리킴 
        if(p!=CL->head) printf(", "); //헤드노드가 아니면 , 출력 
    }while(p!=CL->head); //근데 이제 헤드노드가 아닐 때 반복하는 
    printf(") \n"); 
}
//원형 연결 리스트이므로 반복 후 다시 헤드 노드로 돌아오면 반복을 종료함 !!

//첫번째 노드를 삽입하는 연산
void insertFirstNode(linkedList_h* CL, char* x){
    listNode* newNode, *temp;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x); //data x를 newNode의 data에 삽입 
    if(CL->head==NULL){ //헤드 노드가 비어있을 시 (공백 리스트인 경우)
        CL->head = newNode; //헤드 노드가 newNode
        newNode->link=newNode; //노드의 다음 노드 역시 newNode(원형이므로)
    }
    else{ //공백 리스트가 아닌 경우 
        temp=CL->head; //임시 포인터 temp가 헤드 노드를 가리킴 
        while(temp->link!=CL->head) temp=temp->link; //temp의 다음 노드가 헤드 노드가 아니라면 (temp가 마지막 노드가 아닐 때) temp=temp->link (계속 다음 노드를 가리킴. 마지막까지)
        newNode->link = temp->link; //newNode의 링크값 = temp가 가진 주소값 newNode data == x, link == temp->link
        temp->link=newNode; //마지막 노드를 첫번째 노드인 new와 원형 연결 (마지막 노드를 가리키는 포인터 temp의 다음 노드가 newNode가 됨 (첫번째 노드))
        CL->head=newNode;
    }
}

//pre 뒤에 노드를 삽입하는 연산
void insertMiddleNode(linkedList_h* CL, listNode* pre, char* x){ //삽입할 리스트, 삽입 위치의 이전 노드, 데이터 
    listNode* newNode; //삽입할 노드 
    newNode=(listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    if(CL==NULL){ //공백 리스트인 경우 
        CL->head=newNode; //헤드 노드가 newNode가 됨
        newNode->link=newNode; //new노드의 다음 노드도 newNode가 됨 (원형 리스트)
    }
    else{
        newNode->link=pre->link; //newNode의 다음 노드가 이전 노드의 다음 노드가 되어야 함 (pre, newNode, node 순서이므로...) 
        pre->link=newNode; //pre의 다음 노드는 newNode가 된다 
    }
}

//원형 연결 리스트의 pre 뒤에 있는 노드 old를 삭제하는 연산
void deleteNode(linkedList_h* CL, listNode* old){
    listNode* pre; //위치를 알려줄 노드 pre
    if(CL->head==NULL) return; //공백 리스트인 경우 return
    if(CL->head->link==CL->head){ //노드가 하나뿐인 경우 
        free(CL->head); //할당 해제 
        CL->head=NULL; //NULL
        return;
    }
    else if(old==NULL) return; //삭제할 노드가 없는 경우 return
    else{
        pre=CL->head; //pointer pre를 시작 노드에 연결
        while(pre->link!=old){ //pre가 삭제할 노드의 이전 노드가 될 때 까지
            pre=pre->link; //계속해서 다음 노드를 가리킴 
        }
        pre->link=old->link; //삭제할 노드의 다음 노드를 pre의 다음 노드로 지정한다 
        if(old==CL->head) CL->head=old->link; //삭제할 노드가 헤드 노드라면 old의 다음 노드가 헤드 노드가 된다 
        free(old); //old 노드를 할당 해제 
    }
}

//원형 연결 리스트에서 x 노드를 탐색하는 연산
listNode* searchNode(linkedList_h* CL, char* x){
    listNode* temp; //탐색을 위한 임시 포인터 
    temp=CL->head; //head 노드부터 탐색 시작 
    if(temp==NULL) return NULL; //공백 리스트인 경우 NULL 반환 
    do{
        if(strcmp(temp->data, x)==0) return temp; //탐색하는 노드와 찾을 데이터가 같은 경우 해당 노드를 반환
        else temp=temp->link; //다음 노드로 이동
    }while (temp!=CL->head); //temp가 head 노드로 다시 돌아올 때 까지 반복 
    return NULL;
}

int main(){
    linkedList_h* CL;
    listNode* p;
    CL=createLinkedList_h();
    printf("(1) 원형 연결 리스트 생성하기\n");
    
    printf("(2) 원형 연결 리스트에 [월] 노드 삽입하기\n");
    insertFirstNode(CL, "월");
    printList(CL);

    printf("(3) 원형 연결 리스트의 [월] 노드 뒤에 [수] 노드 삽입하기\n");
    p=searchNode(CL, "월");
    insertMiddleNode(CL, p, "수");
    printList(CL);

    printf("(4) 원형 연결 리스트의 [수] 노드 뒤에 [금] 노드 삽입하기\n");
    p=searchNode(CL, "수");
    insertMiddleNode(CL, p, "금");
    printList(CL);

    printf("(5) 원형 연결 리스트에서 [수] 노드 삭제하기\n");
    p=searchNode(CL, "수");
    deleteNode(CL, p);
    printList(CL);

    return 0;
}

