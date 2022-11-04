#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "insert_functions.h"

void main()
{
    int n,i,item;

    struct node* list;

    int choice;
    printf("1. Create a singly linked list of N numbers and display\n");
    printf("2. Delete every occurrence of the numbers in the linked list which are equal to the square of the given key value\n");
    printf("3. Display the updated list after the deletion of elements\n");
    printf("4. Exit\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        if(choice==1)
        {
            printf("Enter number of nodes to create: ");
            scanf("%d",&n);

            list = (struct node*)calloc(n,sizeof(struct node));
            list=NULL;

            for(i=0;i<n;i++)
            {
                printf("Enter data of node %d: ",i+1);
                scanf("%d",&item);
                list=insertEnd(list,item);
            }

            printf("\nData in list before deletion: \n");
            display(list);
            printf("\n");
        }
        
        else if(choice==2)
        {
            struct node* p = list;
            struct node* q;

            printf("Enter element value of key to be considered for deletion: ");
            scanf("%d",&item);
            item*=item;

            for(i=0;i<n;i++)
            {
                if((p->data)==item)
                {
                    if(p==list)
                    {
                        p=p->next;
                        list=p;
                    }
                    else if(p->next==NULL)
                    {
                        q->next=NULL;
                    }
                    else
                    {
                        q->next=p->next;
                        p=p->next;
                    }
                }
                else
                {
                    q=p;
                    p=p->next;
                }
            }
        }
        
        else if(choice==3)
        {
            printf("Data in the final list after deletion: ");
            display(list);
        }
    } while(choice!=4);
}