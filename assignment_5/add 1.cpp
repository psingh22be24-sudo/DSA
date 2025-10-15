#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* newNode(int v){
    Node* n = malloc(sizeof(Node)); n->data = v; n->next = NULL; return n;
}

Node* getIntersection(Node* headA, Node* headB){
    if (!headA || !headB) return NULL;
    Node *a = headA, *b = headB;
    while (a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }
    return a; 
}


void printList(Node* h){
    while(h){ printf("%d", h->data); if(h->next) printf("->"); h=h->next; }
    printf("\n");
}

int main(void){
   
    Node *headA = newNode(1);
    headA->next = newNode(2);
    headA->next->next = newNode(3);

    Node *headB = newNode(4);
    headB->next = newNode(5);
    headB->next->next = newNode(6);

    
    Node *shared = newNode(8);
    shared->next = newNode(9);

    
    headA->next->next->next = shared;   
    headB->next->next->next = shared;   

    printf("List A: "); printList(headA);
    printf("List B: "); printList(headB);

    Node *intr = getIntersection(headA, headB);
    if (intr) printf("Intersection at node with value: %d\n", intr->data);
    else     printf("No intersection (NULL)\n");

    return 0;
}
