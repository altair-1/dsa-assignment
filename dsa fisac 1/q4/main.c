#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char name[50];
    int roll_no;
    int marks;
    struct node*next;
};

struct node*head = NULL;
struct node*tail = NULL;

void addNode(char name[],int rn,int marks){
    if(!head){
        head = (struct node*)malloc(sizeof(struct node));
        tail = head;
        strcpy(head->name,name);
        head->roll_no = rn;
        head->marks = marks;
        tail->next = NULL;
    } else {
        tail->next = (struct node*)malloc(sizeof(struct node));
        tail = tail->next;
        strcpy(tail->name,name);
        tail->roll_no = rn;
        tail->marks = marks;
        tail->next = NULL;
    }
}


void sortList(struct node*head){
    struct node*i;
    struct node*j;

    for(i = head; i != NULL; i = i->next){
        for(j = i->next; j != NULL; j = j->next){
            if(j->marks > i->marks){
                struct node temp;

                strcpy(temp.name,i->name);
                temp.roll_no = i->roll_no;
                temp.marks = i->marks;

                strcpy(i->name,j->name);
                i->roll_no = j->roll_no;
                i->marks = j->marks;

                strcpy(j->name,temp.name);
                j->roll_no = temp.roll_no;
                j->marks = temp.marks;
            }
        }
    }
}


void printList(struct node*temp){
    while(temp != NULL){
        printf("%s ",temp->name);
        printf("%d ",temp->roll_no);
        printf("%d ",temp->marks);
        temp = temp->next;
    }
    printf("\n");
}

int main(){

    addNode("Arun",12,45);
    addNode("Ram",6,89);
    addNode("Raju",1,60);
    printList(head);

    printf("Sorted list based on marks: \n");
    sortList(head);
    printList(head);

    printf("Second highest: \n");
    printf("%s %d %d",head->next->name,head->next->roll_no,head->next->marks);

}
