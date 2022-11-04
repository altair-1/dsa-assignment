#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
   int data;
   int key;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;
struct node *l1 = NULL;
struct node *l2 = NULL;

//display the list
void printList() {
   struct node *ptr = head;
   printf("\n[ ");

   //start from the beginning
   while(ptr != NULL) {
      printf("(%d) ",ptr->data);
      ptr = ptr->next;
   }

   printf("]");
}

//insert link at the first location
void insertFirst(int key, int data) {
   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));

   link->key = key;
   link->data = data;

   //point it to old first node
   link->next = head;

   //point first to new first node
   head = link;
}

void reverse(struct node** head_ref) {
   struct node* prev   = NULL;
   struct node* current = *head_ref;
   struct node* next;

   while (current != NULL) {
      next  = current->next;
      current->next = prev;
      prev = current;
      current = next;
   }

   *head_ref = prev;
}

bool isEmpty() {
   return head == NULL;
}

void main() {

   printf("List : ");
   insertFirst(1,8);
   insertFirst(2,4);
   insertFirst(3,6);
   insertFirst(4,2);
   insertFirst(5,1);
   printList();
   printf("\n");

   struct node *start1 = head;
   struct node *start2 = head->next;
   int key1=1,key2=1;
	while(start1!=NULL)
    {
        struct node *f1 = (struct node *)malloc(sizeof(struct node));
        f1->key = key1;
        key1++;
        f1->data=start1->data;
        f1->next=l1;
        l1=f1;
        if(start1->next==NULL)
        {
            break;
        }
        start1=start1->next->next;
    }
    while(start2!=NULL)
    {
        struct node *f2 = (struct node *)malloc(sizeof(struct node));
        f2->key = key2;
        key2++;
        f2->data=start2->data;
        f2->next=l2;
        l2=f2;
        if(start2->next==NULL)
        {
            break;
        }
        start2=start2->next->next;
    }
    reverse(&l1);
    reverse(&l2);
    printf("List 1:\n");
   while(l1!=NULL)
   {
       printf("%d->",l1->data);
       l1=l1->next;
   }
   printf("null\n");
   printf("List 2:\n");
   while(l2!=NULL)
   {
       printf("%d->",l2->data);
       l2=l2->next;
   }
   printf("null\n");
}
