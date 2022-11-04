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

int getSize(struct node*h){
    int count = 0;
    while(h != NULL){
        count++;
        h = h->next;
    }
    return count;
}

struct node*rightRotate(int n,struct node*head){
    if(getSize(head) == n || n == 0){
        return head;
    }

    int size = getSize(head);

    struct node*temp = head;
    struct node*prev = NULL;
    struct node*newhead = head;

    for(int i=0;i<(size-n);i++){
        prev = temp;
        temp = temp -> next;
    }

    while(newhead->next != NULL){
        newhead = newhead->next;
    }

    newhead->next = head;
    prev->next = NULL;

    return temp;
}


struct node*leftRotate(int n,struct node*head){
    if(getSize(head) == n || n == 0){
        return head;
    }

    struct node*temp = head;
    struct node*prev = NULL;
    struct node*t = head;

    for(int i=0;i<n;i++){
        prev = temp;
        temp = temp->next;
    }

    while(t->next != NULL){
        t = t->next;
    }

    prev->next = NULL;
    t->next = head;

    return temp;
}


int main(){

    int n;

    printf("enter size of list: ");
    scanf("%d",&n);

    int val;

    for(int i = 0; i<n; i++){
        printf("enter the node %d: ",i+1);
        scanf("%d",&val);
        addNode1(val);
    }

    struct node*copy = NULL;
    struct node*tcopy = NULL;

    struct node*temp = head1;
    while(temp != NULL){
        if(!copy){
            copy = (struct node*)malloc(sizeof(struct node));
            copy->val = temp->val;
            tcopy = copy;
            copy->next = NULL;
        } else {
            tcopy->next = (struct node*)malloc(sizeof(struct node));
            tcopy->next->val = temp->val;
            tcopy = tcopy->next;
            tcopy->next = NULL;
        }
        temp = temp->next;
    }

    printf("original list: ");
    printList(head1);

    printf("copied list: ");
    printList(copy);

    printf("left rotate: ");
    struct node*res2 = leftRotate(2,copy);
    printList(res2);

    printf("right rotate: ");
    struct node*res1 = rightRotate(2,head1);
    printList(res1);
}
