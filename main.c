#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char* string;
    struct node* next;
} node;

node* createNode(char* string)
{
 node* newNode = (node*)malloc(sizeof(node));
 newNode->string = (char*)malloc(256);
 strcpy(newNode->string, string);
 return newNode;
}

node* addFirst(char* string, node* head)
{
 node* newHead = createNode(string);
 newHead->next = head;
 return newHead;
}

node* addAt(int index, char* string, node* head)
{
 if(index==0)
 return addFirst(string, head);
 int counter = 0;
 node* temp = head;
 node* beforeTemp = NULL;
 while(temp != NULL)
 {
 if(index == counter)
 {
 node* newNode = createNode(string);
 newNode->next = temp;
 beforeTemp->next = newNode;
 return head;
 }
 beforeTemp = temp;
 temp = temp->next;
 ++counter;
 }
 if(index == counter)
 {
 node* newNode = createNode(string);
 newNode->next = temp;
 beforeTemp->next = newNode;
 }
 return head;
}

node* deleteList(node* head)
{
 struct node* temp = head;
 while(temp != NULL)
 {
node* toDelete = temp;
 temp = temp->next;
 free(toDelete->string);
 free(toDelete);
 }
 return NULL;
};


void printList(node* head) {
    while (head != NULL) {
        printf("%s", head->string);
        if(head->next != NULL)
            printf("-");
        head = head->next;
    }
    printf("\n");
}


node* moveHead(node* head, int index)
{
    if (head == NULL)
    {
        return NULL;
    }
    node* current = head;
    int count = 0;
    while(current->next != NULL)
    {
        if (count == index)
        {
            break;
        }
        current = current->next;
        count++;
    }
    node* newHead = head->next;
    head->next = current->next;
    current->next = head;

    return newHead;
}

int size(struct node* head)
{
int size = 0;
struct node* temp = head;
while(temp != NULL)
{
++size;
temp = temp->next;
}
return size;
}


 node* addLast(char* string, node* head)
{
 if(head == NULL)
 {
node* newNode = (struct node*)malloc(sizeof(struct node));
  newNode->string = (char*)malloc(256);
 strcpy(newNode->string, string);
 newNode->next = NULL;
 return newNode;

 }
 else
 {
 head->next = addLast(string, head->next);
 }
 return head;
}

node* removeFirst(struct node* head)
{
 if(head == NULL)
 return head;

 struct node* newHead = head->next;
free(head->string);
 free(head); //free memory of first node
 return newHead;
}
node* removeAt(node* head, int index)
{
    if(index==0)
        return removeFirst(head);
    int counter = 0;
    node* temp = head;
    node* beforeTemp = NULL;
    while(temp != NULL)
    {
        if(index == counter)
        {
            beforeTemp->next = temp->next;
            free(temp);
            return head;
        }
        beforeTemp = temp;
        temp = temp->next;
        ++counter;

    }
    return head;
}



int main ()
{
node* head = NULL;
char input[99];
int index;
int deletedNodes = 0;
while(1)
{
printf("\nwort eingeben: ");
scanf("%s", input);
if(input [0] == '=') {
break; }
        head = addLast(input, head);
        printList(head);

   }
   while (1) {
    printf("\nEnter index and word to insert:");
    scanf("%d", &index);
    scanf("%s", input);
    if(input [0] == '=') {
                break; }
    head = addAt(index, input, head);
    printList(head);
    deletedNodes++;
   }
    printf("\nAdded Nodes: %d", deletedNodes);
     printf("Size of list: %d\n", size(head));
    deleteList(head);
    return 0;
}
