#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *insert(struct node * head)
{
    int position;
    if(head==NULL)
    {
        printf("List is empty.");
        return head;
    }
    printf("\nEnter the position at which you to insert newnnode: ");
    scanf("%d" ,&position);
    if(position<1)
    {
        printf("\nInvalid position.\n");
        return head;
    }
    struct node *ii,*newnode=NULL;
    newnode=malloc(sizeof(struct node));
    printf("Enter the key value: ");
    scanf("%d" ,&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    if(position==1)
    {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        return head;
    }
    int count=0;
    for(ii=head ; ii!=NULL ; ii=ii->next)
    {
        count++;
        if(count==position-1)
        {
            newnode->next=ii->next;
            ii->next=newnode;
            newnode->prev=ii;
            if(newnode->next!=NULL)
            {
                newnode->next->prev=newnode;
            }
            return head;
        }
    }
    printf("Invalid Position.");
    return head;
}
void print_list_head(struct node *head)
{
    struct node *ii;
    printf("NULL <->");
    for(ii=head ; ii!=NULL ; ii=ii->next)
    {
        printf("%d <-> " ,ii->data);
    }
    printf("NULL");
}
void print_list_tail(struct node *tail)
{
    struct node *ii;
    printf("NULL <->");
    for(ii=tail ; ii!=NULL ; ii=ii->prev)
    {
        printf("%d <-> " ,ii->data);
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
    head=insert(head);
    printf("PRINTING THE LIST\n");
    print_list_head(head);
    printf("\n");
    //print_list_tail(tail);
    return 0;
}