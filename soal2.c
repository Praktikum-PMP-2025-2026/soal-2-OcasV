#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

void inputList(Node *head, int *size) {
    int N;
    scanf("%d", &N);
    *size = N;
    Node *HeadList = head;
    
    for (int i=0; i<N; i++) {
        scanf("%d", &head->data);
        
        if (i == N-1) {
            head->next = NULL;
        } else {
            head->next = malloc(sizeof(Node));
            head = head->next;
        }
    }
    head = HeadList;
}

void sortList(Node *list, int N) {
    int temp;

    Node *head = list;

    for (int i=0; i<N-1; i++) {
        list = head;
        for (int j=0; j<N-1-i; j++) {            
            temp = list->next->data;
            if (list->data > temp) {
                temp = list->next->data;
                list->next->data = list->data;
                list->data = temp;
            }
            list = list->next;
        }
    }
}

void sortDoubleList(Node *List1, int N1, Node *List2, int N2, Node *result) {
    for (int i=0; i<N1+N2; i++) {
        if (List1 == NULL) {
            result->data = List2->data;
            List2 = List2->next;
        } else if (List2 == NULL) {
            result->data = List1->data;
            List1 = List1->next;
        } else if (List1->data < List2->data) {
            result->data = List1->data;
            List1 = List1->next;
        } else if (List1->data > List2->data){
            result->data = List2->data;
            List2 = List2->next;
        }

        if (i == N1+N2-1) {
            result->next = NULL;
        } else {
            result->next = malloc(sizeof(Node));
            result = result->next;
        }
    }
}

void printList(Node *head, int N) {
    for (int i=0; i<N; i++) {
        if (head == NULL) {
            printf("null\n");
        }
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int N1, N2;
    Node *List1 = malloc(sizeof(Node));
    List1->data = 0, List1->next = NULL;
    Node *List2 = malloc(sizeof(Node));
    List2->data = 0, List2->next = NULL;
    Node *Result = malloc(sizeof(Node));
    Result->data = 0, Result->next = NULL;

    inputList(List1, &N1);
    inputList(List2, &N2);

    sortList(List1, N1);
    sortList(List2, N2);

    sortDoubleList(List1, N1, List2, N2, Result);
    printList(Result, N1+N2);

    return 0;
}
