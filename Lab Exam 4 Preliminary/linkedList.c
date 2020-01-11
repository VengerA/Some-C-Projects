#include "linkedList.h"

struct Node {
    int data;
    struct Node *next;
};
typedef struct Node Node;


/* Functions will be implemented here */

void printList(Node *head){
    if(head->data != NULL){
        printf("%d -> ", head->data);
        return printList(*head->next);
    }
    printf("%d\n", head->data);
}

void insertEnd(Node** list, int data){
    Node *temp;
    Node *new = (Node) malloc(sizeof(Node));
    temp = *list;
    new->next = NULL;
    new->data = data;
    if(temp != NULL){
        while(temp->next->data != NULL){
        temp = temp->next;
        }
        temp->next = new;
    }
    else{
        *list = new;
    }
}

int occurrences(Node *head, int value){
    int occurence = 0;
    while(head->data != NULL){
        if (head->data == value){
            occurence++;
            head = head->next;
        }
        else{
            head = head ->next;
        }
    }
    return occurence;
}

Node* removeNode(Node *head, int index){
    Node *temp = head;
    Node *temp2;
    int sira;
    if (index == 0){
        head = head->next;
        free(temp);
    }
    else{
        for(sira = 0; sira< index - 1; sira++){
            temp = temp->next;
        }
        temp2 = temp->next
        temp->next = temp2->next;
        free(temp2);
    }
    return head;
}

Node* mergeLists(Node *list1, Node *list2){
    Node *temp;
    temp = list1;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = list2;
    return insertionSort(list1);
}

Node* reverse(Node *head){
    Node *temp, *temp2;
    int len, i;

    temp = head;
    temp2 = temp;
    len = 0;

    while(temp){
        temp = temp->next;
        len++;
    }
    temp = head;
    while(temp){
        i = 0;
        while(i<len-1){
            temp2 = temp2->next;
        }
    }
    return NULL;
}

int isPalindrome(Node *head){
    Node *temp, *temp2;

    int len = 0;
    int i;

    temp = head;
    
    while(temp){
        temp = temp->next;
        len++;
    }
    temp = head;

    while(len > 1){
        i = 0;
        temp2 = temp;

        while(i<len-1){
            temp2 = temp2->next;
            i++;
        }
        if (temp->data == temp2->data){
            temp = temp->next;
            continue;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

Node* insert(Node *list1, Node *list2, int index){
    Node *temp;
    Node *temp2;
    int i;
    
    temp = list1;
    while(i<index){
        temp = temp->next;
        i++;
    }
    temp2 = temp->next;
    temp->next = list2;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = temp2;
    return temp;
}

Node* changeVar(Node *list, int index){
    Node *temp, *temp2, *temp3;
    int i; 

    temp = list;
    for( i = 0; i< index - 1; i++){
        temp = temp->next;
    }
    temp2 = temp->next;
    te

}

Node* insertionSort(Node *head){
    Node *temp, *temp2;
    int len, i, j;
    

    len = 0;
    temp = head;
    while(temp){
        len++;
        temp = temp->next;
    }

    temp = head;

    for(i = 0; i<len; i++){
        for(j = 0; j<len; j++){
            if (temp->data <=temp2->next->data){
                temp2 = temp2->next;
                j++;
            }
            else{

            }
        }
        
    }


    return NULL;
}

