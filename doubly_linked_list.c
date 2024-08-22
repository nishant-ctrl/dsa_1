#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
void print_list_head(struct node *head)
{
    struct node *ii;
    printf("NULL ->");
    for(ii=head ; ii!=NULL ; ii=ii->next)
    {
        printf("%d -> " ,ii->data);
    }
    printf("NULL");
}
void print_list_tail(struct node *tail)
{
    struct node *ii;
    printf("NULL ->");
    for(ii=tail ; ii!=NULL ; ii=ii->prev)
    {
        printf("%d -> " ,ii->data);
    }
    printf("NULL");
}
int main()
{
    struct node *head=NULL,*tail=NULL,*newnode;
    int n;
    printf("Enter the size of list: ");
    scanf("%d" ,&n);
    for(int i=0 ; i<n ; i++)
    {
        newnode=malloc(sizeof(struct node));
        newnode->next=NULL;
        newnode->prev=NULL;
        printf("Enter key value: ");
        scanf("%d" ,&newnode->data);
        if(newnode==NULL)
        {
            printf("Storage not allocated.");
            break;
        }
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
    }
    printf("PRINTING THE LIST\n");
    print_list_head(head);
    printf("\n");
    print_list_tail(tail);
    return 0;
}