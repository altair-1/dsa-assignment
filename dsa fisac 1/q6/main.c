#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct node{
    int val;
    struct node*next;
};

struct node*head1 = NULL;
struct node*tail1 = NULL;

void addNode1(int val){
    if(!head1){
        head1 = (struct node *)malloc(sizeof(struct node));
        tail1 = head1;
        head1->val = val;
        head1->next = NULL;
    } else {
        tail1->next = (struct node*)malloc(sizeof(struct node));
        tail1 = tail1->next;
        tail1->val = val;
        tail1->next = NULL;
    }
}

void printList(struct node*temp){
    while(temp != NULL){
        printf("%d ",temp->val);
        temp = temp->next;
    }
    printf("\n");
}


int main(){

    addNode1(1);
    addNode1(2);
    addNode1(3);
    addNode1(4);
    addNode1(5);
    addNode1(6);

    printf("Sample nodes of the original list: \n");
    printList(head1);

    struct node*temp = head1;
    // printf("%d hi",temp->val);
    struct node*eve = NULL;
    struct node*odd = NULL;
    struct node*etail = NULL;
    struct node*otail = NULL;

    while(temp){

        if(temp->val % 2 == 0){
            if(!eve){
                eve = (struct node *)malloc(sizeof(struct node));
                etail = eve;
                eve->val = temp->val * temp->val * temp->val;
                etail->next = NULL;
            } else {
                etail->next = (struct node *)malloc(sizeof(struct node));
                etail = etail->next;
                etail->val = temp->val * temp->val * temp->val;
                etail->next = NULL;
            }
        } else {
            if(!odd){
                odd = (struct node *)malloc(sizeof(struct node));
                otail = odd;
                odd->val =  temp->val * temp->val * temp->val;
                otail->next = NULL;
            } else {
                otail->next = (struct node *)malloc(sizeof(struct node));
                otail = otail->next;
                otail->val =  temp->val * temp->val * temp->val;
                otail->next = NULL;
            }
        }

        temp = temp->next;
    }

    printf("Displaying the elements of LIST-1 followed by LIST-2:\nLIST1: ");
    printList(eve);

    printf("LIST2: ");
    printList(odd);

}
