#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *next;
} Node;


void insertHead(Node **head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;

    if (*head == NULL) {
        
        newNode->next = newNode;
        *head = newNode;
    } else {
        Node *temp = *head;
        
        while (temp->next != *head) {
            temp = temp->next;
        }
        
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
}


void insertTail(Node **head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;

    if (*head == NULL) {
        
        newNode->next = newNode;
        *head = newNode;
    } else {
        Node *temp = *head;
        
        while (temp->next != *head) {
            temp = temp->next;
        }
        
        temp->next = newNode;
        newNode->next = *head;
    }
}


void display(Node *head) {
    if (head == NULL) {
        printf("Liste vide\n");
        return;
    }
    Node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(retour au début)\n");
}

int main() {
    Node *head = NULL;

    
    insertHead(&head, 10);
    insertHead(&head, 20);
    insertHead(&head, 30);
    printf("Après insertions en tête :\n");
    display(head);

    
    insertTail(&head, 40);
    insertTail(&head, 50);
    printf("Après insertions en queue :\n");
    display(head);

    return 0;
}

    