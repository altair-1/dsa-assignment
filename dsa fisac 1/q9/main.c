#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "delete_functions.h"
int isVowel(char ch)
{
    if(ch=='a' || ch=='A' || ch=='e' || ch=='E' || ch=='i' || ch=='I' || ch=='o' || ch=='O' || ch=='u' || ch=='U')
        return 1;

    else
        return 0;
}
struct node* create(char name[])
{
    int i;
    struct node* list=NULL;

    for(i=0;i<strlen(name);i++)
    {
        char item=name[i];

        struct node* ptr = (struct node*)malloc(sizeof(struct node));
        ptr->data=item;
        ptr->next=NULL;

        struct node* p = list;
        if(p==NULL)
            list=ptr;
        else
        {
            while(p->next!=NULL)
            {
                p=p->next;
            }

            p->next=ptr;
        }

    }

    return list;
}
void display(struct node *ptr)
{
    while (ptr!=NULL)
    {
        printf("%c ",ptr->data);
        ptr = ptr->next;
    }
}
void allVowels(struct node* head)
{
    struct node* p = head;
    struct node* q = (struct node*)malloc(sizeof(struct node));
    struct node* list = head;


    while(p!=NULL)
    {
        char ch=p->data;

        if(isVowel(ch))
        {
            q->next=p->next;
        }
        q=p;
        p=p->next;
    }

    printf("\nList after editing : ");
    display(list);
}
void main()
{
    char name[50];
    int i;

    printf("Enter a name : ");
    gets(name);

    struct node* list=NULL;
    list=create(name);

    printf("Character list is : ");
    display(list);

    allVowels(list);
}
