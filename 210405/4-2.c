/*단순 연결 리스트 프로그램2*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

//마지막 노드를 삽입하는 연산 
void insertLastNode(linkedList_h* L, char* x){
    listNode* newNode; 
    listNode* temp; //이전 노드들의 link값을 받아 노드를 순회할 임시 포인터 
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);
    newNode->link=NULL; //newNode는 마지막 노드이므로 link값이 NULL이어야 함 
    
    if(L -> head == NULL){ //head노드가 비어있는 경우 newNode가 처음이자 마지막 노드가 됨   
        L -> head = newNode; //head노드가 newNode
        return;
    }

    temp = L -> head; //temp는 L의 head노드에서부터 시작 
    while(temp->link != NULL) temp = temp -> link; //temp의 다음 노드가 없을 때 까지 (마지막 노드가 될 때 까지) temp는 다음 노드의 주소지를 가짐 
    temp -> link = newNode; //temp가 마지막 노드가 되면 temp의 다음 노드는 newNode가 된다 (newNode가 마지막 노드)

}

//리스트에서 노드 p를 삭제하는 연산 
void deleteNode(linkedList_h* L, listNode* p){
    listNode* pre; //삭제할 노드의 선행 노드 
    if(L -> head == NULL) return; //공백 리스트인 경우 return으로 탈출
    if(L->head->link == NULL){ //리스트에 노드가 한개만 있는 경우 
        free(L->head); //첫번째 노드를 메모리에서 할당 해제 
        L->head=NULL; //리스트 시작 포인터를 NULL로 설정 
        return;
    }

    else if(p==NULL) return; //삭제할 노드가 NULL인 경우 (삭제할 노드가 없음) return;
    else{
        pre=L->head; //삭제할 노드의 선행 노드를 pointer pre를 통해 찾음 
        while(pre->link != p){ //선행 노드의 다음 노드가 p가 아닐 때 
            pre=pre->link;  //pre노드가 그 다음 노드로 바뀜 (한칸씩 뒤로... p의 선행노드가 될 때 까지 진행)
        }

        pre->link=p->link; //삭제할 노드 p의 선행 노드와 다음 노드를 연결 
        free(p); //삭제 노드의 메모리 해제 
    }
}

//리스트에서 x 노드를 탐색하는 연산 
listNode* searchNode(linkedList_h* L, char* x){ 
    listNode *temp; //노드를 탐색할 임시 포인터 temp
    temp=L->head; //temp는 헤드 노드부터 시작함 
    while(temp!=NULL){ //헤드 노드가 NULL이 아닐 때 (마지막 노드가 될 때 까지)
        if(strcmp(temp->data, x)==0) return temp; //temp가 가리키는 데이터가 x와 같을 때 temp를 리턴
        else temp = temp->link; //temp와 x가 같은 데이터가 아니라면 그 다음 노드로 이동해 while문을 다시 반복 
    }
    return temp; //temp를 리턴 
}
 
//리스트의 노드 순서를 역순으로 바꾸는 연산 
void reverse(linkedList_h* L){ 
    listNode* p;
    listNode* q;
    listNode* r;

    p = L->head; //포인터 p를 첫번째 노드에 설정
    q = NULL;
    r = NULL;

//리스트의 첫번째 노드부터 링크를 따라 다음 노드로 이동하면서 노드 간 연결을 바꿈 
    while(p!=NULL){ //헤드 노드가 NULL이 아니면 
        r=q;
        q=p;
        p=p->link;
        q->link=r;
    }
    
    L->head=q;
}

int main(){
    linkedList_h* L;
    listNode* p;
    L = createLinkedList_h();

    printf("(1) 리스트에 [월], [수], [일] 노드 삽입하기 \n");
    insertLastNode(L, "월"); 
    insertLastNode(L, "수");
    insertLastNode(L, "일");
    printList(L);
    
    printf("(2) 리스트에서 [수] 노드 탐색하기\n");
    p = searchNode(L, "수");
    if(p==NULL) printf("찾는 데이터가 없습니다\n");
    else printf("[%s]를 찾았습니다.\n", p->data);

    printf("(3) 리스트에서 [수] 뒤에 [금] 노드 삽입하기\n");
    insertMiddleNode(L, p, "금");
    printList(L);

    printf("(4) 리스트에서 [일] 노드 삭제하기 \n");
    p=searchNode(L, "일");
    deleteNode(L, p);
    printList(L);

    printf("(5) 리스트 순서를 역순으로 바꾸기\n");
    reverse(L);
    printList(L);

    freeLinkedList_h(L);
    return 0;

}