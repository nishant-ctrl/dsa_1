#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
void delete(struct node **head , struct node **tail)
{
    int position;
    struct node *temp=NULL,*ii;
    if(*head==NULL)
    {
        printf("List is empty.");
        return;
    }
    printf("\nEnter the position at which you to delete node: ");
    scanf("%d" ,&position);
    if(position<1)
    {
        printf("\nInvalid position.\n");
        return ;
    }
    if(position==1)
    {
        temp=(*head);
        (*head)=(*head)->next;
        (*head)->prev=NULL;
        free(temp);
        return;
    }
    int count=0;
    int total=0;
    for(ii=*head ; ii!=NULL ; ii=ii->next)
    {
        total++;
    }
    if(position==total)
    {
        temp=(*tail);
        (*tail)=(*tail)->prev;
        (*tail)->next=NULL;
        free(temp);
    }
    for(ii=*head ; ii->next!=NULL ; ii=ii->next)
    {
        count++;
        if(count==position-1)
        {
            temp=ii->next;
            ii->next=ii->next->next;
            ii->next->prev=ii;
            free(temp);
        }
    }
    printf("Invalid Position.");
    return;
}
void insert(struct node **head , struct node **tail)
{
    int position;
    if(*head==NULL)
    {
        printf("List is empty.");
        return;
    }
    printf("\nEnter the position at which you to insert newnnode: ");
    scanf("%d" ,&position);
    if(position<1)
    {
        printf("\nInvalid position.\n");
        return ;
    }
    struct node *ii,*newnode=NULL;
    newnode=malloc(sizeof(struct node));
    printf("Enter the key value: ");
    scanf("%d" ,&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    if(position==1)
    {
        newnode->next=(*head);
        (*head)->prev=newnode;
        (*head)=newnode;
        return;
    }
    int count=0;
    int total=0;
    for(ii=*head ; ii!=NULL ; ii=ii->next)
    {
        total++;
    }
    // printf("\n%d\n" ,total);
    for(ii=*head ; ii!=NULL ; ii=ii->next)
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
            if(total==position-1)
            {
                (*tail)=newnode;
            }
            return;
        }
    }
    printf("Invalid Position.");
    return;
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
    int choice;
    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Print List from Head\n4.Print list from tail\n5.EXIT\n    Enter your choice: ");
        scanf("%d" ,&choice);
        switch(choice)
        {
            case 1: insert(&head , &tail);
                     break;
            case 2: delete(&head , &tail);
                    break;
            case 3: print_list_head(head);
                    break;
            case 4: print_list_tail(tail);
                    break;
            case 5: printf("Exiting The Program\n"); 
                    return 0;
            default: printf("INVALID CHOICE");
                    break;
        }
    }
    // printf("PRINTING THE LIST\n");
    // print_list_head(head);
    // printf("\n");
    // print_list_tail(tail);
    // insert(&head,&tail);
    // printf("PRINTING THE LIST\n");
    // print_list_head(head);
    // printf("\n");
    // print_list_tail(tail);
    // delete(&head , &tail);
    // printf("PRINTING THE LIST\n");
    // print_list_head(head);
    // printf("\n");
    // print_list_tail(tail);
    return 0;
}