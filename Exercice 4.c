#include <stdio.h>
#include <stdlib.h>

// Définition d’un nœud
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Fonction pour insérer en tête
void insertHead(Node **head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;

    if (*head == NULL) {
        // Liste vide
        newNode->next = newNode;
        *head = newNode;
    } else {
        Node *temp = *head;
        // Trouver le dernier nœud
        while (temp->next != *head) {
            temp = temp->next;
        }
        // Insertion
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
}

// Fonction pour insérer en queue
void insertTail(Node **head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;

    if (*head == NULL) {
        // Liste vide
        newNode->next = newNode;
        *head = newNode;
    } else {
        Node *temp = *head;
        // Trouver le dernier nœud
        while (temp->next != *head) {
            temp = temp->next;
        }
        // Insertion
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Afficher la liste circulaire
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

// Programme principal
int main() {
    Node *head = NULL;

    // Insertion en tête
    insertHead(&head, 10);
    insertHead(&head, 20);
    insertHead(&head, 30);
    printf("Après insertions en tête :\n");
    display(head);

    // Insertion en queue
    insertTail(&head, 40);
    insertTail(&head, 50);
    printf("Après insertions en queue :\n");
    display(head);

    return 0;
}

    