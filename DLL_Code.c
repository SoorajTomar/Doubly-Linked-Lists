#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node *next,*prev;
};
typedef struct node sn;
sn *head=NULL;
sn* insertb(sn* h,int val){
    sn *nn=(sn*)malloc(sizeof(sn));
    nn->data=val;
    if(h==NULL)
    {nn->next=NULL;
        nn->prev=NULL;
        h=nn;
    }
    else
    {nn->next=h;
    h->prev=nn;
    nn->prev=NULL;
    h=nn;}
    return h;
}
sn* inserte(sn* h,int val){
    sn *nn=(sn*)malloc(sizeof(sn));
    nn->data=val;
    nn->next=NULL;
    sn *p=h;
    while(p->next!=NULL)p=p->next;
    p->next=nn;
    nn->prev=p;
    return h;
}
sn* delb(sn* h){
    sn* x=h;
    h->next->prev=NULL;
    h=h->next;
    free(x);
    return h;
}
sn* dele(sn* h){
    sn* p=h;
    while(p->next!=NULL)p=p->next;
    sn* x=p;
    x->prev->next=NULL;
    free(x);
    return h;
}
void print(sn* h){
    sn* p=h;
    while(p){
        printf("%d->",p->data);
        p=p->next;
    }
}
int main()
{
    int i;
    for(i=0;i<5;i++)
    head=insertb(head,i);
    print(head);
    printf("\n");
    head=inserte(head,97);
    print(head);
    printf("\n");
    head=delb(head);
    print(head);
    printf("\n");
    head=dele(head);
    print(head);
    printf("\n");
    return 0;
}
