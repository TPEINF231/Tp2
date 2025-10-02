
#include <stdio.h>
#include <stdlib.h>

// Définition de la structure d'un nœud
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fonction pour créer un nouveau nœud
Node* creerNoeud(int valeur) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    newNode->data = valeur;
    newNode->next = NULL;
    return newNode;
}

// Insertion en fin de liste
void insererFin(Node** head, int valeur) {
    Node* newNode = creerNoeud(valeur);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Fonction pour afficher la liste
void afficherListe(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Fonction pour supprimer toutes les occurrences d'un élément
void supprimerOccurrences(Node** head, int valeur) {
    Node* temp = *head;
    Node* prev = NULL;

    // Supprimer les occurrences en début de liste
    while (temp != NULL && temp->data == valeur) {
        *head = temp->next;
        free(temp);
        temp = *head;
    }

    // Parcours du reste de la liste
    while (temp != NULL) {
        if (temp->data == valeur) {
            prev->next = temp->next;
            free(temp);
            temp = prev->next;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

// Programme principal
int main() {
    Node* head = NULL;
    int n, valeur, x;

    printf("Combien d'elements dans la liste ? ");
    scanf("%d", &n);

    printf("Entrez les elements :\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &valeur);
        insererFin(&head, valeur);
    }

    printf("Liste initiale : ");
    afficherListe(head);

    printf("Entrez la valeur a supprimer : ");
    scanf("%d", &x);

    supprimerOccurrences(&head, x);

    printf("Liste apres suppression de %d : ", x);
    afficherListe(head);

    return 0;
}