#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char data[50];
    struct node* next;
};

struct node* insert(struct node* head, char str[])
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    strcpy((ptr->data),str);
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

void display(struct node *ptr)
{
    while (ptr!=NULL)
    {
        printf("%s ",ptr->data);
        ptr = ptr->next;
    }
}

int isPalin(char str[])
{
    int i,j,flag=1;
    for(i=0,j=strlen(str)-1;i<=j;i++,j--)
    {
        if(str[i]!=str[j])
        {
            flag=0;
            break;
        }
    }
    return flag;
}

void main()
{
    int n,i;
    char s[50],temp[50];

    printf("enter size of list: ");
    scanf("%d",&n);

    struct node* list=NULL;

    printf("enter strings: \n");
    for(i=0;i<n;i++)
    {
        scanf(" %s",&s);
        list=insert(list,s);
    }

    printf("original list: ");
    display(list);
    printf("\n");

    struct node* PSLIST=NULL;
    struct node* NPSLIST=NULL;

    for(i=0;i<n;i++)
    {
        strcpy(temp,list->data);
        if(isPalin(temp))
        {
            PSLIST=insert(PSLIST,temp);
        }
        else
        {
            NPSLIST=insert(NPSLIST,temp);
        }
        list=list->next;
    }

    printf("1. palindrome strings: ");
    display(PSLIST);

    printf("\n2. remaining strings: ");
    display(NPSLIST);
}
