#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;
struct Node{
    int data;
    node* next;
};

void printList(node* head);
void push(node** head_ref,int data);
void insertionSort(node** head_ref);
void insertIntoSorted(node** sorted_ref,node* new_node);

/* Driver program that applies insertion sort to singly linked lists */
int main(int argc, char* argv[]){
    int i, sizeOfList;
    sizeOfList=argc-1;
    node *head;
    head=NULL;
 
    for(i=sizeOfList;i>0;i--){
       push(&head,atoi(argv[i]));
    }

    /* Print the linked list before the insertion sort */
    printf("Your list before the insertion sort is: ");
    printList(head);

    /* insertion sort function */
    insertionSort(&head);

    /* Print the linked list after the insertion sort */
    printf("Your list after the sort is: ");
    printList(head);

    return EXIT_SUCCESS;
}


/* Utility function that inserts a new node at the beginning of a linked list */
void push(node** head_ref,int data){
    //allocate node and fill
    node* new_node;
    new_node=(node*)malloc(sizeof(node));
    new_node->data=data;    

    //link
    new_node->next=*head_ref;
    *head_ref=new_node;
}


/* Utility function to print a linked list */
void printList(node* head){
    node* temp;
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}


/* Function to sort a singly linked list using insertion sort */
void insertionSort(node** head_ref){

    /* Initialize the sorted linked list */
    node* sorted;
    sorted=NULL;

    /* Traverse the given linked list and insert every node to "sorted" */
    node* current;
    current=*head_ref;
    while(current!=NULL){
        /* Store "next" for next iteration */ 
        node* next;
        next=current->next;

        /*Insert "current" into the "sorted" linked list */
        insertIntoSorted(&sorted, current);

        /* Update "current" to the next node */
        current=next;
    }
    *head_ref=sorted;
}


/* Function to insert a given node in the "sorted" linked list. Where
 * the insertion sort actually occurs.
 */ 
void insertIntoSorted(node** sorted_ref,node* new_node){
    node* current; 
    /* Special case for the head end of the "sorted" */
    if ((*sorted_ref == NULL) || ((*sorted_ref)->data >= new_node->data)) 
    { 
        new_node->next = *sorted_ref; 
        *sorted_ref = new_node; 
    }
    /* Locate the node before the point of insertion */
    else
    {
        current = *sorted_ref; 
        while ((current->next!=NULL) && (current->next->data < new_node->data)){ 
            current = current->next; 
        } 
        new_node->next = current->next; 
        current->next = new_node; 
    } 
}