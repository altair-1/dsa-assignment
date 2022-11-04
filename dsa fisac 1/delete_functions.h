#include<stdio.h>
#include<stdlib.h>
struct node
{
    char data;
    struct node* next;
};
struct node* deleteFirst(struct node* head)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr=head;
    head=ptr->next;
    free(ptr);
    return head;
}
struct node* deleteEnd(struct node* head)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = (struct node*)malloc(sizeof(struct node));
    ptr=head;

    while(ptr->next!=NULL)
    {
        p=ptr;
        ptr=ptr->next;
    }
    free(ptr);
    p->next=NULL;
    return head;
}
struct node* deleteBetween(struct node* head, int index)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node* p = (struct node*)malloc(sizeof(struct node));
    ptr=head;

    int i;
    for(i=0;i<index;i++)
    {
        p=ptr;
        ptr=ptr->next;
    }

    p->next=ptr->next;
    free(ptr);
    return head;
}
