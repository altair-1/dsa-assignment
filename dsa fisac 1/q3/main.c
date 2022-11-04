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

struct node*fib(int n){
    head1 = (struct node*)malloc(sizeof(struct node));
    head1->val = 0;

    struct node*t = head1;
    struct node*prev = NULL;

    if(n == 1){
        return head1;
    }

    prev = t;
    t->next = (struct node*)malloc(sizeof(struct node));
    t = t->next;
    t->val = 1;

    if(n == 2){
        return head1;
    }

    for(int i = 0 ; i<(n-2); i++){
        t->next = (struct node*)malloc(sizeof(struct node));
        // t = t->next;
        t->next->val = t->val + prev->val;
        prev = t;
        t = t->next;
    }

    return head1;
}

int main(){
   int n;
   printf("Enter n: ");
   scanf("%d",&n);
   struct node*res = fib(n);
   printf("Generated List:\n");
   printList(res);
}
