#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* insertFirst(struct node* head, int item)
{

}
struct node* insertEnd(struct node* head, int item)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data=item;
    ptr->next=NULL;

    struct node* p = head;

    if(p==NULL)
        return ptr;
    else
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }

        p->next=ptr;
    }
    return head;
}
struct node* insertBetween(struct node* head, int item)
{

}
void display(struct node *ptr)
{
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}