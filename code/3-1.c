#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    int score;
    struct Node* next;
} Node;

Node* head = NULL;

void addlastname(char name[], int score) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = newNode;
}

void deletelastname(char name[]) {
    Node* cur = head;
    Node* prev = NULL;

    while (cur != NULL) {
        if (strcmp(cur->name, name) == 0) {
            if (prev == NULL) {
                head = cur->next;
            } else {
                prev->next = cur->next;
            }
            free(cur);
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}



int main() {
    char command[20];
    char name[50];
    int score;

    while (1) {
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%s %d", name, &score);
            addlastname(name, score);
        }
        else if (strcmp(command, "delete") == 0) {
            scanf("%s", name);
            deletelastname(name);
        }
        else if (strcmp(command, "print") == 0) {
            printList();
        }
        else if (strcmp(command, "quit") == 0) {
            freeList();
            break;
        }
    }

    return 0;
}
