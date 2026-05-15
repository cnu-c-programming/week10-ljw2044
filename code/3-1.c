#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[100];
    int score;
    struct Student* next;
};

struct Student* head = NULL;

void add(char name[], int score) {
    struct Student* newNode =
        (struct Student*)malloc(sizeof(struct Student));

    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Student* curr = head;

    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = newNode;
}

void delete(char name[]) {
    struct Student* curr = head;
    struct Student* prev = NULL;

    while (curr != NULL) {

        if (strcmp(curr->name, name) == 0) {

            if (prev == NULL) {
                head = curr->next;
            }
            else {
                prev->next = curr->next;
            }

            free(curr);
            return;
        }

        prev = curr;
        curr = curr->next;
    }
}

void printList() {
    struct Student* curr = head;

    while (curr != NULL) {
        printf("%s %d\n",
               curr->name,
               curr->score);

        curr = curr->next;
    }
}

void freeList() {
    struct Student* curr = head;

    while (curr != NULL) {
        struct Student* temp = curr;

        curr = curr->next;

        free(temp);
    }
}

int main() {

    char command[100];

    while (1) {

        scanf("%s", command);

        if (strcmp(command, "add") == 0) {

            char name[100];
            int score;

            scanf("%s %d", name, &score);

            add(name, score);
        }

        else if (strcmp(command, "delete") == 0) {

            char name[100];

            scanf("%s", name);

            delete(name);
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
