#include <stdio.h>
#include <stdlib.h>
// Définition d’un nœud
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;
// Fonction pour créer un nouveau nœud
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}
// Insertion en tête
void insertHead(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        // Premier élément → se relie à lui-même
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
        return;
    }
    Node* last = (*head)->prev;
    newNode->next = *head;
    newNode->prev = last;
    last->next = newNode;
    (*head)->prev = newNode;
    *head = newNode;  // mise à jour de la tête
}
// Insertion en queue
void insertTail(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
        return;
    }
    Node* last = (*head)->prev;
    newNode->next = *head;
    newNode->prev = last;
    last->next = newNode;
    (*head)->prev = newNode;
}
// Affichage de la liste
void display(Node* head) {
    if (head == NULL) {
        printf("Liste vide\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(retour à la tête)\n");
}
// Programme principal
int main() {
    Node* head = NULL;
    insertHead(&head,5 );
    insertHead(&head, 8);
    insertTail(&head, 1);
    insertTail(&head, 0);
    display(head);
    return 0;
}