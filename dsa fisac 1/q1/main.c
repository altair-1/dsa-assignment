#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct node{
    int val;
    struct node*next;
};

struct node*head1 = NULL;
struct node*tail1 = NULL;
struct node*head2 = NULL;
struct node*tail2 = NULL;

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

void addNode2(int val){
    if(!head2){
        head2 = (struct node *)malloc(sizeof(struct node));
        tail2 = head2;
        head2->val = val;
        head2->next = NULL;
    } else {
        tail2->next = (struct node*)malloc(sizeof(struct node));
        tail2 = tail2->next;
        tail2->val = val;
        tail2->next = NULL;
    }
}

void printList(struct node*temp){
    while(temp != NULL){
        printf("%d ",temp->val);
        temp = temp->next;
    }
    printf("\n");
}

struct node* merge(struct node*h1,struct node*h2){
    if(!h1){
        return h2;
    }

    if(!h2){
        return h1;
    }

    struct node*h = NULL;
    struct node*t = NULL;

    if(h1->val < h2->val){
        h = h1;
        h1 = h1->next;
        t = h;
    } else {
        h = h2;
        h2 = h2->next;
        t = h;
    }

    while(h1!=NULL && h2!=NULL){
        if(h1->val < h2->val){
            t->next = h1;
            t = t->next;
            h1 = h1->next;
        } else {
            t->next = h2;
            t = t->next;
            h2 = h2->next;
        }
    }

    while(h1 != NULL){
        t->next = h1;
        t = h1;
        h1 = h1->next;
    }

    while(h2 != NULL){
        t->next = h2;
        t = h2;
        h2 = h2->next;
    }

    return h;
}

int main(){

    printf("LIST 1: ");
    addNode1(2);
    addNode1(4);
    addNode1(6);
    addNode1(8);

    printList(head1);

    printf("LIST 2: ");
    addNode2(3);
    addNode2(5);
    addNode2(7);
    addNode2(9);

    printList(head2);

    struct node* res = merge(head1,head2);

    printf("After merging:\nLIST 1: ");
    printList(res);
}
