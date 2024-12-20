// ===========================================
// SINGLY LINKED LIST
// TABLANTE, MIGUEL LORENZO F.
// 2024
// ===========================================

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int uiIfEmpty();
int uiIfNotEmpty();
Node* createNode(int data);                                     // RETURNS NEW NODE
void appendNode(Node **head, int data);                         // APPENDS CREATED NODE TO LIST
void printList(Node *head);                                     // PRINT CURRENT LIST
void deleteNode(Node **head, int position);                     // DELETES NODE
void insertNode(Node** head, int position, int data);

int main() {
    Node *head = NULL;                                          // START WITH LIST EMPTY
    bool exit = false;
    int data, check, pos;

    do {                                                        
        if (head == NULL) {                                     // DO IF LIST IS EMPTY
            int willDo = uiIfEmpty(), ask;

            switch (willDo) {                                   // ***************************************
                case 1:                                         // IF USER WANTS TO ADD NODE
                    printf("Enter number to add: ");
                    do {
                        check = scanf("%d", &data);
                        if (check != 1) {
                            printf("Invalid input! Please try again.\n");
                            printf("-> ");
                        }
                        else {
                            appendNode(&head, data);            // ADD NODE AFTER VALID INPUT
                        }
                    } while (check != 1);                       // ***************************************
                    printf("\nWould you like to continue?\n");  // ASK IF USER WANTS TO CONTINUE
                    printf("1. Yes\n");
                    printf("2. No\n");
                    printf("-> ");
                    do {
                        check = scanf("%d", &ask);
                        if (check != 1) {
                            while (getchar() != '\n');
                            printf("Invalid input! Please try again.\n");
                            printf("-> ");
                        }
                    } while (check != 1);
                    if (ask == 1) {
                        break;                                  // HEAD NOT NULL ANYMORE, CONTINUE (1)
                    }
                    else {
                        exit = true;                            // IF USER WANTS TO EXIT (2)
                        break;
                    }                                           // ***************************************
                case 2:
                    exit = true;
                    break;
            }
        }                                                       
        else {                                                  // DO IF LIST IS NOT EMPTY
            printf("\nCurrent List: ");
            printList(head);
            int willDo = uiIfNotEmpty(), ask;

            switch (willDo) {                                   // ---------------------------------------
                case 1:                                         // IF USER WANTS TO ADD NODE
                    printf("Enter number to add: ");
                    do {
                        check = scanf("%d", &data);
                        if (check != 1) {
                            while (getchar() != '\n');          // CLEAR INPUT BUFFER
                            printf("Invalid input! Please try again.\n");
                            printf("-> ");
                        }
                        else {
                            appendNode(&head, data);            // ADD NODE AFTER VALID INPUT
                        }
                    } while (check != 1);                       // ---------------------------------------
                    printf("\nWould you like to continue?\n");  // ASK IF USER WANTS TO CONTINUE
                    printf("1. Yes\n");
                    printf("2. No\n");
                    printf("-> ");
                    do {
                        check = scanf("%d", &ask);
                        if (check != 1) {
                            while (getchar() != '\n');
                            printf("Invalid input! Please try again.\n");
                            printf("-> ");
                        }
                    } while (check != 1);
                    if (ask == 1) {
                        break;                                  // HEAD NOT NULL ANYMORE, CONTINUE (1)
                    }
                    else {
                        exit = true;                            // IF USER WANTS TO EXIT (2)
                        break;
                    }                                           // ---------------------------------------
                case 2:                                         // =======================================
                    printf("\n");
                    printList(head);                            
                    printf("Enter node to delete: ");           // IF USER WANTS TO DELETE NODE
                    do {
                        check = scanf("%d", &pos);
                        if (check != 1 || pos <= 0) {
                            while (getchar() != '\n');          // CLEAR INPUT BUFFER
                            printf("Invalid input! Please try again.\n");
                            printf("-> ");
                        }
                        else {
                            deleteNode(&head, pos);            // DELETE NODE AFTER VALID INPUT
                        }
                    } while (check != 1 || pos <= 0);          // =======================================
                    printf("\nWould you like to continue?\n");  // ASK IF USER WANTS TO CONTINUE
                    printf("1. Yes\n");
                    printf("2. No\n");
                    printf("-> ");
                    do {
                        check = scanf("%d", &ask);
                        if (check != 1) {
                            while (getchar() != '\n');
                            printf("Invalid input! Please try again.\n");
                            printf("-> ");
                        }
                    } while (check != 1);
                    if (ask == 1) {
                        break;                                  // CONTINUE (1)
                    }
                    else {
                        exit = true;                            // IF USER WANTS TO EXIT (2)
                        break;
                    }                                           // =======================================
                case 3:
                    printf("Enter number to add: ");
                    do {
                        check = scanf("%d", &data);
                        if (check != 1) {
                            while (getchar() != '\n');          // CLEAR INPUT BUFFER
                            printf("Invalid input! Please try again.\n");
                            printf("-> ");
                        }
                    } while (check != 1);                       // ---------------------------------------
                    printf("Enter position to insert: ");       // ASK FOR INSERT POSITION OF NEW NODE
                    do {
                        check = scanf("%d", &pos);
                        if (check != 1 || pos <= 0) {
                            while (getchar() != '\n');          // CLEAR INPUT BUFFER
                            printf("Invalid input! Please try again.\n");
                            printf("-> ");
                        }
                        else {
                            insertNode(&head, pos, data);      // INSERT NEW NODE AFTER VALID INPUT
                        }
                    } while (check != 1 || pos <= 0);          // =======================================
                    printf("\nWould you like to continue?\n"); // ASK IF USER WANTS TO CONTINUE
                    printf("1. Yes\n");
                    printf("2. No\n");
                    printf("-> ");
                    do {
                        check = scanf("%d", &ask);
                        if (check != 1) {
                            while (getchar() != '\n');
                            printf("Invalid input! Please try again.\n");
                            printf("-> ");
                        }
                    } while (check != 1);
                    if (ask == 1) {
                        break;                                  // CONTINUE (1)
                    }
                    else {
                        exit = true;                            // IF USER WANTS TO EXIT (2)
                        break;
                    }                                           // =======================================
                case 4:
                    exit = true;
                    break;
            }
        }
    } while (exit != true);

    free(head);
    return 0;
}

