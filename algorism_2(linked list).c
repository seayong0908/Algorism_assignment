#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode-> data = data;
    newNode-> next = NULL;
    return newNode;
}


void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

void insertAtPosition(Node**head, int data, int position) {
    Node* newNode = createNode(data);

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* temp = *head;

    for (int i = 1; i< position - 1 && temp != NULL; i++) {
        temp = temp-> next;
    }

    if(temp == NULL) {
        printf("삽입 위치가 잘못되었습니다.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

int main(void) {

    Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    printf("초기 리스트: ");
    printList(head);

    insertAtPosition(&head, 15, 2);
    printList(head);

    return 0;
}