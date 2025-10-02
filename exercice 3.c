#include<stdio.h>
#include <stdlib.h>
// Structure pour un nœud de la liste doublement chaînée
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;
// Fonction pour créer un nouveau nœud
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erreur d'allocation de mémoire\n");
        return NULL;
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
// Fonction pour insérer un élément dans une liste doublement chaînée triée
void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL || (*head)->data >= newNode->data) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->prev = current;
        newNode->next = current->next;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }
}

// Fonction pour afficher la liste
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Insertion de quelques éléments
    insertNode(&head, 10);
    insertNode(&head, 5);
    insertNode(&head, 15);
    insertNode(&head, 3);
    insertNode(&head, 8);

    // Affichage de la liste
    printf("Liste : ");
    printList(head);

    return 0;
}