int uiIfEmpty() {                                               // MENU IF LIST IS EMPTY
    printf("\nWelcome!\n");
    printf("List is currently empty...\n");
    printf("\nWhat would you like to do?\n");
    printf("1. Add a New Starting Node\n");
    printf("2. Exit\n");
    
    short int choice;
    printf("-> ");
    do {
        scanf("%hi", &choice);
        if (choice!= 1 && choice != 2) {
            while (getchar() != '\n');
            printf("Invalid input! Please try again.\n");
            printf("-> ");
        }
    } while (choice!= 1 && choice != 2);
    return choice;
}

int uiIfNotEmpty() {                                            // MENU IF LIST IS NOT EMPTY
    printf("What would you like to do?\n");
    printf("1. Add a New Node\n");
    printf("2. Delete a Node\n");
    printf("3. Insert new node\n");
    printf("4. Exit\n");

    short int choice;
    printf("-> ");
    do {
        scanf("%hi", &choice);
        if (choice!= 1 && choice != 2 && choice != 3) {
            while (getchar() != '\n');
            printf("Invalid input! Please try again.\n");
            printf("-> ");
        }
    } while (choice!= 1 && choice != 2 && choice != 3);
    return choice;
}

Node* createNode(int data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void appendNode(Node **head, int data) {
    if (*head == NULL) {
        Node *nodeToAppend = createNode(data);
        *head = nodeToAppend;
    }
    else {
        Node *current = *head;
        while (current && current->next != NULL) {
            current = current->next;
        }
        Node *nodeToAppend = createNode(data);
        current->next = nodeToAppend;
    }
}

void printList(Node *head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void deleteNode(Node **head, int position) {
    if (position == 1) {
        Node *newHead = *head;
        *head = newHead->next;
        free(newHead);
    }
    else {
        Node *current = *head;
        for (int i = 1; i < (position - 1); i++) {
            if (current == NULL) {
                printf("Invalid position! Node does not exist.\n");
                return;
            }
            current = current->next;
        }
        if (current->next == NULL) {
            printf("Invalid position! Node does not exist.\n");
            return;
        }
        Node *temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}

void insertNode(Node** head, int position, int data) {
    if (position == 1) {
        Node *newHead = createNode(data);
        *head = newHead;
    }
    else {
        Node *current = *head;
        for (int i = 1; i < (position - 1); i++) {
            if (current == NULL) {
                printf("Invalid position! Node does not exist.\n");
                return;
            }
            current = current->next;
        }
        Node *newNode = createNode(data);
        newNode->next = current->next;
        current->next = newNode;
    }
}
