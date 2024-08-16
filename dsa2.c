#include<stdio.h>
void remove_newline_character(char name[])
{
    for(int i=0 ; name[i]!='\0' ; i++)
    {
        if(name[i]=='\n')
        {
            name[i]=name[i+1];
            break;
        }
    }
}
int main()
{
    int n;
    char name[100][100];
    int roll[100];
    int search;
    printf("Enter how many details of students you want to enter: ");
    scanf("%d" ,&n);
    for(int i=0 ; i<n ; i++)
    {
        getchar();
        printf("Enter the name of student %d: " ,i+1);
        fgets(name[i] , 100 , stdin);
        remove_newline_character(name[i]);
        printf("Enter the roll number of student %d: " ,i+1);
        scanf("%d" ,&roll[i]);
    }
    printf("Enter the roll number of student to search: ");
    scanf("%d" ,&search);
    for(int i=0 ; i<n ; i++)
    {
        if(roll[i]==search)
        {
            printf("Name of the student: %s and Roll-%d" ,name[i] ,roll[i]);
            return 0;
        }
    }
    printf("Student not found in the database.");
    return 0;
}