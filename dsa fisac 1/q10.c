#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char data[50];
    int count;
    struct node* next;
};

struct node* create(struct node* head,char name[])
{
    
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    strcpy(ptr->data,name);
    ptr->next=NULL;

    struct node* p = head;

    if(p==NULL){
        return ptr;
    }
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

void search(struct node* head)
{
    struct node* p = head;
    struct node *q, *temp;
    int count;

    while(p != NULL){  
        temp = p;  
        q = p->next;  
        count=1;
        while(q != NULL) {  
            if(!strcmp(p->data, q->data)) { 
                temp->next = q->next;
                count++;
            }  
            else {  
                temp = q;
            }  
            q = q->next;  
        }  
        printf("\n%s %d ", p->data, count);
        p = p->next;  
    }  
}

void display(struct node *ptr)
{
    while (ptr!=NULL)
    {
        printf("%s ",ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    char name[50];
    int i,n;

    printf("enter number of names: ");
    scanf("%d",&n);

    struct node* list=NULL;

    printf("enter the names: \n");

    for(i=0;i<n;i++)
    {
        scanf("%s",&name);
        list=create(list,name);

    }

    printf("list of first names: ");
    display(list);
    search(list);
    printf("\nmodified list: ");
    display(list);
    
    return 0;
}
